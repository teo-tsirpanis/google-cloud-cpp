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
// source: google/cloud/billing/v1/cloud_catalog.proto

#include "google/cloud/billing/internal/cloud_catalog_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace billing_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

CloudCatalogTracingConnection::CloudCatalogTracingConnection(
    std::shared_ptr<billing::CloudCatalogConnection> child)
    : child_(std::move(child)) {}

StreamRange<google::cloud::billing::v1::Service>
CloudCatalogTracingConnection::ListServices(
    google::cloud::billing::v1::ListServicesRequest request) {
  auto span =
      internal::MakeSpan("billing::CloudCatalogConnection::ListServices");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListServices(std::move(request));
  return internal::MakeTracedStreamRange<google::cloud::billing::v1::Service>(
      std::move(span), std::move(sr));
}

StreamRange<google::cloud::billing::v1::Sku>
CloudCatalogTracingConnection::ListSkus(
    google::cloud::billing::v1::ListSkusRequest request) {
  auto span = internal::MakeSpan("billing::CloudCatalogConnection::ListSkus");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListSkus(std::move(request));
  return internal::MakeTracedStreamRange<google::cloud::billing::v1::Sku>(
      std::move(span), std::move(sr));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<billing::CloudCatalogConnection>
MakeCloudCatalogTracingConnection(
    std::shared_ptr<billing::CloudCatalogConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<CloudCatalogTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace billing_internal
}  // namespace cloud
}  // namespace google
