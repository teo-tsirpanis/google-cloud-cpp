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
// source: google/cloud/vision/v1/product_search_service.proto

#include "google/cloud/vision/v1/internal/product_search_auth_decorator.h"
#include <google/cloud/vision/v1/product_search_service.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace vision_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ProductSearchAuth::ProductSearchAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<ProductSearchStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::vision::v1::ProductSet>
ProductSearchAuth::CreateProductSet(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::CreateProductSetRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateProductSet(context, options, request);
}

StatusOr<google::cloud::vision::v1::ListProductSetsResponse>
ProductSearchAuth::ListProductSets(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::ListProductSetsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListProductSets(context, options, request);
}

StatusOr<google::cloud::vision::v1::ProductSet>
ProductSearchAuth::GetProductSet(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::GetProductSetRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetProductSet(context, options, request);
}

StatusOr<google::cloud::vision::v1::ProductSet>
ProductSearchAuth::UpdateProductSet(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::UpdateProductSetRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateProductSet(context, options, request);
}

Status ProductSearchAuth::DeleteProductSet(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::DeleteProductSetRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteProductSet(context, options, request);
}

StatusOr<google::cloud::vision::v1::Product> ProductSearchAuth::CreateProduct(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::CreateProductRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateProduct(context, options, request);
}

StatusOr<google::cloud::vision::v1::ListProductsResponse>
ProductSearchAuth::ListProducts(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::ListProductsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListProducts(context, options, request);
}

StatusOr<google::cloud::vision::v1::Product> ProductSearchAuth::GetProduct(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::GetProductRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetProduct(context, options, request);
}

StatusOr<google::cloud::vision::v1::Product> ProductSearchAuth::UpdateProduct(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::UpdateProductRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateProduct(context, options, request);
}

Status ProductSearchAuth::DeleteProduct(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::DeleteProductRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteProduct(context, options, request);
}

StatusOr<google::cloud::vision::v1::ReferenceImage>
ProductSearchAuth::CreateReferenceImage(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::CreateReferenceImageRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateReferenceImage(context, options, request);
}

Status ProductSearchAuth::DeleteReferenceImage(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::DeleteReferenceImageRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteReferenceImage(context, options, request);
}

StatusOr<google::cloud::vision::v1::ListReferenceImagesResponse>
ProductSearchAuth::ListReferenceImages(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::ListReferenceImagesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListReferenceImages(context, options, request);
}

StatusOr<google::cloud::vision::v1::ReferenceImage>
ProductSearchAuth::GetReferenceImage(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::GetReferenceImageRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetReferenceImage(context, options, request);
}

Status ProductSearchAuth::AddProductToProductSet(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::AddProductToProductSetRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->AddProductToProductSet(context, options, request);
}

Status ProductSearchAuth::RemoveProductFromProductSet(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::RemoveProductFromProductSetRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->RemoveProductFromProductSet(context, options, request);
}

StatusOr<google::cloud::vision::v1::ListProductsInProductSetResponse>
ProductSearchAuth::ListProductsInProductSet(
    grpc::ClientContext& context, Options const& options,
    google::cloud::vision::v1::ListProductsInProductSetRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListProductsInProductSet(context, options, request);
}

future<StatusOr<google::longrunning::Operation>>
ProductSearchAuth::AsyncImportProductSets(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::vision::v1::ImportProductSetsRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncImportProductSets(cq, *std::move(context),
                                             std::move(options), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
ProductSearchAuth::AsyncPurgeProducts(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::cloud::vision::v1::PurgeProductsRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncPurgeProducts(cq, *std::move(context),
                                         std::move(options), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
ProductSearchAuth::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::GetOperationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncGetOperation(cq, *std::move(context),
                                        std::move(options), request);
      });
}

future<Status> ProductSearchAuth::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::internal::ImmutableOptions options,
    google::longrunning::CancelOperationRequest const& request) {
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child = child_, options = std::move(options),
             request](future<StatusOr<std::shared_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) return make_ready_future(std::move(context).status());
        return child->AsyncCancelOperation(cq, *std::move(context),
                                           std::move(options), request);
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace vision_v1_internal
}  // namespace cloud
}  // namespace google
