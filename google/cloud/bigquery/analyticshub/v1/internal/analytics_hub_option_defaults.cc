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
// source: google/cloud/bigquery/analyticshub/v1/analyticshub.proto

#include "google/cloud/bigquery/analyticshub/v1/internal/analytics_hub_option_defaults.h"
#include "google/cloud/bigquery/analyticshub/v1/analytics_hub_connection.h"
#include "google/cloud/bigquery/analyticshub/v1/analytics_hub_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_analyticshub_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options AnalyticsHubServiceDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_ANALYTICS_HUB_SERVICE_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_ANALYTICS_HUB_SERVICE_AUTHORITY",
      "analyticshub.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<
          bigquery_analyticshub_v1::AnalyticsHubServiceRetryPolicyOption>()) {
    options.set<bigquery_analyticshub_v1::AnalyticsHubServiceRetryPolicyOption>(
        bigquery_analyticshub_v1::AnalyticsHubServiceLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<
          bigquery_analyticshub_v1::AnalyticsHubServiceBackoffPolicyOption>()) {
    options
        .set<bigquery_analyticshub_v1::AnalyticsHubServiceBackoffPolicyOption>(
            ExponentialBackoffPolicy(
                std::chrono::seconds(0), std::chrono::seconds(1),
                std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
                .clone());
  }
  if (!options.has<
          bigquery_analyticshub_v1::AnalyticsHubServicePollingPolicyOption>()) {
    options.set<
        bigquery_analyticshub_v1::AnalyticsHubServicePollingPolicyOption>(
        GenericPollingPolicy<bigquery_analyticshub_v1::
                                 AnalyticsHubServiceRetryPolicyOption::Type,
                             bigquery_analyticshub_v1::
                                 AnalyticsHubServiceBackoffPolicyOption::Type>(
            options
                .get<bigquery_analyticshub_v1::
                         AnalyticsHubServiceRetryPolicyOption>()
                ->clone(),
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone())
            .clone());
  }
  if (!options
           .has<bigquery_analyticshub_v1::
                    AnalyticsHubServiceConnectionIdempotencyPolicyOption>()) {
    options.set<bigquery_analyticshub_v1::
                    AnalyticsHubServiceConnectionIdempotencyPolicyOption>(
        bigquery_analyticshub_v1::
            MakeDefaultAnalyticsHubServiceConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_analyticshub_v1_internal
}  // namespace cloud
}  // namespace google
