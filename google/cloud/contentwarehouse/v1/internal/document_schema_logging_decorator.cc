// Copyright 2023 Google LLC
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
// source: google/cloud/contentwarehouse/v1/document_schema_service.proto

#include "google/cloud/contentwarehouse/v1/internal/document_schema_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/contentwarehouse/v1/document_schema_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace contentwarehouse_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DocumentSchemaServiceLogging::DocumentSchemaServiceLogging(
    std::shared_ptr<DocumentSchemaServiceStub> child,
    TracingOptions tracing_options, std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::contentwarehouse::v1::DocumentSchema>
DocumentSchemaServiceLogging::CreateDocumentSchema(
    grpc::ClientContext& context,
    google::cloud::contentwarehouse::v1::CreateDocumentSchemaRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::contentwarehouse::v1::
                 CreateDocumentSchemaRequest const& request) {
        return child_->CreateDocumentSchema(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::contentwarehouse::v1::DocumentSchema>
DocumentSchemaServiceLogging::UpdateDocumentSchema(
    grpc::ClientContext& context,
    google::cloud::contentwarehouse::v1::UpdateDocumentSchemaRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::contentwarehouse::v1::
                 UpdateDocumentSchemaRequest const& request) {
        return child_->UpdateDocumentSchema(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::contentwarehouse::v1::DocumentSchema>
DocumentSchemaServiceLogging::GetDocumentSchema(
    grpc::ClientContext& context,
    google::cloud::contentwarehouse::v1::GetDocumentSchemaRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::contentwarehouse::v1::GetDocumentSchemaRequest const&
              request) { return child_->GetDocumentSchema(context, request); },
      context, request, __func__, tracing_options_);
}

Status DocumentSchemaServiceLogging::DeleteDocumentSchema(
    grpc::ClientContext& context,
    google::cloud::contentwarehouse::v1::DeleteDocumentSchemaRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::contentwarehouse::v1::
                 DeleteDocumentSchemaRequest const& request) {
        return child_->DeleteDocumentSchema(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::contentwarehouse::v1::ListDocumentSchemasResponse>
DocumentSchemaServiceLogging::ListDocumentSchemas(
    grpc::ClientContext& context,
    google::cloud::contentwarehouse::v1::ListDocumentSchemasRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::contentwarehouse::v1::ListDocumentSchemasRequest const&
              request) {
        return child_->ListDocumentSchemas(context, request);
      },
      context, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace contentwarehouse_v1_internal
}  // namespace cloud
}  // namespace google
