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
// source: google/cloud/securitycenter/v1/securitycenter_service.proto

#include "google/cloud/securitycenter/internal/security_center_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace securitycenter_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

SecurityCenterTracingConnection::SecurityCenterTracingConnection(
    std::shared_ptr<securitycenter::SecurityCenterConnection> child)
    : child_(std::move(child)) {}

future<StatusOr<google::cloud::securitycenter::v1::BulkMuteFindingsResponse>>
SecurityCenterTracingConnection::BulkMuteFindings(
    google::cloud::securitycenter::v1::BulkMuteFindingsRequest const& request) {
  return child_->BulkMuteFindings(request);
}

StatusOr<google::cloud::securitycenter::v1::Source>
SecurityCenterTracingConnection::CreateSource(
    google::cloud::securitycenter::v1::CreateSourceRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::CreateSource");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateSource(request));
}

StatusOr<google::cloud::securitycenter::v1::Finding>
SecurityCenterTracingConnection::CreateFinding(
    google::cloud::securitycenter::v1::CreateFindingRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::CreateFinding");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateFinding(request));
}

StatusOr<google::cloud::securitycenter::v1::MuteConfig>
SecurityCenterTracingConnection::CreateMuteConfig(
    google::cloud::securitycenter::v1::CreateMuteConfigRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::CreateMuteConfig");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateMuteConfig(request));
}

StatusOr<google::cloud::securitycenter::v1::NotificationConfig>
SecurityCenterTracingConnection::CreateNotificationConfig(
    google::cloud::securitycenter::v1::CreateNotificationConfigRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::CreateNotificationConfig");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateNotificationConfig(request));
}

Status SecurityCenterTracingConnection::DeleteMuteConfig(
    google::cloud::securitycenter::v1::DeleteMuteConfigRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::DeleteMuteConfig");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteMuteConfig(request));
}

Status SecurityCenterTracingConnection::DeleteNotificationConfig(
    google::cloud::securitycenter::v1::DeleteNotificationConfigRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::DeleteNotificationConfig");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteNotificationConfig(request));
}

StatusOr<google::cloud::securitycenter::v1::BigQueryExport>
SecurityCenterTracingConnection::GetBigQueryExport(
    google::cloud::securitycenter::v1::GetBigQueryExportRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::GetBigQueryExport");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetBigQueryExport(request));
}

StatusOr<google::iam::v1::Policy> SecurityCenterTracingConnection::GetIamPolicy(
    google::iam::v1::GetIamPolicyRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::GetIamPolicy");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetIamPolicy(request));
}

StatusOr<google::cloud::securitycenter::v1::MuteConfig>
SecurityCenterTracingConnection::GetMuteConfig(
    google::cloud::securitycenter::v1::GetMuteConfigRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::GetMuteConfig");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetMuteConfig(request));
}

StatusOr<google::cloud::securitycenter::v1::NotificationConfig>
SecurityCenterTracingConnection::GetNotificationConfig(
    google::cloud::securitycenter::v1::GetNotificationConfigRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::GetNotificationConfig");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetNotificationConfig(request));
}

StatusOr<google::cloud::securitycenter::v1::OrganizationSettings>
SecurityCenterTracingConnection::GetOrganizationSettings(
    google::cloud::securitycenter::v1::GetOrganizationSettingsRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::GetOrganizationSettings");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetOrganizationSettings(request));
}

StatusOr<google::cloud::securitycenter::v1::Source>
SecurityCenterTracingConnection::GetSource(
    google::cloud::securitycenter::v1::GetSourceRequest const& request) {
  auto span =
      internal::MakeSpan("securitycenter::SecurityCenterConnection::GetSource");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetSource(request));
}

StreamRange<google::cloud::securitycenter::v1::GroupResult>
SecurityCenterTracingConnection::GroupAssets(
    google::cloud::securitycenter::v1::GroupAssetsRequest request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::GroupAssets");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->GroupAssets(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::securitycenter::v1::GroupResult>(std::move(span),
                                                      std::move(sr));
}

StreamRange<google::cloud::securitycenter::v1::GroupResult>
SecurityCenterTracingConnection::GroupFindings(
    google::cloud::securitycenter::v1::GroupFindingsRequest request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::GroupFindings");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->GroupFindings(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::securitycenter::v1::GroupResult>(std::move(span),
                                                      std::move(sr));
}

StreamRange<
    google::cloud::securitycenter::v1::ListAssetsResponse::ListAssetsResult>
SecurityCenterTracingConnection::ListAssets(
    google::cloud::securitycenter::v1::ListAssetsRequest request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::ListAssets");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListAssets(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::securitycenter::v1::ListAssetsResponse::ListAssetsResult>(
      std::move(span), std::move(sr));
}

StreamRange<
    google::cloud::securitycenter::v1::ListFindingsResponse::ListFindingsResult>
SecurityCenterTracingConnection::ListFindings(
    google::cloud::securitycenter::v1::ListFindingsRequest request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::ListFindings");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListFindings(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::securitycenter::v1::ListFindingsResponse::
          ListFindingsResult>(std::move(span), std::move(sr));
}

StreamRange<google::cloud::securitycenter::v1::MuteConfig>
SecurityCenterTracingConnection::ListMuteConfigs(
    google::cloud::securitycenter::v1::ListMuteConfigsRequest request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::ListMuteConfigs");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListMuteConfigs(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::securitycenter::v1::MuteConfig>(std::move(span),
                                                     std::move(sr));
}

StreamRange<google::cloud::securitycenter::v1::NotificationConfig>
SecurityCenterTracingConnection::ListNotificationConfigs(
    google::cloud::securitycenter::v1::ListNotificationConfigsRequest request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::ListNotificationConfigs");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListNotificationConfigs(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::securitycenter::v1::NotificationConfig>(std::move(span),
                                                             std::move(sr));
}

StreamRange<google::cloud::securitycenter::v1::Source>
SecurityCenterTracingConnection::ListSources(
    google::cloud::securitycenter::v1::ListSourcesRequest request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::ListSources");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListSources(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::securitycenter::v1::Source>(std::move(span),
                                                 std::move(sr));
}

future<StatusOr<google::cloud::securitycenter::v1::RunAssetDiscoveryResponse>>
SecurityCenterTracingConnection::RunAssetDiscovery(
    google::cloud::securitycenter::v1::RunAssetDiscoveryRequest const&
        request) {
  return child_->RunAssetDiscovery(request);
}

StatusOr<google::cloud::securitycenter::v1::Finding>
SecurityCenterTracingConnection::SetFindingState(
    google::cloud::securitycenter::v1::SetFindingStateRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::SetFindingState");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->SetFindingState(request));
}

StatusOr<google::cloud::securitycenter::v1::Finding>
SecurityCenterTracingConnection::SetMute(
    google::cloud::securitycenter::v1::SetMuteRequest const& request) {
  auto span =
      internal::MakeSpan("securitycenter::SecurityCenterConnection::SetMute");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->SetMute(request));
}

StatusOr<google::iam::v1::Policy> SecurityCenterTracingConnection::SetIamPolicy(
    google::iam::v1::SetIamPolicyRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::SetIamPolicy");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->SetIamPolicy(request));
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
SecurityCenterTracingConnection::TestIamPermissions(
    google::iam::v1::TestIamPermissionsRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::TestIamPermissions");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->TestIamPermissions(request));
}

StatusOr<google::cloud::securitycenter::v1::ExternalSystem>
SecurityCenterTracingConnection::UpdateExternalSystem(
    google::cloud::securitycenter::v1::UpdateExternalSystemRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::UpdateExternalSystem");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateExternalSystem(request));
}

StatusOr<google::cloud::securitycenter::v1::Finding>
SecurityCenterTracingConnection::UpdateFinding(
    google::cloud::securitycenter::v1::UpdateFindingRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::UpdateFinding");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateFinding(request));
}

StatusOr<google::cloud::securitycenter::v1::MuteConfig>
SecurityCenterTracingConnection::UpdateMuteConfig(
    google::cloud::securitycenter::v1::UpdateMuteConfigRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::UpdateMuteConfig");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateMuteConfig(request));
}

StatusOr<google::cloud::securitycenter::v1::NotificationConfig>
SecurityCenterTracingConnection::UpdateNotificationConfig(
    google::cloud::securitycenter::v1::UpdateNotificationConfigRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::UpdateNotificationConfig");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateNotificationConfig(request));
}

StatusOr<google::cloud::securitycenter::v1::OrganizationSettings>
SecurityCenterTracingConnection::UpdateOrganizationSettings(
    google::cloud::securitycenter::v1::UpdateOrganizationSettingsRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::UpdateOrganizationSettings");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateOrganizationSettings(request));
}

StatusOr<google::cloud::securitycenter::v1::Source>
SecurityCenterTracingConnection::UpdateSource(
    google::cloud::securitycenter::v1::UpdateSourceRequest const& request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::UpdateSource");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateSource(request));
}

StatusOr<google::cloud::securitycenter::v1::SecurityMarks>
SecurityCenterTracingConnection::UpdateSecurityMarks(
    google::cloud::securitycenter::v1::UpdateSecurityMarksRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::UpdateSecurityMarks");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateSecurityMarks(request));
}

StatusOr<google::cloud::securitycenter::v1::BigQueryExport>
SecurityCenterTracingConnection::CreateBigQueryExport(
    google::cloud::securitycenter::v1::CreateBigQueryExportRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::CreateBigQueryExport");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateBigQueryExport(request));
}

Status SecurityCenterTracingConnection::DeleteBigQueryExport(
    google::cloud::securitycenter::v1::DeleteBigQueryExportRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::DeleteBigQueryExport");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteBigQueryExport(request));
}

StatusOr<google::cloud::securitycenter::v1::BigQueryExport>
SecurityCenterTracingConnection::UpdateBigQueryExport(
    google::cloud::securitycenter::v1::UpdateBigQueryExportRequest const&
        request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::UpdateBigQueryExport");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateBigQueryExport(request));
}

StreamRange<google::cloud::securitycenter::v1::BigQueryExport>
SecurityCenterTracingConnection::ListBigQueryExports(
    google::cloud::securitycenter::v1::ListBigQueryExportsRequest request) {
  auto span = internal::MakeSpan(
      "securitycenter::SecurityCenterConnection::ListBigQueryExports");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListBigQueryExports(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::securitycenter::v1::BigQueryExport>(std::move(span),
                                                         std::move(sr));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<securitycenter::SecurityCenterConnection>
MakeSecurityCenterTracingConnection(
    std::shared_ptr<securitycenter::SecurityCenterConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<SecurityCenterTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace securitycenter_internal
}  // namespace cloud
}  // namespace google
