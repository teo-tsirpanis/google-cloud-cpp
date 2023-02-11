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
// source: google/cloud/dataplex/v1/metadata.proto

#include "google/cloud/dataplex/internal/metadata_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace dataplex_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

MetadataServiceTracingConnection::MetadataServiceTracingConnection(
    std::shared_ptr<dataplex::MetadataServiceConnection> child)
    : child_(std::move(child)) {}

StatusOr<google::cloud::dataplex::v1::Entity>
MetadataServiceTracingConnection::CreateEntity(
    google::cloud::dataplex::v1::CreateEntityRequest const& request) {
  auto span =
      internal::MakeSpan("dataplex::MetadataServiceConnection::CreateEntity");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateEntity(request));
}

StatusOr<google::cloud::dataplex::v1::Entity>
MetadataServiceTracingConnection::UpdateEntity(
    google::cloud::dataplex::v1::UpdateEntityRequest const& request) {
  auto span =
      internal::MakeSpan("dataplex::MetadataServiceConnection::UpdateEntity");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateEntity(request));
}

Status MetadataServiceTracingConnection::DeleteEntity(
    google::cloud::dataplex::v1::DeleteEntityRequest const& request) {
  auto span =
      internal::MakeSpan("dataplex::MetadataServiceConnection::DeleteEntity");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteEntity(request));
}

StatusOr<google::cloud::dataplex::v1::Entity>
MetadataServiceTracingConnection::GetEntity(
    google::cloud::dataplex::v1::GetEntityRequest const& request) {
  auto span =
      internal::MakeSpan("dataplex::MetadataServiceConnection::GetEntity");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetEntity(request));
}

StreamRange<google::cloud::dataplex::v1::Entity>
MetadataServiceTracingConnection::ListEntities(
    google::cloud::dataplex::v1::ListEntitiesRequest request) {
  auto span =
      internal::MakeSpan("dataplex::MetadataServiceConnection::ListEntities");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListEntities(std::move(request));
  return internal::MakeTracedStreamRange<google::cloud::dataplex::v1::Entity>(
      std::move(span), std::move(sr));
}

StatusOr<google::cloud::dataplex::v1::Partition>
MetadataServiceTracingConnection::CreatePartition(
    google::cloud::dataplex::v1::CreatePartitionRequest const& request) {
  auto span = internal::MakeSpan(
      "dataplex::MetadataServiceConnection::CreatePartition");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreatePartition(request));
}

Status MetadataServiceTracingConnection::DeletePartition(
    google::cloud::dataplex::v1::DeletePartitionRequest const& request) {
  auto span = internal::MakeSpan(
      "dataplex::MetadataServiceConnection::DeletePartition");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeletePartition(request));
}

StatusOr<google::cloud::dataplex::v1::Partition>
MetadataServiceTracingConnection::GetPartition(
    google::cloud::dataplex::v1::GetPartitionRequest const& request) {
  auto span =
      internal::MakeSpan("dataplex::MetadataServiceConnection::GetPartition");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetPartition(request));
}

StreamRange<google::cloud::dataplex::v1::Partition>
MetadataServiceTracingConnection::ListPartitions(
    google::cloud::dataplex::v1::ListPartitionsRequest request) {
  auto span =
      internal::MakeSpan("dataplex::MetadataServiceConnection::ListPartitions");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListPartitions(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::dataplex::v1::Partition>(std::move(span), std::move(sr));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<dataplex::MetadataServiceConnection>
MakeMetadataServiceTracingConnection(
    std::shared_ptr<dataplex::MetadataServiceConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<MetadataServiceTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataplex_internal
}  // namespace cloud
}  // namespace google
