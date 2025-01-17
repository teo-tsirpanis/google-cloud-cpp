// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/internal/grpc_request_metadata.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/absl_str_join_quiet.h"
#include <grpcpp/grpcpp.h>

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {
namespace {
// AFAICT there is no C++ API to get the name, but the C core API is public and
// documented:
//    https://grpc.github.io/grpc/core/compression_8h.html
std::string ToString(grpc_compression_algorithm algo) {
  char const* name;
  if (grpc_compression_algorithm_name(algo, &name) == 0) {
    return "unknown";
  }
  return name;
}
}  // namespace

RpcMetadata GetRequestMetadataFromContext(grpc::ClientContext const& context) {
  RpcMetadata metadata{
      /*.headers=*/{
          // Use invalid header names (starting with ':') to store the
          // grpc::ClientContext metadata.
          {":grpc-context-peer", context.peer()},
          {":grpc-context-compression-algorithm",
           ToString(context.compression_algorithm())},

      },
      /*.trailers=*/{},
  };
  auto hint = metadata.headers.end();
  for (auto const& kv : context.GetServerInitialMetadata()) {
    // gRPC metadata is stored in `grpc::string_ref`, a type inspired by
    // `std::string_view`. We need to explicitly convert these to `std::string`.
    // In addition, we use a prefix to distinguish initial vs. trailing headers.
    auto key = std::string{kv.first.data(), kv.first.size()};
    auto value = std::string{kv.second.data(), kv.second.size()};
    hint = std::next(
        metadata.headers.emplace_hint(hint, std::move(key), std::move(value)));
  }
  hint = metadata.trailers.end();
  for (auto const& kv : context.GetServerTrailingMetadata()) {
    // Same as above, convert `grpc::string_ref` to `std::string`:
    auto key = std::string{kv.first.data(), kv.first.size()};
    auto value = std::string{kv.second.data(), kv.second.size()};
    hint = std::next(
        metadata.trailers.emplace_hint(hint, std::move(key), std::move(value)));
  }
  return metadata;
}

std::string FormatForLoggingDecorator(RpcMetadata const& metadata) {
  auto formatter = [](std::string* output, auto const& p) {
    *output += absl::StrCat("{", p.first, ": ", p.second, "}");
  };
  return absl::StrCat("headers={",
                      absl::StrJoin(metadata.headers.begin(),
                                    metadata.headers.end(), ", ", formatter),
                      "}, trailers={",
                      absl::StrJoin(metadata.trailers.begin(),
                                    metadata.trailers.end(), ", ", formatter),
                      "}");
}

}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google
