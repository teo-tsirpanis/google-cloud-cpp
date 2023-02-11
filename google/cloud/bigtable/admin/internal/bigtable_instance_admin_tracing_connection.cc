// Copyright 2021 Google LLC
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
// source: google/bigtable/admin/v2/bigtable_instance_admin.proto

#include "google/cloud/bigtable/admin/internal/bigtable_instance_admin_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigtable_admin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

BigtableInstanceAdminTracingConnection::BigtableInstanceAdminTracingConnection(
    std::shared_ptr<bigtable_admin::BigtableInstanceAdminConnection> child)
    : child_(std::move(child)) {}

future<StatusOr<google::bigtable::admin::v2::Instance>>
BigtableInstanceAdminTracingConnection::CreateInstance(
    google::bigtable::admin::v2::CreateInstanceRequest const& request) {
  return child_->CreateInstance(request);
}

StatusOr<google::bigtable::admin::v2::Instance>
BigtableInstanceAdminTracingConnection::GetInstance(
    google::bigtable::admin::v2::GetInstanceRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::GetInstance");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetInstance(request));
}

StatusOr<google::bigtable::admin::v2::ListInstancesResponse>
BigtableInstanceAdminTracingConnection::ListInstances(
    google::bigtable::admin::v2::ListInstancesRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::ListInstances");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->ListInstances(request));
}

StatusOr<google::bigtable::admin::v2::Instance>
BigtableInstanceAdminTracingConnection::UpdateInstance(
    google::bigtable::admin::v2::Instance const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::UpdateInstance");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateInstance(request));
}

future<StatusOr<google::bigtable::admin::v2::Instance>>
BigtableInstanceAdminTracingConnection::PartialUpdateInstance(
    google::bigtable::admin::v2::PartialUpdateInstanceRequest const& request) {
  return child_->PartialUpdateInstance(request);
}

Status BigtableInstanceAdminTracingConnection::DeleteInstance(
    google::bigtable::admin::v2::DeleteInstanceRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::DeleteInstance");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteInstance(request));
}

future<StatusOr<google::bigtable::admin::v2::Cluster>>
BigtableInstanceAdminTracingConnection::CreateCluster(
    google::bigtable::admin::v2::CreateClusterRequest const& request) {
  return child_->CreateCluster(request);
}

StatusOr<google::bigtable::admin::v2::Cluster>
BigtableInstanceAdminTracingConnection::GetCluster(
    google::bigtable::admin::v2::GetClusterRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::GetCluster");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetCluster(request));
}

StatusOr<google::bigtable::admin::v2::ListClustersResponse>
BigtableInstanceAdminTracingConnection::ListClusters(
    google::bigtable::admin::v2::ListClustersRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::ListClusters");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->ListClusters(request));
}

future<StatusOr<google::bigtable::admin::v2::Cluster>>
BigtableInstanceAdminTracingConnection::UpdateCluster(
    google::bigtable::admin::v2::Cluster const& request) {
  return child_->UpdateCluster(request);
}

future<StatusOr<google::bigtable::admin::v2::Cluster>>
BigtableInstanceAdminTracingConnection::PartialUpdateCluster(
    google::bigtable::admin::v2::PartialUpdateClusterRequest const& request) {
  return child_->PartialUpdateCluster(request);
}

Status BigtableInstanceAdminTracingConnection::DeleteCluster(
    google::bigtable::admin::v2::DeleteClusterRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::DeleteCluster");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteCluster(request));
}

StatusOr<google::bigtable::admin::v2::AppProfile>
BigtableInstanceAdminTracingConnection::CreateAppProfile(
    google::bigtable::admin::v2::CreateAppProfileRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::CreateAppProfile");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateAppProfile(request));
}

StatusOr<google::bigtable::admin::v2::AppProfile>
BigtableInstanceAdminTracingConnection::GetAppProfile(
    google::bigtable::admin::v2::GetAppProfileRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::GetAppProfile");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetAppProfile(request));
}

StreamRange<google::bigtable::admin::v2::AppProfile>
BigtableInstanceAdminTracingConnection::ListAppProfiles(
    google::bigtable::admin::v2::ListAppProfilesRequest request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::ListAppProfiles");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListAppProfiles(std::move(request));
  return internal::MakeTracedStreamRange<
      google::bigtable::admin::v2::AppProfile>(std::move(span), std::move(sr));
}

future<StatusOr<google::bigtable::admin::v2::AppProfile>>
BigtableInstanceAdminTracingConnection::UpdateAppProfile(
    google::bigtable::admin::v2::UpdateAppProfileRequest const& request) {
  return child_->UpdateAppProfile(request);
}

Status BigtableInstanceAdminTracingConnection::DeleteAppProfile(
    google::bigtable::admin::v2::DeleteAppProfileRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::DeleteAppProfile");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteAppProfile(request));
}

StatusOr<google::iam::v1::Policy>
BigtableInstanceAdminTracingConnection::GetIamPolicy(
    google::iam::v1::GetIamPolicyRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::GetIamPolicy");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetIamPolicy(request));
}

StatusOr<google::iam::v1::Policy>
BigtableInstanceAdminTracingConnection::SetIamPolicy(
    google::iam::v1::SetIamPolicyRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::SetIamPolicy");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->SetIamPolicy(request));
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
BigtableInstanceAdminTracingConnection::TestIamPermissions(
    google::iam::v1::TestIamPermissionsRequest const& request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::TestIamPermissions");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->TestIamPermissions(request));
}

StreamRange<google::bigtable::admin::v2::HotTablet>
BigtableInstanceAdminTracingConnection::ListHotTablets(
    google::bigtable::admin::v2::ListHotTabletsRequest request) {
  auto span = internal::MakeSpan(
      "bigtable_admin::BigtableInstanceAdminConnection::ListHotTablets");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListHotTablets(std::move(request));
  return internal::MakeTracedStreamRange<
      google::bigtable::admin::v2::HotTablet>(std::move(span), std::move(sr));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<bigtable_admin::BigtableInstanceAdminConnection>
MakeBigtableInstanceAdminTracingConnection(
    std::shared_ptr<bigtable_admin::BigtableInstanceAdminConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<BigtableInstanceAdminTracingConnection>(
        std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigtable_admin_internal
}  // namespace cloud
}  // namespace google
