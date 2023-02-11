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
// source: google/cloud/managedidentities/v1/managed_identities_service.proto

#include "google/cloud/managedidentities/internal/managed_identities_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace managedidentities_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

ManagedIdentitiesServiceTracingConnection::
    ManagedIdentitiesServiceTracingConnection(
        std::shared_ptr<managedidentities::ManagedIdentitiesServiceConnection>
            child)
    : child_(std::move(child)) {}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceTracingConnection::CreateMicrosoftAdDomain(
    google::cloud::managedidentities::v1::CreateMicrosoftAdDomainRequest const&
        request) {
  return child_->CreateMicrosoftAdDomain(request);
}

StatusOr<google::cloud::managedidentities::v1::ResetAdminPasswordResponse>
ManagedIdentitiesServiceTracingConnection::ResetAdminPassword(
    google::cloud::managedidentities::v1::ResetAdminPasswordRequest const&
        request) {
  auto span = internal::MakeSpan(
      "managedidentities::ManagedIdentitiesServiceConnection::"
      "ResetAdminPassword");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->ResetAdminPassword(request));
}

StreamRange<google::cloud::managedidentities::v1::Domain>
ManagedIdentitiesServiceTracingConnection::ListDomains(
    google::cloud::managedidentities::v1::ListDomainsRequest request) {
  auto span = internal::MakeSpan(
      "managedidentities::ManagedIdentitiesServiceConnection::ListDomains");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListDomains(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::managedidentities::v1::Domain>(std::move(span),
                                                    std::move(sr));
}

StatusOr<google::cloud::managedidentities::v1::Domain>
ManagedIdentitiesServiceTracingConnection::GetDomain(
    google::cloud::managedidentities::v1::GetDomainRequest const& request) {
  auto span = internal::MakeSpan(
      "managedidentities::ManagedIdentitiesServiceConnection::GetDomain");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetDomain(request));
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceTracingConnection::UpdateDomain(
    google::cloud::managedidentities::v1::UpdateDomainRequest const& request) {
  return child_->UpdateDomain(request);
}

future<StatusOr<google::cloud::managedidentities::v1::OpMetadata>>
ManagedIdentitiesServiceTracingConnection::DeleteDomain(
    google::cloud::managedidentities::v1::DeleteDomainRequest const& request) {
  return child_->DeleteDomain(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceTracingConnection::AttachTrust(
    google::cloud::managedidentities::v1::AttachTrustRequest const& request) {
  return child_->AttachTrust(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceTracingConnection::ReconfigureTrust(
    google::cloud::managedidentities::v1::ReconfigureTrustRequest const&
        request) {
  return child_->ReconfigureTrust(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceTracingConnection::DetachTrust(
    google::cloud::managedidentities::v1::DetachTrustRequest const& request) {
  return child_->DetachTrust(request);
}

future<StatusOr<google::cloud::managedidentities::v1::Domain>>
ManagedIdentitiesServiceTracingConnection::ValidateTrust(
    google::cloud::managedidentities::v1::ValidateTrustRequest const& request) {
  return child_->ValidateTrust(request);
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<managedidentities::ManagedIdentitiesServiceConnection>
MakeManagedIdentitiesServiceTracingConnection(
    std::shared_ptr<managedidentities::ManagedIdentitiesServiceConnection>
        conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<ManagedIdentitiesServiceTracingConnection>(
        std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace managedidentities_internal
}  // namespace cloud
}  // namespace google
