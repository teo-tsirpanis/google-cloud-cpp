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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTENTWAREHOUSE_V1_INTERNAL_DOCUMENT_SCHEMA_AUTH_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTENTWAREHOUSE_V1_INTERNAL_DOCUMENT_SCHEMA_AUTH_DECORATOR_H

#include "google/cloud/contentwarehouse/v1/internal/document_schema_stub.h"
#include "google/cloud/internal/unified_grpc_credentials.h"
#include "google/cloud/version.h"
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace contentwarehouse_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class DocumentSchemaServiceAuth : public DocumentSchemaServiceStub {
 public:
  ~DocumentSchemaServiceAuth() override = default;
  DocumentSchemaServiceAuth(
      std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
      std::shared_ptr<DocumentSchemaServiceStub> child);

  StatusOr<google::cloud::contentwarehouse::v1::DocumentSchema>
  CreateDocumentSchema(
      grpc::ClientContext& context,
      google::cloud::contentwarehouse::v1::CreateDocumentSchemaRequest const&
          request) override;

  StatusOr<google::cloud::contentwarehouse::v1::DocumentSchema>
  UpdateDocumentSchema(
      grpc::ClientContext& context,
      google::cloud::contentwarehouse::v1::UpdateDocumentSchemaRequest const&
          request) override;

  StatusOr<google::cloud::contentwarehouse::v1::DocumentSchema>
  GetDocumentSchema(
      grpc::ClientContext& context,
      google::cloud::contentwarehouse::v1::GetDocumentSchemaRequest const&
          request) override;

  Status DeleteDocumentSchema(
      grpc::ClientContext& context,
      google::cloud::contentwarehouse::v1::DeleteDocumentSchemaRequest const&
          request) override;

  StatusOr<google::cloud::contentwarehouse::v1::ListDocumentSchemasResponse>
  ListDocumentSchemas(
      grpc::ClientContext& context,
      google::cloud::contentwarehouse::v1::ListDocumentSchemasRequest const&
          request) override;

 private:
  std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth_;
  std::shared_ptr<DocumentSchemaServiceStub> child_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace contentwarehouse_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTENTWAREHOUSE_V1_INTERNAL_DOCUMENT_SCHEMA_AUTH_DECORATOR_H
