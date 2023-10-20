// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SPANNER_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SPANNER_CLIENT_H

#include "google/cloud/spanner/batch_dml_result.h"
#include "google/cloud/spanner/client_options.h"
#include "google/cloud/spanner/commit_options.h"
#include "google/cloud/spanner/commit_result.h"
#include "google/cloud/spanner/connection.h"
#include "google/cloud/spanner/connection_options.h"
#include "google/cloud/spanner/database.h"
#include "google/cloud/spanner/internal/defaults.h"
#include "google/cloud/spanner/keys.h"
#include "google/cloud/spanner/mutations.h"
#include "google/cloud/spanner/partition_options.h"
#include "google/cloud/spanner/query_options.h"
#include "google/cloud/spanner/query_partition.h"
#include "google/cloud/spanner/read_options.h"
#include "google/cloud/spanner/read_partition.h"
#include "google/cloud/spanner/results.h"
#include "google/cloud/spanner/retry_policy.h"
#include "google/cloud/spanner/session_pool_options.h"
#include "google/cloud/spanner/sql_statement.h"
#include "google/cloud/spanner/transaction.h"
#include "google/cloud/spanner/version.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/internal/non_constructible.h"
#include "google/cloud/options.h"
#include "google/cloud/status.h"
#include "google/cloud/status_or.h"
#include <google/spanner/v1/spanner.pb.h>
#include <grpcpp/grpcpp.h>
#include <functional>
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

namespace google {
namespace cloud {
namespace spanner {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

// clang-format off
/**
 * Performs database client operations on Spanner.
 *
 * Applications use this class to perform operations on
 * [Spanner Databases][spanner-doc-link].
 *
 * @par Performance
 *
 * `Client` objects are relatively cheap to create, copy, and move. However,
 * each `Client` object must be created with a `std::shared_ptr<Connection>`,
 * which itself is relatively expensive to create. Therefore, connection
 * instances should be shared when possible. See the `MakeConnection()` method
 * and the `Connection` interface for more details.
 *
 * @par Thread Safety
 *
 * Instances of this class created via copy-construction or copy-assignment
 * share the underlying pool of connections. Access to these copies via multiple
 * threads is guaranteed to work. Two threads operating on the same instance of
 * this class is not guaranteed to work.
 *
 * @par Error Handling
 *
 * This class uses `StatusOr<T>` to report errors. When an operation fails to
 * perform its work the returned `StatusOr<T>` contains the error details. If
 * the `ok()` member function in the `StatusOr<T>` returns `true` then it
 * contains the expected result. For more information, see the
 * [Error Handling Guide](#spanner-error-handling).
 *
 * @code
 * namespace spanner = ::google::cloud::spanner;
 *
 * auto db = spanner::Database("my_project", "my_instance", "my_db_id"));
 * auto conn = spanner::MakeConnection(db);
 * auto client = spanner::Client(conn);
 *
 * auto rows = client.Read(...);
 * using RowType = std::tuple<std::int64_t, std::string>;
 * for (auto const& row : spanner::StreamOf<RowType>(rows)) {
 *   // ...
 * }
 * @endcode
 *
 * @par Query Options
 *
 * Most operations that take an `SqlStatement` may also be modified with
 * query `Options`. These options can be set at various levels, with more
 * specific levels taking precedence over broader ones. For example,
 * `Options` that are passed directly to `Client::ExecuteQuery()` will
 * take precedence over the `Client`-level defaults (if any), which will
 * themselves take precedence over any environment variables. The following
 * table shows the environment variables that may optionally be set and the
 * query `Options` setting that they affect.
 *
 * Environment Variable                   | Options setting
 * -------------------------------------- | --------------------
 * `SPANNER_OPTIMIZER_VERSION`            | `QueryOptimizerVersionOption`
 * `SPANNER_OPTIMIZER_STATISTICS_PACKAGE` | `QueryOptimizerStatisticsPackageOption`
 *
 * @see https://cloud.google.com/spanner/docs/reference/rest/v1/QueryOptions
 * @see http://cloud/spanner/docs/query-optimizer/manage-query-optimizer
 *
 * [spanner-doc-link]:
 * https://cloud.google.com/spanner/docs/api-libraries-overview
 */
// clang-format on
class Client {
 public:
  /**
   * Constructs a `Client` object using the specified @p conn and @p opts.
   *
   * See `MakeConnection()` for how to create a connection to Spanner. To help
   * with unit testing, callers may create fake/mock `Connection` objects that
   * are injected into the `Client`.
   */
  explicit Client(std::shared_ptr<Connection> conn, Options opts = {})
      : conn_(std::move(conn)),
        opts_(internal::MergeOptions(std::move(opts), conn_->options())) {}

  /// No default construction.
  Client() = delete;

  ///@{
  /// @name Copy and move support
  Client(Client const&) = default;
  Client& operator=(Client const&) = default;
  Client(Client&&) = default;
  Client& operator=(Client&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(Client const& a, Client const& b) {
    return a.conn_ == b.conn_;
  }
  friend bool operator!=(Client const& a, Client const& b) { return !(a == b); }
  ///@}

  /**
   * Reads rows from the database using key lookups and scans, as a simple
   * key/value style alternative to `ExecuteQuery()`.
   *
   * Callers can optionally supply a `Transaction` or
   * `Transaction::SingleUseOptions` used to create a single-use transaction -
   * or neither, in which case a single-use transaction with default options
   * is used.
   *
   * @note No individual row in the `ReadResult` can exceed 100 MiB, and no
   *     column value can exceed 10 MiB.
   *
   * @par Example
   * @snippet samples.cc read-data
   *
   * @param table The name of the table in the database to be read.
   * @param keys Identifies the rows to be yielded. If `read_options.index_name`
   *     is set, names keys in that index; otherwise names keys in the primary
   *     index of `table`. It is not an error for `keys` to name rows that do
   *     not exist in the database; `Read` yields nothing for nonexistent rows.
   * @param columns The columns of `table` to be returned for each row matching
   *     this request.
   * @param opts `Options` used for this request.
   */
  RowStream Read(std::string table, KeySet keys,
                 std::vector<std::string> columns, Options opts = {});

  /**
   * @copydoc Read
   *
   * @param transaction_options Execute this read in a single-use transaction
   *     with these options.
   */
  RowStream Read(Transaction::SingleUseOptions transaction_options,
                 std::string table, KeySet keys,
                 std::vector<std::string> columns, Options opts = {});

  /**
   * @copydoc Read
   *
   * @param transaction Execute this read as part of an existing transaction.
   */
  RowStream Read(Transaction transaction, std::string table, KeySet keys,
                 std::vector<std::string> columns, Options opts = {});

  /**
   * Reads rows from a subset of rows in a database. Requires a prior call
   * to `PartitionRead` to obtain the partition information; see the
   * documentation of that method for full details.
   * @note No individual row in the `ReadResult` can exceed 100 MiB, and no
   *     column value can exceed 10 MiB.
   *
   * @par Example
   * @snippet samples.cc read-read-partition
   *
   * @param partition A `ReadPartition`, obtained by calling `PartitionRead`.
   * @param opts `Options` used for this request.
   */
  RowStream Read(ReadPartition const& partition, Options opts = {});

  /**
   * Creates a set of partitions that can be used to execute a read
   * operation in parallel.  Each of the returned partitions can be passed
   * to `Read` to specify a subset of the read result to read.
   *
   * There are no ordering guarantees on rows returned among the returned
   * partition, or even within each individual `Read` call issued with a given
   * partition.
   *
   * Partitions become invalid when the session used to create them is deleted,
   * is idle for too long, begins a new transaction, or becomes too old. When
   * any of these happen, it is not possible to resume the read, and the whole
   * operation must be restarted from the beginning.
   *
   * @par Example
   * @snippet samples.cc partition-read
   *
   * @param transaction The transaction to execute the operation in.
   *     **Must** be a read-only snapshot transaction.
   * @param table The name of the table in the database to be read.
   * @param keys Identifies the rows to be yielded. If `read_options.index_name`
   *     is set, names keys in that index; otherwise names keys in the primary
   *     index of `table`. It is not an error for `keys` to name rows that do
   *     not exist in the database; `Read` yields nothing for nonexistent rows.
   * @param columns The columns of `table` to be returned for each row matching
   *     this request.
   * @param opts `Options` used for this request.
   *
   * @return A `StatusOr` containing a vector of `ReadPartition` or error
   *     status on failure.
   */
  StatusOr<std::vector<ReadPartition>> PartitionRead(
      Transaction transaction, std::string table, KeySet keys,
      std::vector<std::string> columns, Options opts = {});

  /**
   * Executes a SQL query.
   *
   * Operations inside read-write transactions might return `ABORTED`. If this
   * occurs, the application should restart the transaction from the beginning.
   *
   * Callers can optionally supply a `Transaction` or
   * `Transaction::SingleUseOptions` used to create a single-use transaction -
   * or neither, in which case a single-use transaction with default options
   * is used.
   *
   * `SELECT * ...` queries are supported, but there's no guarantee about the
   * order, nor number, of returned columns. Therefore, the caller must look up
   * the wanted values in each row by column name. When the desired column
   * names are known in advance, it is better to list them explicitly in the
   * query's SELECT statement, so that unnecessary values are not
   * returned/ignored, and the column order is known. This enables more
   * efficient and simpler code.
   *
   * Can also execute a DML statement with a returning clause in a read/write
   * transaction.
   *
   * @note No individual row in the `RowStream` can exceed 100 MiB, and no
   *     column value can exceed 10 MiB.
   *
   * @par Example
   * Query with explicitly selected columns.
   * @snippet samples.cc spanner-query-data
   *
   * @par Example
   * Using `SELECT *`.
   * @snippet samples.cc spanner-query-data-select-star
   *
   * @par Example
   * Using a DML statement with `THEN RETURN`.
   * @snippet samples.cc spanner-update-dml-returning
   *
   * @param statement The SQL statement to execute.
   * @param opts (optional) The `Options` to use for this call. If given,
   *     these will take precedence over the options set at the client and
   *     environment levels.
   */
  RowStream ExecuteQuery(SqlStatement statement, Options opts = {});

  /**
   * @copydoc ExecuteQuery(SqlStatement, Options)
   *
   * @param transaction_options Execute this query in a single-use transaction
   *     with these options.
   */
  RowStream ExecuteQuery(Transaction::SingleUseOptions transaction_options,
                         SqlStatement statement, Options opts = {});

  /**
   * @copydoc ExecuteQuery(SqlStatement, Options)
   *
   * @param transaction Execute this query as part of an existing transaction.
   */
  RowStream ExecuteQuery(Transaction transaction, SqlStatement statement,
                         Options opts = {});

  /**
   * Executes a SQL query on a subset of rows in a database. Requires a prior
   * call to `PartitionQuery` to obtain the partition information; see the
   * documentation of that method for full details.
   *
   * @note No individual row in the `RowStream` can exceed 100 MiB, and no
   *     column value can exceed 10 MiB.
   *
   * @par Example
   * @snippet samples.cc execute-sql-query-partition
   *
   * @param partition A `QueryPartition`, obtained by calling `PartitionQuery`.
   * @param opts (optional) The `Options` to use for this call. If given,
   *     these will take precedence over the options set at the client and
   *     environment levels.
   */
  RowStream ExecuteQuery(QueryPartition const& partition, Options opts = {});

  /**
   * Profiles a SQL query.
   *
   * Profiling executes the query, provides the resulting rows, `ExecutionPlan`,
   * and execution statistics.
   *
   * Operations inside read-write transactions might return `kAborted`. If this
   * occurs, the application should restart the transaction from the beginning.
   *
   * Callers can optionally supply a `Transaction` or
   * `Transaction::SingleUseOptions` used to create a single-use transaction -
   * or neither, in which case a single-use transaction with default options
   * is used.
   *
   * @note Callers must consume all rows from the result before execution
   *     statistics and `ExecutionPlan` are available.
   *
   * @note No individual row in the `ProfileQueryResult` can exceed 100 MiB, and
   *     no column value can exceed 10 MiB.
   *
   * @par Example
   * @snippet samples.cc profile-query
   *
   * @param statement The SQL statement to execute.
   * @param opts (optional) The `Options` to use for this call. If given,
   *     these will take precedence over the options set at the client and
   *     environment levels.
   *
   */
  ProfileQueryResult ProfileQuery(SqlStatement statement, Options opts = {});

  /**
   * @copydoc ProfileQuery(SqlStatement, Options)
   *
   * @param transaction_options Execute this query in a single-use transaction
   *     with these options.
   */
  ProfileQueryResult ProfileQuery(
      Transaction::SingleUseOptions transaction_options, SqlStatement statement,
      Options opts = {});

  /**
   * @copydoc ProfileQuery(SqlStatement, Options)
   *
   * @param transaction Execute this query as part of an existing transaction.
   */
  ProfileQueryResult ProfileQuery(Transaction transaction,
                                  SqlStatement statement, Options opts = {});

  /**
   * Creates a set of partitions that can be used to execute a query
   * operation in parallel.  Each of the returned partitions can be passed
   * to `ExecuteQuery` to specify a subset of the query result to read.
   *
   * Partitions become invalid when the session used to create them is deleted,
   * is idle for too long, begins a new transaction, or becomes too old. When
   * any of these happen, it is not possible to resume the query, and the whole
   * operation must be restarted from the beginning.
   *
   * @par Example
   * @snippet samples.cc partition-query
   *
   * @param transaction The transaction to execute the operation in.
   *     **Must** be a read-only snapshot transaction.
   * @param statement The SQL statement to execute.
   * @param opts `Options` used for this request.
   *
   * @return A `StatusOr` containing a vector of `QueryPartition`s or error
   *     status on failure.
   */
  StatusOr<std::vector<QueryPartition>> PartitionQuery(
      Transaction transaction, SqlStatement statement,
      Options opts = Options{});

  /**
   * Executes a SQL DML statement.
   *
   * Operations inside read-write transactions might return `ABORTED`. If this
   * occurs, the application should restart the transaction from the beginning.
   *
   * @note Single-use transactions are not supported with DML statements.
   *
   * @par Example
   * @snippet samples.cc execute-dml
   *
   * @param transaction Execute this query as part of an existing transaction.
   * @param statement The SQL statement to execute.
   * @param opts (optional) The `Options` to use for this call. If given,
   *     these will take precedence over the options set at the client and
   *     environment levels.
   */
  StatusOr<DmlResult> ExecuteDml(Transaction transaction,
                                 SqlStatement statement, Options opts = {});

  /**
   * Profiles a SQL DML statement.
   *
   * Profiling executes the DML statement, provides the modified row count,
   * `ExecutionPlan`, and execution statistics.
   *
   * Operations inside read-write transactions might return `ABORTED`. If this
   * occurs, the application should restart the transaction from the beginning.
   *
   * @note Single-use transactions are not supported with DML statements.
   *
   * @par Example
   * @snippet samples.cc profile-dml
   *
   * @param transaction Execute this query as part of an existing transaction.
   * @param statement The SQL statement to execute.
   * @param opts (optional) The `Options` to use for this call. If given,
   *     these will take precedence over the options set at the client and
   *     environment levels.
   */
  StatusOr<ProfileDmlResult> ProfileDml(Transaction transaction,
                                        SqlStatement statement,
                                        Options opts = {});

  /**
   * Analyzes the execution plan of a SQL statement.
   *
   * Analyzing provides the `ExecutionPlan`, but does not execute the SQL
   * statement.
   *
   * Operations inside read-write transactions might return `ABORTED`. If this
   * occurs, the application should restart the transaction from the beginning.
   *
   * @note Single-use transactions are not supported with DML statements.
   *
   * @par Example
   * @snippet samples.cc analyze-query
   *
   * @param transaction Execute this query as part of an existing transaction.
   * @param statement The SQL statement to execute.
   * @param opts (optional) The `Options` to use for this call. If given,
   *     these will take precedence over the options set at the client and
   *     environment levels.
   */
  StatusOr<ExecutionPlan> AnalyzeSql(Transaction transaction,
                                     SqlStatement statement, Options opts = {});

  /**
   * Executes a batch of SQL DML statements. This method allows many statements
   * to be run with lower latency than submitting them sequentially with
   * `ExecuteDml`.
   *
   * Statements are executed in order, sequentially. Execution will stop at the
   * first failed statement; the remaining statements will not run.
   *
   * As with all read-write transactions, the results will not be visible
   * outside of the transaction until it is committed. For that reason, it is
   * advisable to run this method from a `Commit` mutator.
   *
   * @warning A returned status of OK from this function does not imply that
   *     all the statements were executed successfully. For that, you need to
   *     inspect the `BatchDmlResult::status` field.
   *
   * @par Example
   * @snippet samples.cc execute-batch-dml
   *
   * @param transaction The read-write transaction to execute the operation in.
   * @param statements The list of statements to execute in this batch.
   *     Statements are executed serially, such that the effects of statement i
   *     are visible to statement i+1. Each statement must be a DML statement.
   *     Execution will stop at the first failed statement; the remaining
   *     statements will not run. Must not be empty.
   * @param opts (optional) The options to use for this call.  Expected options
   *     are any of the types in the following option lists.
   *       - `google::cloud::RequestOptionList`
   */
  StatusOr<BatchDmlResult> ExecuteBatchDml(Transaction transaction,
                                           std::vector<SqlStatement> statements,
                                           Options opts = {});

  /**
   * Commits a read-write transaction.
   *
   * Calls the @p mutator in the context of a new read-write transaction.
   * The @p mutator can execute read/write operations using the transaction,
   * and returns any additional `Mutations` to commit.
   *
   * If the @p mutator succeeds and the transaction commits, then `Commit()`
   * returns the `CommitResult`.
   *
   * If the @p mutator returns a non-rerunnable status (according to the
   * @p rerun_policy), the transaction is rolled back and that status is
   * returned. Similarly, if the transaction fails to commit with a non-
   * rerunnable status, that status is returned.
   *
   * Otherwise the whole process repeats (subject to @p rerun_policy and
   * @p backoff_policy), by building a new transaction and re-running the
   * @p mutator.  The lock priority of the operation increases after each
   * rerun, meaning that the next attempt has a slightly better chance of
   * success.
   *
   * Note that the @p mutator should only return a rerunnable status when
   * the transaction is no longer usable (e.g., it was aborted). Otherwise
   * the transaction will be leaked.
   *
   * @par Example
   * @snippet samples.cc commit-with-policies
   *
   * @param mutator the function called to create mutations
   * @param rerun_policy controls for how long (or how many times) the mutator
   *     will be rerun after the transaction aborts.
   * @param backoff_policy controls how long `Commit` waits between reruns.
   * @param opts (optional) The options to use for this call.  Expected options
   *     include any of the following types:
   *       - `google::cloud::spanner::CommitReturnStatsOption`
   *       - `google::cloud::spanner::RequestPriorityOption`
   *       - `google::cloud::spanner::TransactionTagOption`
   *
   * @throw Rethrows any exception thrown by @p `mutator` (after rolling back
   *     the transaction). However, a `RuntimeStatusError` exception is
   *     instead consumed and converted into a `mutator` return value of the
   *     enclosed `Status`.
   */
  StatusOr<CommitResult> Commit(
      std::function<StatusOr<Mutations>(Transaction)> const& mutator,
      std::unique_ptr<TransactionRerunPolicy> rerun_policy,
      std::unique_ptr<BackoffPolicy> backoff_policy, Options opts = {});

  /**
   * Commits a read-write transaction.
   *
   * Same as above, but uses the default rerun and backoff policies.
   *
   * @par Example
   * @snippet samples.cc commit-with-mutator
   *
   * @param mutator the function called to create mutations
   * @param opts (optional) The options to use for this call.
   */
  StatusOr<CommitResult> Commit(
      std::function<StatusOr<Mutations>(Transaction)> const& mutator,
      Options opts = {});

  /**
   * Commits the @p mutations, using the @p options, atomically in order.
   *
   * @par Example
   * @snippet samples.cc commit-with-mutations
   *
   * This function uses the re-run loop described above with the default
   * policies.
   */
  StatusOr<CommitResult> Commit(Mutations mutations, Options opts = {});

  /**
   * Commits a read-write transaction.
   *
   * The commit might return a `kAborted` error. This can occur at any time.
   * Commonly the cause is conflicts with concurrent transactions, however
   * it can also happen for a variety of other reasons. If `Commit` returns
   * `kAborted`, the caller may try to reapply the mutations within a new
   * read-write transaction (which should share lock priority with the aborted
   * transaction so that the new attempt has a slightly better chance of
   * success).
   *
   * @warning It is an error to call `Commit` with a read-only transaction.
   *
   * @note Prefer the previous `Commit` overloads if you want to simply reapply
   *     mutations after a `kAborted` error.
   *
   * @param transaction The transaction to commit.
   * @param mutations The mutations to be executed when this transaction
   *     commits. All mutations are applied atomically, in the order they
   *     appear in this list.
   * @param opts (optional) The options to use for this call.
   *
   * @return A `StatusOr` containing the result of the commit or error status
   *     on failure.
   */
  StatusOr<CommitResult> Commit(Transaction transaction, Mutations mutations,
                                Options opts = {});

  /**
   * Commits a write transaction with at-least-once semantics.
   *
   * Apply the given mutations atomically, using a single RPC, and therefore
   * without replay protection.  That is, it is possible that the mutations
   * will be applied more than once. If the mutations are not idempotent, this
   * may lead to a failure (for example, an insert may fail with "already
   * exists" even though the row did not exist before the call was made).
   * Accordingly, this call may only be appropriate for idempotent, latency-
   * sensitive and/or high-throughput blind writing.
   *
   * @note Prefer the `Commit` overloads if you want exactly-once semantics
   *     or want to reapply mutations after a `kAborted` error.
   *
   * @par Example
   * @snippet samples.cc commit-at-least-once
   *
   * @param transaction_options Execute the commit in a temporary transaction
   *     with these options.
   * @param mutations The mutations to be executed when this transaction
   *     commits. All mutations are applied atomically, in the order they
   *     appear in this list.
   * @param opts (optional) The options to use for this call.
   *
   * @return A `StatusOr` containing the result of the commit or error status
   *     on failure.
   */
  StatusOr<CommitResult> CommitAtLeastOnce(
      Transaction::ReadWriteOptions transaction_options, Mutations mutations,
      Options opts = {});

  /**
   * Commits the mutation groups, batched efficiently into transactions with
   * at-least-once semantics, using a single RPC.
   *
   * All mutations within a group are committed atomically. There is no
   * atomicity or ordering between groups however, so all groups must be
   * independent of each other.
   *
   * Partial failure is possible. That is, some groups can commit successfully
   * while others fail. The results of individual batches are returned via the
   * response stream as their transactions complete.
   *
   * Mutation groups are not replay protected. That is, it is possible that
   * each mutation group may be applied more than once. If the mutations are
   * not idempotent, this may lead to a failure. For example, replays of an
   * insert mutation might produce an "already exists" error, or, if you use
   * generated or commit-timestamp-based keys, might result in additional
   * rows being added to the mutation's table. We recommend structuring your
   * mutation groups to be idempotent to avoid this issue.
   *
   * @note Prefer the `Commit` overloads if you want exactly-once semantics
   *     or want to automatically reapply mutations after a `kAborted` error.
   *
   * @par Example
   * @snippet samples.cc commit-at-least-once-batched
   *
   * @param mutation_groups The mutation groups to be batched into temporary
   *     transactions and committed.
   * @param opts (optional) The options to use for this call. Expected options
   *     include any of the following types:
   *       - `google::cloud::spanner::RequestPriorityOption`
   *       - `google::cloud::spanner::RequestTagOption`
   *       - `google::cloud::spanner::TransactionTagOption`
   */
  BatchedCommitResultStream CommitAtLeastOnce(
      std::vector<Mutations> mutation_groups, Options opts = {});

  /**
   * Rolls back a read-write transaction, releasing any locks it holds.
   *
   * At any time before `Commit`, the client can call `Rollback` to abort the
   * transaction. It is a good idea to call this for any read-write transaction
   * that includes  one or more `Read`, `ExecuteQuery`, or `ExecuteDml` requests
   * and ultimately decides not to commit.
   *
   * @warning It is an error to call `Rollback` with a read-only transaction.
   *
   * @param transaction The transaction to roll back.
   * @param opts (optional) The options to use for this call.
   *
   * @return The error status of the rollback.
   */
  Status Rollback(Transaction transaction, Options opts = {});

  /**
   * Executes a Partitioned DML SQL query.
   *
   * @par Example
   * @snippet samples.cc execute-sql-partitioned
   *
   * @param statement the SQL statement to execute. Please see the
   *     [spanner documentation][dml-partitioned] for the restrictions on the
   *     SQL statements supported by this function.
   * @param opts (optional) The `Options` to use for this call. If given,
   *     these will take precedence over the options set at the client and
   *     environment levels.
   *
   * @see [Partitioned DML Transactions][txn-partitioned] for an overview of
   *     Partitioned DML transactions.
   * @see [Partitioned DML][dml-partitioned] for a description of which SQL
   *     statements are supported in Partitioned DML transactions.
   * [txn-partitioned]:
   * https://cloud.google.com/spanner/docs/transactions#partitioned_dml_transactions
   * [dml-partitioned]: https://cloud.google.com/spanner/docs/dml-partitioned
   */
  StatusOr<PartitionedDmlResult> ExecutePartitionedDml(SqlStatement statement,
                                                       Options opts = {});

  ///@{
  /// @name Backwards compatibility for ClientOptions.
  explicit Client(std::shared_ptr<Connection> conn, ClientOptions const& opts)
      : Client(std::move(conn), Options(opts)) {}
  explicit Client(std::shared_ptr<Connection> conn,
                  std::initializer_list<internal::NonConstructible>)
      : Client(std::move(conn)) {}
  ///@}

  ///@{
  /// @name Backwards compatibility for ReadOptions.
  /**
   * @copybrief Read(std::string,KeySet,std::vector<std::string>,Options)
   * @see Read(std::string,KeySet,std::vector<std::string>,Options)
   */
  RowStream Read(std::string table, KeySet keys,
                 std::vector<std::string> columns,
                 ReadOptions const& read_options) {
    return Read(std::move(table), std::move(keys), std::move(columns),
                ToOptions(read_options));
  }
  /**
   * @copybrief Read(std::string,KeySet,std::vector<std::string>,Options)
   * @see Read(std::string,KeySet,std::vector<std::string>,Options)
   */
  RowStream Read(std::string table, KeySet keys,
                 std::vector<std::string> columns,
                 std::initializer_list<internal::NonConstructible>) {
    return Read(std::move(table), std::move(keys), std::move(columns));
  }
  /**
   * @copybrief Read(Transaction::SingleUseOptions,std::string,KeySet,std::vector<std::string>,Options)
   * @see Read(Transaction::SingleUseOptions,std::string,KeySet,std::vector<std::string>,Options)
   */
  RowStream Read(Transaction::SingleUseOptions transaction_options,
                 std::string table, KeySet keys,
                 std::vector<std::string> columns,
                 ReadOptions const& read_options) {
    return Read(std::move(transaction_options), std::move(table),
                std::move(keys), std::move(columns), ToOptions(read_options));
  }
  /**
   * @copybrief Read(Transaction::SingleUseOptions,std::string,KeySet,std::vector<std::string>,Options)
   * @see Read(Transaction::SingleUseOptions,std::string,KeySet,std::vector<std::string>,Options)
   */
  RowStream Read(Transaction::SingleUseOptions transaction_options,
                 std::string table, KeySet keys,
                 std::vector<std::string> columns,
                 std::initializer_list<internal::NonConstructible>) {
    return Read(std::move(transaction_options), std::move(table),
                std::move(keys), std::move(columns));
  }
  /**
   * @copybrief Read(Transaction,std::string,KeySet,std::vector<std::string>,Options)
   * @see Read(Transaction,std::string,KeySet,std::vector<std::string>,Options)
   */
  RowStream Read(Transaction transaction, std::string table, KeySet keys,
                 std::vector<std::string> columns,
                 ReadOptions const& read_options) {
    return Read(std::move(transaction), std::move(table), std::move(keys),
                std::move(columns), ToOptions(read_options));
  }
  /**
   * @copybrief Read(Transaction,std::string,KeySet,std::vector<std::string>,Options)
   * @see Read(Transaction,std::string,KeySet,std::vector<std::string>,Options)
   */
  RowStream Read(Transaction transaction, std::string table, KeySet keys,
                 std::vector<std::string> columns,
                 std::initializer_list<internal::NonConstructible>) {
    return Read(std::move(transaction), std::move(table), std::move(keys),
                std::move(columns));
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for ReadOptions and PartitionOptions.
  /**
   * @copybrief PartitionRead(Transaction,std::string,KeySet,std::vector<std::string>,Options)
   * @see PartitionRead(Transaction,std::string,KeySet,std::vector<std::string>,Options)
   */
  StatusOr<std::vector<ReadPartition>> PartitionRead(
      Transaction transaction, std::string table, KeySet keys,
      std::vector<std::string> columns, ReadOptions const& read_options,
      PartitionOptions const& partition_options) {
    return PartitionRead(std::move(transaction), std::move(table),
                         std::move(keys), std::move(columns),
                         internal::MergeOptions(ToOptions(read_options),
                                                ToOptions(partition_options)));
  }
  /**
   * @copybrief PartitionRead(Transaction,std::string,KeySet,std::vector<std::string>,Options)
   * @see PartitionRead(Transaction,std::string,KeySet,std::vector<std::string>,Options)
   */
  StatusOr<std::vector<ReadPartition>> PartitionRead(
      Transaction transaction, std::string table, KeySet keys,
      std::vector<std::string> columns,
      std::initializer_list<internal::NonConstructible>) {
    return PartitionRead(std::move(transaction), std::move(table),
                         std::move(keys), std::move(columns));
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for QueryOptions.
  /**
   * @copybrief ExecuteQuery(SqlStatement,Options)
   * @see ExecuteQuery(SqlStatement,Options)
   */
  RowStream ExecuteQuery(SqlStatement statement, QueryOptions const& opts) {
    return ExecuteQuery(std::move(statement), Options(opts));
  }
  /**
   * @copybrief ExecuteQuery(SqlStatement,Options)
   * @see ExecuteQuery(SqlStatement,Options)
   */
  RowStream ExecuteQuery(SqlStatement statement,
                         std::initializer_list<internal::NonConstructible>) {
    return ExecuteQuery(std::move(statement));
  }
  /**
   * @copybrief ExecuteQuery(Transaction::SingleUseOptions,SqlStatement,Options)
   * @see ExecuteQuery(Transaction::SingleUseOptions,SqlStatement,Options)
   */
  RowStream ExecuteQuery(Transaction::SingleUseOptions transaction_options,
                         SqlStatement statement, QueryOptions const& opts) {
    return ExecuteQuery(std::move(transaction_options), std::move(statement),
                        Options(opts));
  }
  /**
   * @copybrief ExecuteQuery(Transaction::SingleUseOptions,SqlStatement,Options)
   * @see ExecuteQuery(Transaction::SingleUseOptions,SqlStatement,Options)
   */
  RowStream ExecuteQuery(Transaction::SingleUseOptions transaction_options,
                         SqlStatement statement,
                         std::initializer_list<internal::NonConstructible>) {
    return ExecuteQuery(std::move(transaction_options), std::move(statement));
  }
  /**
   * @copybrief ExecuteQuery(Transaction,SqlStatement,Options)
   * @see ExecuteQuery(Transaction,SqlStatement,Options)
   */
  RowStream ExecuteQuery(Transaction transaction, SqlStatement statement,
                         QueryOptions const& opts) {
    return ExecuteQuery(std::move(transaction), std::move(statement),
                        Options(opts));
  }
  /**
   * @copybrief ExecuteQuery(Transaction,SqlStatement,Options)
   * @see ExecuteQuery(Transaction,SqlStatement,Options)
   */
  RowStream ExecuteQuery(Transaction transaction, SqlStatement statement,
                         std::initializer_list<internal::NonConstructible>) {
    return ExecuteQuery(std::move(transaction), std::move(statement));
  }
  /**
   * @copybrief ExecuteQuery(QueryPartition const&,Options)
   * @see ExecuteQuery(QueryPartition const&,Options)
   */
  RowStream ExecuteQuery(QueryPartition const& partition,
                         QueryOptions const& opts) {
    return ExecuteQuery(partition, Options(opts));
  }
  /**
   * @copybrief ExecuteQuery(QueryPartition const&,Options)
   * @see ExecuteQuery(QueryPartition const&,Options)
   */
  RowStream ExecuteQuery(QueryPartition const& partition,
                         std::initializer_list<internal::NonConstructible>) {
    return ExecuteQuery(partition);
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for QueryOptions.
  /**
   * @copybrief ProfileQuery(SqlStatement,Options)
   * @see ProfileQuery(SqlStatement,Options)
   */
  ProfileQueryResult ProfileQuery(SqlStatement statement,
                                  QueryOptions const& opts) {
    return ProfileQuery(std::move(statement), Options(opts));
  }
  /**
   * @copybrief ProfileQuery(SqlStatement,Options)
   * @see ProfileQuery(SqlStatement,Options)
   */
  ProfileQueryResult ProfileQuery(
      SqlStatement statement,
      std::initializer_list<internal::NonConstructible>) {
    return ProfileQuery(std::move(statement));
  }
  /**
   * @copybrief ProfileQuery(Transaction::SingleUseOptions,SqlStatement,Options)
   * @see ProfileQuery(Transaction::SingleUseOptions,SqlStatement,Options)
   */
  ProfileQueryResult ProfileQuery(
      Transaction::SingleUseOptions transaction_options, SqlStatement statement,
      QueryOptions const& opts) {
    return ProfileQuery(std::move(transaction_options), std::move(statement),
                        Options(opts));
  }
  /**
   * @copybrief ProfileQuery(Transaction::SingleUseOptions,SqlStatement,Options)
   * @see ProfileQuery(Transaction::SingleUseOptions,SqlStatement,Options)
   */
  ProfileQueryResult ProfileQuery(
      Transaction::SingleUseOptions transaction_options, SqlStatement statement,
      std::initializer_list<internal::NonConstructible>) {
    return ProfileQuery(std::move(transaction_options), std::move(statement));
  }
  /**
   * @copybrief ProfileQuery(Transaction,SqlStatement,Options)
   * @see ProfileQuery(Transaction,SqlStatement,Options)
   */
  ProfileQueryResult ProfileQuery(Transaction transaction,
                                  SqlStatement statement,
                                  QueryOptions const& opts) {
    return ProfileQuery(std::move(transaction), std::move(statement),
                        Options(opts));
  }
  /**
   * @copybrief ProfileQuery(Transaction,SqlStatement,Options)
   * @see ProfileQuery(Transaction,SqlStatement,Options)
   */
  ProfileQueryResult ProfileQuery(
      Transaction transaction, SqlStatement statement,
      std::initializer_list<internal::NonConstructible>) {
    return ProfileQuery(std::move(transaction), std::move(statement));
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for PartitionOptions.
  /**
   * @copybrief PartitionQuery(Transaction,SqlStatement,Options)
   * @see PartitionQuery(Transaction,SqlStatement,Options)
   */
  StatusOr<std::vector<QueryPartition>> PartitionQuery(
      Transaction transaction, SqlStatement statement,
      PartitionOptions const& partition_options) {
    return PartitionQuery(std::move(transaction), std::move(statement),
                          ToOptions(partition_options));
  }
  /**
   * @copybrief PartitionQuery(Transaction,SqlStatement,Options)
   * @see PartitionQuery(Transaction,SqlStatement,Options)
   */
  StatusOr<std::vector<QueryPartition>> PartitionQuery(
      Transaction transaction, SqlStatement statement,
      std::initializer_list<internal::NonConstructible>) {
    return PartitionQuery(std::move(transaction), std::move(statement));
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for QueryOptions.
  /**
   * @copybrief ExecuteDml(Transaction,SqlStatement,Options)
   * @see ExecuteDml(Transaction,SqlStatement,Options)
   */
  StatusOr<DmlResult> ExecuteDml(Transaction transaction,
                                 SqlStatement statement,
                                 QueryOptions const& opts) {
    return ExecuteDml(std::move(transaction), std::move(statement),
                      Options(opts));
  }
  /**
   * @copybrief ExecuteDml(Transaction,SqlStatement,Options)
   * @see ExecuteDml(Transaction,SqlStatement,Options)
   */
  StatusOr<DmlResult> ExecuteDml(
      Transaction transaction, SqlStatement statement,
      std::initializer_list<internal::NonConstructible>) {
    return ExecuteDml(std::move(transaction), std::move(statement));
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for QueryOptions.
  StatusOr<ProfileDmlResult> ProfileDml(Transaction transaction,
                                        SqlStatement statement,
                                        QueryOptions const& opts) {
    return ProfileDml(std::move(transaction), std::move(statement),
                      Options(opts));
  }
  StatusOr<ProfileDmlResult> ProfileDml(
      Transaction transaction, SqlStatement statement,
      std::initializer_list<internal::NonConstructible>) {
    return ProfileDml(std::move(transaction), std::move(statement));
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for QueryOptions.
  /**
   * @copybrief AnalyzeSql(Transaction,SqlStatement,Options)
   * @see AnalyzeSql(Transaction,SqlStatement,Options)
   */
  StatusOr<ExecutionPlan> AnalyzeSql(Transaction transaction,
                                     SqlStatement statement,
                                     QueryOptions const& opts) {
    return AnalyzeSql(std::move(transaction), std::move(statement),
                      Options(opts));
  }
  /**
   * @copybrief AnalyzeSql(Transaction,SqlStatement,Options)
   * @see AnalyzeSql(Transaction,SqlStatement,Options)
   */
  StatusOr<ExecutionPlan> AnalyzeSql(
      Transaction transaction, SqlStatement statement,
      std::initializer_list<internal::NonConstructible>) {
    return AnalyzeSql(std::move(transaction), std::move(statement));
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for CommitOptions.
  /**
   * @copybrief Commit(std::function<StatusOr<Mutations>(Transaction)> const&,std::unique_ptr<TransactionRerunPolicy>,std::unique_ptr<BackoffPolicy>,Options)
   * @see Commit(std::function<StatusOr<Mutations>(Transaction)> const&,std::unique_ptr<TransactionRerunPolicy>,std::unique_ptr<BackoffPolicy>,Options)
   */
  StatusOr<CommitResult> Commit(
      std::function<StatusOr<Mutations>(Transaction)> const& mutator,
      std::unique_ptr<TransactionRerunPolicy> rerun_policy,
      std::unique_ptr<BackoffPolicy> backoff_policy,
      CommitOptions const& commit_options) {
    return Commit(mutator, std::move(rerun_policy), std::move(backoff_policy),
                  Options(commit_options));
  }
  /**
   * @copybrief Commit(std::function<StatusOr<Mutations>(Transaction)> const&,std::unique_ptr<TransactionRerunPolicy>,std::unique_ptr<BackoffPolicy>,Options)
   * @see Commit(std::function<StatusOr<Mutations>(Transaction)> const&,std::unique_ptr<TransactionRerunPolicy>,std::unique_ptr<BackoffPolicy>,Options)
   */
  StatusOr<CommitResult> Commit(
      std::function<StatusOr<Mutations>(Transaction)> const& mutator,
      std::unique_ptr<TransactionRerunPolicy> rerun_policy,
      std::unique_ptr<BackoffPolicy> backoff_policy,
      std::initializer_list<internal::NonConstructible>) {
    return Commit(mutator, std::move(rerun_policy), std::move(backoff_policy));
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for CommitOptions.
  /**
   * @copybrief Commit(std::function<StatusOr<Mutations>(Transaction)> const&,Options)
   */
  StatusOr<CommitResult> Commit(
      std::function<StatusOr<Mutations>(Transaction)> const& mutator,
      CommitOptions const& commit_options) {
    return Commit(mutator, Options(commit_options));
  }
  /**
   * @see Commit(std::function<StatusOr<Mutations>(Transaction)> const&,Options)
   */
  StatusOr<CommitResult> Commit(
      std::function<StatusOr<Mutations>(Transaction)> const& mutator,
      std::initializer_list<internal::NonConstructible>) {
    return Commit(mutator);
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for CommitOptions.
  /**
   * @copybrief Commit(Mutations,Options)
   * @see Commit(Mutations,Options)
   */
  StatusOr<CommitResult> Commit(Mutations mutations,
                                CommitOptions const& commit_options) {
    return Commit(std::move(mutations), Options(commit_options));
  }
  /**
   * @copybrief Commit(Mutations,Options)
   * @see Commit(Mutations,Options)
   */
  StatusOr<CommitResult> Commit(
      Mutations mutations, std::initializer_list<internal::NonConstructible>) {
    return Commit(std::move(mutations));
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for CommitOptions.
  /**
   * @copybrief Commit(Transaction,Mutations,Options)
   * @see Commit(Transaction,Mutations,Options)
   */
  StatusOr<CommitResult> Commit(Transaction transaction, Mutations mutations,
                                CommitOptions const& commit_options) {
    return Commit(std::move(transaction), std::move(mutations),
                  Options(commit_options));
  }
  /**
   * @copybrief Commit(Transaction,Mutations,Options)
   * @see Commit(Transaction,Mutations,Options)
   */
  StatusOr<CommitResult> Commit(
      Transaction transaction, Mutations mutations,
      std::initializer_list<internal::NonConstructible>) {
    return Commit(std::move(transaction), std::move(mutations));
  }
  ///@}

  ///@{
  /// @name Backwards compatibility for QueryOptions.
  /**
   * @copybrief ExecutePartitionedDml(SqlStatement,Options)
   * @see ExecutePartitionedDml(SqlStatement,Options)
   */
  StatusOr<PartitionedDmlResult> ExecutePartitionedDml(
      SqlStatement statement, QueryOptions const& opts) {
    return ExecutePartitionedDml(std::move(statement), Options(opts));
  }
  /**
   * @copybrief ExecutePartitionedDml(SqlStatement,Options)
   * @see ExecutePartitionedDml(SqlStatement,Options)
   */
  StatusOr<PartitionedDmlResult> ExecutePartitionedDml(
      SqlStatement statement,
      std::initializer_list<internal::NonConstructible>) {
    return ExecutePartitionedDml(std::move(statement));
  }
  ///@}

 private:
  std::shared_ptr<Connection> conn_;
  Options opts_;
};

/**
 * Returns a Connection object that can be used for interacting with Spanner.
 *
 * The returned connection object should not be used directly; instead it
 * should be given to a `Client` instance, and methods should be invoked on
 * `Client`.
 *
 * The optional @p opts argument may be used to configure aspects of the
 * returned `Connection`. Expected options are any of the types in the
 * following option lists.
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::spanner::SpannerPolicyOptionList`
 * - `google::cloud::spanner::SessionPoolOptionList`
 *
 * @note Unrecognized options will be ignored. To debug issues with options set
 *     `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment and unexpected
 *     options will be logged.
 *
 * @see `Connection`
 *
 * @param db See `Database`.
 * @param opts (optional) Configure the `Connection` created by this function.
 */
std::shared_ptr<spanner::Connection> MakeConnection(spanner::Database const& db,
                                                    Options opts = {});

/**
 * Returns a Connection object that can be used for interacting with Spanner.
 *
 * The returned connection object should not be used directly, rather it should
 * be given to a `Client` instance, and methods should be invoked on `Client`.
 *
 * @deprecated Please use the `MakeConnection()` overload that accepts
 *     `google::cloud::Options` instead.
 *
 * @see `Connection`
 *
 * @param db See `Database`.
 * @param connection_options configure the `Connection` created by this
 *     function.
 * @param session_pool_options (optional) configure the `SessionPool` created
 *     by the `Connection`.
 */
std::shared_ptr<Connection> MakeConnection(
    Database const& db, ConnectionOptions const& connection_options,
    SessionPoolOptions session_pool_options = SessionPoolOptions());

/**
 * @copydoc MakeConnection(Database const&, ConnectionOptions const&, SessionPoolOptions)
 *
 * @deprecated Please use the `MakeConnection()` overload that accepts
 *     `google::cloud::Options` instead.
 *
 * @par Example
 * @snippet samples.cc custom-retry-policy
 *
 * @param retry_policy override the default `RetryPolicy`, controls how long
 *     the returned `Connection` object retries requests on transient
 *     failures.
 * @param backoff_policy override the default `BackoffPolicy`, controls how
 *     long the `Connection` object waits before retrying a failed request.
 */
std::shared_ptr<Connection> MakeConnection(
    Database const& db, ConnectionOptions const& connection_options,
    SessionPoolOptions session_pool_options,
    std::unique_ptr<RetryPolicy> retry_policy,
    std::unique_ptr<BackoffPolicy> backoff_policy);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace spanner
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SPANNER_CLIENT_H
