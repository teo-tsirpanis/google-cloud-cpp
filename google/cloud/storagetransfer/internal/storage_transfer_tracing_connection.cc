// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/storagetransfer/v1/transfer.proto

#include "google/cloud/storagetransfer/internal/storage_transfer_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace storagetransfer_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

StorageTransferServiceTracingConnection::
    StorageTransferServiceTracingConnection(
        std::shared_ptr<storagetransfer::StorageTransferServiceConnection>
            child)
    : child_(std::move(child)) {}

StatusOr<google::storagetransfer::v1::GoogleServiceAccount>
StorageTransferServiceTracingConnection::GetGoogleServiceAccount(
    google::storagetransfer::v1::GetGoogleServiceAccountRequest const&
        request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::"
      "GetGoogleServiceAccount");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetGoogleServiceAccount(request));
}

StatusOr<google::storagetransfer::v1::TransferJob>
StorageTransferServiceTracingConnection::CreateTransferJob(
    google::storagetransfer::v1::CreateTransferJobRequest const& request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::CreateTransferJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateTransferJob(request));
}

StatusOr<google::storagetransfer::v1::TransferJob>
StorageTransferServiceTracingConnection::UpdateTransferJob(
    google::storagetransfer::v1::UpdateTransferJobRequest const& request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::UpdateTransferJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateTransferJob(request));
}

StatusOr<google::storagetransfer::v1::TransferJob>
StorageTransferServiceTracingConnection::GetTransferJob(
    google::storagetransfer::v1::GetTransferJobRequest const& request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::GetTransferJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetTransferJob(request));
}

StreamRange<google::storagetransfer::v1::TransferJob>
StorageTransferServiceTracingConnection::ListTransferJobs(
    google::storagetransfer::v1::ListTransferJobsRequest request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::ListTransferJobs");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListTransferJobs(std::move(request));
  return internal::MakeTracedStreamRange<
      google::storagetransfer::v1::TransferJob>(std::move(span), std::move(sr));
}

Status StorageTransferServiceTracingConnection::PauseTransferOperation(
    google::storagetransfer::v1::PauseTransferOperationRequest const& request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::"
      "PauseTransferOperation");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->PauseTransferOperation(request));
}

Status StorageTransferServiceTracingConnection::ResumeTransferOperation(
    google::storagetransfer::v1::ResumeTransferOperationRequest const&
        request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::"
      "ResumeTransferOperation");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->ResumeTransferOperation(request));
}

future<StatusOr<google::storagetransfer::v1::TransferOperation>>
StorageTransferServiceTracingConnection::RunTransferJob(
    google::storagetransfer::v1::RunTransferJobRequest const& request) {
  return child_->RunTransferJob(request);
}

Status StorageTransferServiceTracingConnection::DeleteTransferJob(
    google::storagetransfer::v1::DeleteTransferJobRequest const& request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::DeleteTransferJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteTransferJob(request));
}

StatusOr<google::storagetransfer::v1::AgentPool>
StorageTransferServiceTracingConnection::CreateAgentPool(
    google::storagetransfer::v1::CreateAgentPoolRequest const& request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::CreateAgentPool");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateAgentPool(request));
}

StatusOr<google::storagetransfer::v1::AgentPool>
StorageTransferServiceTracingConnection::UpdateAgentPool(
    google::storagetransfer::v1::UpdateAgentPoolRequest const& request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::UpdateAgentPool");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateAgentPool(request));
}

StatusOr<google::storagetransfer::v1::AgentPool>
StorageTransferServiceTracingConnection::GetAgentPool(
    google::storagetransfer::v1::GetAgentPoolRequest const& request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::GetAgentPool");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetAgentPool(request));
}

StreamRange<google::storagetransfer::v1::AgentPool>
StorageTransferServiceTracingConnection::ListAgentPools(
    google::storagetransfer::v1::ListAgentPoolsRequest request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::ListAgentPools");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListAgentPools(std::move(request));
  return internal::MakeTracedStreamRange<
      google::storagetransfer::v1::AgentPool>(std::move(span), std::move(sr));
}

Status StorageTransferServiceTracingConnection::DeleteAgentPool(
    google::storagetransfer::v1::DeleteAgentPoolRequest const& request) {
  auto span = internal::MakeSpan(
      "storagetransfer::StorageTransferServiceConnection::DeleteAgentPool");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteAgentPool(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<storagetransfer::StorageTransferServiceConnection>
MakeStorageTransferServiceTracingConnection(
    std::shared_ptr<storagetransfer::StorageTransferServiceConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<StorageTransferServiceTracingConnection>(
        std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storagetransfer_internal
}  // namespace cloud
}  // namespace google
