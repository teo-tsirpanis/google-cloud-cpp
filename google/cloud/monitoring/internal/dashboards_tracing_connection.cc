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
// source: google/monitoring/dashboard/v1/dashboards_service.proto

#include "google/cloud/monitoring/internal/dashboards_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

DashboardsServiceTracingConnection::DashboardsServiceTracingConnection(
    std::shared_ptr<monitoring::DashboardsServiceConnection> child)
    : child_(std::move(child)) {}

StatusOr<google::monitoring::dashboard::v1::Dashboard>
DashboardsServiceTracingConnection::CreateDashboard(
    google::monitoring::dashboard::v1::CreateDashboardRequest const& request) {
  auto span = internal::MakeSpan(
      "monitoring::DashboardsServiceConnection::CreateDashboard");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateDashboard(request));
}

StreamRange<google::monitoring::dashboard::v1::Dashboard>
DashboardsServiceTracingConnection::ListDashboards(
    google::monitoring::dashboard::v1::ListDashboardsRequest request) {
  auto span = internal::MakeSpan(
      "monitoring::DashboardsServiceConnection::ListDashboards");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListDashboards(std::move(request));
  return internal::MakeTracedStreamRange<
      google::monitoring::dashboard::v1::Dashboard>(std::move(span),
                                                    std::move(sr));
}

StatusOr<google::monitoring::dashboard::v1::Dashboard>
DashboardsServiceTracingConnection::GetDashboard(
    google::monitoring::dashboard::v1::GetDashboardRequest const& request) {
  auto span = internal::MakeSpan(
      "monitoring::DashboardsServiceConnection::GetDashboard");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetDashboard(request));
}

Status DashboardsServiceTracingConnection::DeleteDashboard(
    google::monitoring::dashboard::v1::DeleteDashboardRequest const& request) {
  auto span = internal::MakeSpan(
      "monitoring::DashboardsServiceConnection::DeleteDashboard");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteDashboard(request));
}

StatusOr<google::monitoring::dashboard::v1::Dashboard>
DashboardsServiceTracingConnection::UpdateDashboard(
    google::monitoring::dashboard::v1::UpdateDashboardRequest const& request) {
  auto span = internal::MakeSpan(
      "monitoring::DashboardsServiceConnection::UpdateDashboard");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateDashboard(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<monitoring::DashboardsServiceConnection>
MakeDashboardsServiceTracingConnection(
    std::shared_ptr<monitoring::DashboardsServiceConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn =
        std::make_shared<DashboardsServiceTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google
