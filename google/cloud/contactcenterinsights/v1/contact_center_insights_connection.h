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
// source: google/cloud/contactcenterinsights/v1/contact_center_insights.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTACTCENTERINSIGHTS_V1_CONTACT_CENTER_INSIGHTS_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTACTCENTERINSIGHTS_V1_CONTACT_CENTER_INSIGHTS_CONNECTION_H

#include "google/cloud/contactcenterinsights/v1/contact_center_insights_connection_idempotency_policy.h"
#include "google/cloud/contactcenterinsights/v1/internal/contact_center_insights_retry_traits.h"
#include "google/cloud/contactcenterinsights/v1/internal/contact_center_insights_stub.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace contactcenterinsights_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ContactCenterInsightsRetryPolicy =
    ::google::cloud::internal::TraitBasedRetryPolicy<
        contactcenterinsights_v1_internal::ContactCenterInsightsRetryTraits>;

using ContactCenterInsightsLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        contactcenterinsights_v1_internal::ContactCenterInsightsRetryTraits>;

using ContactCenterInsightsLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        contactcenterinsights_v1_internal::ContactCenterInsightsRetryTraits>;

/**
 * The `ContactCenterInsightsConnection` object for
 * `ContactCenterInsightsClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `ContactCenterInsightsClient`. This allows users to inject custom
 * behavior (e.g., with a Google Mock object) when writing tests that use
 * objects of type `ContactCenterInsightsClient`.
 *
 * To create a concrete instance, see `MakeContactCenterInsightsConnection()`.
 *
 * For mocking, see
 * `contactcenterinsights_v1_mocks::MockContactCenterInsightsConnection`.
 */
class ContactCenterInsightsConnection {
 public:
  virtual ~ContactCenterInsightsConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StatusOr<google::cloud::contactcenterinsights::v1::Conversation>
  CreateConversation(
      google::cloud::contactcenterinsights::v1::CreateConversationRequest const&
          request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::Conversation>
  UpdateConversation(
      google::cloud::contactcenterinsights::v1::UpdateConversationRequest const&
          request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::Conversation>
  GetConversation(
      google::cloud::contactcenterinsights::v1::GetConversationRequest const&
          request);

  virtual StreamRange<google::cloud::contactcenterinsights::v1::Conversation>
  ListConversations(
      google::cloud::contactcenterinsights::v1::ListConversationsRequest
          request);

  virtual Status DeleteConversation(
      google::cloud::contactcenterinsights::v1::DeleteConversationRequest const&
          request);

  virtual future<StatusOr<google::cloud::contactcenterinsights::v1::Analysis>>
  CreateAnalysis(
      google::cloud::contactcenterinsights::v1::CreateAnalysisRequest const&
          request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::Analysis>
  GetAnalysis(
      google::cloud::contactcenterinsights::v1::GetAnalysisRequest const&
          request);

  virtual StreamRange<google::cloud::contactcenterinsights::v1::Analysis>
  ListAnalyses(
      google::cloud::contactcenterinsights::v1::ListAnalysesRequest request);

  virtual Status DeleteAnalysis(
      google::cloud::contactcenterinsights::v1::DeleteAnalysisRequest const&
          request);

  virtual future<StatusOr<google::cloud::contactcenterinsights::v1::
                              BulkAnalyzeConversationsResponse>>
  BulkAnalyzeConversations(google::cloud::contactcenterinsights::v1::
                               BulkAnalyzeConversationsRequest const& request);

  virtual future<StatusOr<
      google::cloud::contactcenterinsights::v1::IngestConversationsResponse>>
  IngestConversations(google::cloud::contactcenterinsights::v1::
                          IngestConversationsRequest const& request);

  virtual future<StatusOr<
      google::cloud::contactcenterinsights::v1::ExportInsightsDataResponse>>
  ExportInsightsData(
      google::cloud::contactcenterinsights::v1::ExportInsightsDataRequest const&
          request);

  virtual future<StatusOr<google::cloud::contactcenterinsights::v1::IssueModel>>
  CreateIssueModel(
      google::cloud::contactcenterinsights::v1::CreateIssueModelRequest const&
          request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::IssueModel>
  UpdateIssueModel(
      google::cloud::contactcenterinsights::v1::UpdateIssueModelRequest const&
          request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::IssueModel>
  GetIssueModel(
      google::cloud::contactcenterinsights::v1::GetIssueModelRequest const&
          request);

  virtual StatusOr<
      google::cloud::contactcenterinsights::v1::ListIssueModelsResponse>
  ListIssueModels(
      google::cloud::contactcenterinsights::v1::ListIssueModelsRequest const&
          request);

  virtual future<StatusOr<
      google::cloud::contactcenterinsights::v1::DeleteIssueModelMetadata>>
  DeleteIssueModel(
      google::cloud::contactcenterinsights::v1::DeleteIssueModelRequest const&
          request);

  virtual future<StatusOr<
      google::cloud::contactcenterinsights::v1::DeployIssueModelResponse>>
  DeployIssueModel(
      google::cloud::contactcenterinsights::v1::DeployIssueModelRequest const&
          request);

  virtual future<StatusOr<
      google::cloud::contactcenterinsights::v1::UndeployIssueModelResponse>>
  UndeployIssueModel(
      google::cloud::contactcenterinsights::v1::UndeployIssueModelRequest const&
          request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::Issue> GetIssue(
      google::cloud::contactcenterinsights::v1::GetIssueRequest const& request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::ListIssuesResponse>
  ListIssues(google::cloud::contactcenterinsights::v1::ListIssuesRequest const&
                 request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::Issue> UpdateIssue(
      google::cloud::contactcenterinsights::v1::UpdateIssueRequest const&
          request);

  virtual Status DeleteIssue(
      google::cloud::contactcenterinsights::v1::DeleteIssueRequest const&
          request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::
                       CalculateIssueModelStatsResponse>
  CalculateIssueModelStats(google::cloud::contactcenterinsights::v1::
                               CalculateIssueModelStatsRequest const& request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::PhraseMatcher>
  CreatePhraseMatcher(google::cloud::contactcenterinsights::v1::
                          CreatePhraseMatcherRequest const& request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::PhraseMatcher>
  GetPhraseMatcher(
      google::cloud::contactcenterinsights::v1::GetPhraseMatcherRequest const&
          request);

  virtual StreamRange<google::cloud::contactcenterinsights::v1::PhraseMatcher>
  ListPhraseMatchers(
      google::cloud::contactcenterinsights::v1::ListPhraseMatchersRequest
          request);

  virtual Status DeletePhraseMatcher(
      google::cloud::contactcenterinsights::v1::
          DeletePhraseMatcherRequest const& request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::PhraseMatcher>
  UpdatePhraseMatcher(google::cloud::contactcenterinsights::v1::
                          UpdatePhraseMatcherRequest const& request);

  virtual StatusOr<
      google::cloud::contactcenterinsights::v1::CalculateStatsResponse>
  CalculateStats(
      google::cloud::contactcenterinsights::v1::CalculateStatsRequest const&
          request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::Settings>
  GetSettings(
      google::cloud::contactcenterinsights::v1::GetSettingsRequest const&
          request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::Settings>
  UpdateSettings(
      google::cloud::contactcenterinsights::v1::UpdateSettingsRequest const&
          request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::View> CreateView(
      google::cloud::contactcenterinsights::v1::CreateViewRequest const&
          request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::View> GetView(
      google::cloud::contactcenterinsights::v1::GetViewRequest const& request);

  virtual StreamRange<google::cloud::contactcenterinsights::v1::View> ListViews(
      google::cloud::contactcenterinsights::v1::ListViewsRequest request);

  virtual StatusOr<google::cloud::contactcenterinsights::v1::View> UpdateView(
      google::cloud::contactcenterinsights::v1::UpdateViewRequest const&
          request);

  virtual Status DeleteView(
      google::cloud::contactcenterinsights::v1::DeleteViewRequest const&
          request);
};

/**
 * A factory function to construct an object of type
 * `ContactCenterInsightsConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of
 * ContactCenterInsightsClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `ContactCenterInsightsConnection`. Expected options are any of the
 * types in the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * -
 * `google::cloud::contactcenterinsights_v1::ContactCenterInsightsPolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `ContactCenterInsightsConnection`
 * created by this function.
 */
std::shared_ptr<ContactCenterInsightsConnection>
MakeContactCenterInsightsConnection(Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace contactcenterinsights_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTACTCENTERINSIGHTS_V1_CONTACT_CENTER_INSIGHTS_CONNECTION_H
