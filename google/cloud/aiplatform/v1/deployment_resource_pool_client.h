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
// source: google/cloud/aiplatform/v1/deployment_resource_pool_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_DEPLOYMENT_RESOURCE_POOL_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_DEPLOYMENT_RESOURCE_POOL_CLIENT_H

#include "google/cloud/aiplatform/v1/deployment_resource_pool_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace aiplatform_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// A service that manages the DeploymentResourcePool resource.
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class DeploymentResourcePoolServiceClient {
 public:
  explicit DeploymentResourcePoolServiceClient(
      std::shared_ptr<DeploymentResourcePoolServiceConnection> connection,
      Options opts = {});
  ~DeploymentResourcePoolServiceClient();

  ///@{
  /// @name Copy and move support
  DeploymentResourcePoolServiceClient(
      DeploymentResourcePoolServiceClient const&) = default;
  DeploymentResourcePoolServiceClient& operator=(
      DeploymentResourcePoolServiceClient const&) = default;
  DeploymentResourcePoolServiceClient(DeploymentResourcePoolServiceClient&&) =
      default;
  DeploymentResourcePoolServiceClient& operator=(
      DeploymentResourcePoolServiceClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(DeploymentResourcePoolServiceClient const& a,
                         DeploymentResourcePoolServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(DeploymentResourcePoolServiceClient const& a,
                         DeploymentResourcePoolServiceClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Create a DeploymentResourcePool.
  ///
  /// @param parent  Required. The parent location resource where this DeploymentResourcePool
  ///  will be created. Format: `projects/{project}/locations/{location}`
  /// @param deployment_resource_pool  Required. The DeploymentResourcePool to create.
  /// @param deployment_resource_pool_id  Required. The ID to use for the DeploymentResourcePool, which
  ///  will become the final component of the DeploymentResourcePool's resource
  ///  name.
  ///  @n
  ///  The maximum length is 63 characters, and valid characters
  ///  are `/^[a-z]([a-z0-9-]{0,61}[a-z0-9])?$/`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return A [`future`] that becomes satisfied when the LRO
  ///     ([Long Running Operation]) completes or the polling policy in effect
  ///     for this call is exhausted. The future is satisfied with an error if
  ///     the LRO completes with an error or the polling policy is exhausted.
  ///     In this case the [`StatusOr`] returned by the future contains the
  ///     error. If the LRO completes successfully the value of the future
  ///     contains the LRO's result. For this RPC the result is a
  ///     [google.cloud.aiplatform.v1.DeploymentResourcePool] proto message.
  ///     The C++ class representing this message is created by Protobuf, using
  ///     the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.aiplatform.v1.CreateDeploymentResourcePoolRequest]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool_service.proto#L101}
  /// [google.cloud.aiplatform.v1.DeploymentResourcePool]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool.proto#L34}
  ///
  // clang-format on
  future<StatusOr<google::cloud::aiplatform::v1::DeploymentResourcePool>>
  CreateDeploymentResourcePool(
      std::string const& parent,
      google::cloud::aiplatform::v1::DeploymentResourcePool const&
          deployment_resource_pool,
      std::string const& deployment_resource_pool_id, Options opts = {});

  // clang-format off
  ///
  /// Create a DeploymentResourcePool.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.aiplatform.v1.CreateDeploymentResourcePoolRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return A [`future`] that becomes satisfied when the LRO
  ///     ([Long Running Operation]) completes or the polling policy in effect
  ///     for this call is exhausted. The future is satisfied with an error if
  ///     the LRO completes with an error or the polling policy is exhausted.
  ///     In this case the [`StatusOr`] returned by the future contains the
  ///     error. If the LRO completes successfully the value of the future
  ///     contains the LRO's result. For this RPC the result is a
  ///     [google.cloud.aiplatform.v1.DeploymentResourcePool] proto message.
  ///     The C++ class representing this message is created by Protobuf, using
  ///     the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.aiplatform.v1.CreateDeploymentResourcePoolRequest]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool_service.proto#L101}
  /// [google.cloud.aiplatform.v1.DeploymentResourcePool]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool.proto#L34}
  ///
  // clang-format on
  future<StatusOr<google::cloud::aiplatform::v1::DeploymentResourcePool>>
  CreateDeploymentResourcePool(
      google::cloud::aiplatform::v1::CreateDeploymentResourcePoolRequest const&
          request,
      Options opts = {});

  // clang-format off
  ///
  /// Get a DeploymentResourcePool.
  ///
  /// @param name  Required. The name of the DeploymentResourcePool to retrieve.
  ///  Format:
  ///  `projects/{project}/locations/{location}/deploymentResourcePools/{deployment_resource_pool}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.aiplatform.v1.DeploymentResourcePool])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.aiplatform.v1.DeploymentResourcePool]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool.proto#L34}
  /// [google.cloud.aiplatform.v1.GetDeploymentResourcePoolRequest]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool_service.proto#L132}
  ///
  // clang-format on
  StatusOr<google::cloud::aiplatform::v1::DeploymentResourcePool>
  GetDeploymentResourcePool(std::string const& name, Options opts = {});

  // clang-format off
  ///
  /// Get a DeploymentResourcePool.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.aiplatform.v1.GetDeploymentResourcePoolRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.aiplatform.v1.DeploymentResourcePool])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.aiplatform.v1.DeploymentResourcePool]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool.proto#L34}
  /// [google.cloud.aiplatform.v1.GetDeploymentResourcePoolRequest]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool_service.proto#L132}
  ///
  // clang-format on
  StatusOr<google::cloud::aiplatform::v1::DeploymentResourcePool>
  GetDeploymentResourcePool(
      google::cloud::aiplatform::v1::GetDeploymentResourcePoolRequest const&
          request,
      Options opts = {});

  // clang-format off
  ///
  /// List DeploymentResourcePools in a location.
  ///
  /// @param parent  Required. The parent Location which owns this collection of
  ///  DeploymentResourcePools. Format: `projects/{project}/locations/{location}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [StreamRange](@ref google::cloud::StreamRange)
  ///     to iterate of the results. See the documentation of this type for
  ///     details. In brief, this class has `begin()` and `end()` member
  ///     functions returning a iterator class meeting the
  ///     [input iterator requirements]. The value type for this iterator is a
  ///     [`StatusOr`] as the iteration may fail even after some values are
  ///     retrieved successfully, for example, if there is a network disconnect.
  ///     An empty set of results does not indicate an error, it indicates
  ///     that there are no resources meeting the request criteria.
  ///     On a successful iteration the `StatusOr<T>` contains elements of type
  ///     [google.cloud.aiplatform.v1.DeploymentResourcePool], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.aiplatform.v1.DeploymentResourcePool]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool.proto#L34}
  /// [google.cloud.aiplatform.v1.ListDeploymentResourcePoolsRequest]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool_service.proto#L145}
  ///
  // clang-format on
  StreamRange<google::cloud::aiplatform::v1::DeploymentResourcePool>
  ListDeploymentResourcePools(std::string const& parent, Options opts = {});

  // clang-format off
  ///
  /// List DeploymentResourcePools in a location.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.aiplatform.v1.ListDeploymentResourcePoolsRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [StreamRange](@ref google::cloud::StreamRange)
  ///     to iterate of the results. See the documentation of this type for
  ///     details. In brief, this class has `begin()` and `end()` member
  ///     functions returning a iterator class meeting the
  ///     [input iterator requirements]. The value type for this iterator is a
  ///     [`StatusOr`] as the iteration may fail even after some values are
  ///     retrieved successfully, for example, if there is a network disconnect.
  ///     An empty set of results does not indicate an error, it indicates
  ///     that there are no resources meeting the request criteria.
  ///     On a successful iteration the `StatusOr<T>` contains elements of type
  ///     [google.cloud.aiplatform.v1.DeploymentResourcePool], or rather,
  ///     the C++ class generated by Protobuf from that type. Please consult the
  ///     Protobuf documentation for details on the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.aiplatform.v1.DeploymentResourcePool]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool.proto#L34}
  /// [google.cloud.aiplatform.v1.ListDeploymentResourcePoolsRequest]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool_service.proto#L145}
  ///
  // clang-format on
  StreamRange<google::cloud::aiplatform::v1::DeploymentResourcePool>
  ListDeploymentResourcePools(
      google::cloud::aiplatform::v1::ListDeploymentResourcePoolsRequest request,
      Options opts = {});

  // clang-format off
  ///
  /// Delete a DeploymentResourcePool.
  ///
  /// @param name  Required. The name of the DeploymentResourcePool to delete.
  ///  Format:
  ///  `projects/{project}/locations/{location}/deploymentResourcePools/{deployment_resource_pool}`
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return A [`future`] that becomes satisfied when the LRO
  ///     ([Long Running Operation]) completes or the polling policy in effect
  ///     for this call is exhausted. The future is satisfied with an error if
  ///     the LRO completes with an error or the polling policy is exhausted.
  ///     In this case the [`StatusOr`] returned by the future contains the
  ///     error. If the LRO completes successfully the value of the future
  ///     contains the LRO's result. For this RPC the result is a
  ///     [google.cloud.aiplatform.v1.DeleteOperationMetadata] proto message.
  ///     The C++ class representing this message is created by Protobuf, using
  ///     the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.aiplatform.v1.DeleteDeploymentResourcePoolRequest]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool_service.proto#L185}
  /// [google.cloud.aiplatform.v1.DeleteOperationMetadata]: @googleapis_reference_link{google/cloud/aiplatform/v1/operation.proto#L52}
  ///
  // clang-format on
  future<StatusOr<google::cloud::aiplatform::v1::DeleteOperationMetadata>>
  DeleteDeploymentResourcePool(std::string const& name, Options opts = {});

  // clang-format off
  ///
  /// Delete a DeploymentResourcePool.
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.aiplatform.v1.DeleteDeploymentResourcePoolRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return A [`future`] that becomes satisfied when the LRO
  ///     ([Long Running Operation]) completes or the polling policy in effect
  ///     for this call is exhausted. The future is satisfied with an error if
  ///     the LRO completes with an error or the polling policy is exhausted.
  ///     In this case the [`StatusOr`] returned by the future contains the
  ///     error. If the LRO completes successfully the value of the future
  ///     contains the LRO's result. For this RPC the result is a
  ///     [google.cloud.aiplatform.v1.DeleteOperationMetadata] proto message.
  ///     The C++ class representing this message is created by Protobuf, using
  ///     the [Protobuf mapping rules].
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [Long Running Operation]: https://google.aip.dev/151
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.aiplatform.v1.DeleteDeploymentResourcePoolRequest]: @googleapis_reference_link{google/cloud/aiplatform/v1/deployment_resource_pool_service.proto#L185}
  /// [google.cloud.aiplatform.v1.DeleteOperationMetadata]: @googleapis_reference_link{google/cloud/aiplatform/v1/operation.proto#L52}
  ///
  // clang-format on
  future<StatusOr<google::cloud::aiplatform::v1::DeleteOperationMetadata>>
  DeleteDeploymentResourcePool(
      google::cloud::aiplatform::v1::DeleteDeploymentResourcePoolRequest const&
          request,
      Options opts = {});

 private:
  std::shared_ptr<DeploymentResourcePoolServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_DEPLOYMENT_RESOURCE_POOL_CLIENT_H
