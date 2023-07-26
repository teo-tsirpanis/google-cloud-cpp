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
// source: google/cloud/beyondcorp/appconnectors/v1/app_connectors_service.proto

#include "google/cloud/beyondcorp/appconnectors/v1/app_connectors_client.h"
#include "google/cloud/beyondcorp/appconnectors/v1/app_connectors_connection_idempotency_policy.h"
#include "google/cloud/beyondcorp/appconnectors/v1/app_connectors_options.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/internal/getenv.h"
#include "google/cloud/testing_util/example_driver.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// clang-format off
// main-dox-marker: beyondcorp_appconnectors_v1::AppConnectorsServiceClient
// clang-format on
namespace {

void SetClientEndpoint(std::vector<std::string> const& argv) {
  if (!argv.empty()) {
    throw google::cloud::testing_util::Usage{"set-client-endpoint"};
  }
  //! [set-client-endpoint]
  // This configuration is common with Private Google Access:
  //     https://cloud.google.com/vpc/docs/private-google-access
  auto options = google::cloud::Options{}.set<google::cloud::EndpointOption>(
      "private.googleapis.com");
  auto client =
      google::cloud::beyondcorp_appconnectors_v1::AppConnectorsServiceClient(
          google::cloud::beyondcorp_appconnectors_v1::
              MakeAppConnectorsServiceConnection(options));
  //! [set-client-endpoint]
}

//! [custom-idempotency-policy]
class CustomIdempotencyPolicy
    : public google::cloud::beyondcorp_appconnectors_v1::
          AppConnectorsServiceConnectionIdempotencyPolicy {
 public:
  ~CustomIdempotencyPolicy() override = default;
  std::unique_ptr<google::cloud::beyondcorp_appconnectors_v1::
                      AppConnectorsServiceConnectionIdempotencyPolicy>
  clone() const override {
    return std::make_unique<CustomIdempotencyPolicy>(*this);
  }
  // Override inherited functions to define as needed.
};
//! [custom-idempotency-policy]

void SetRetryPolicy(std::vector<std::string> const& argv) {
  if (!argv.empty()) {
    throw google::cloud::testing_util::Usage{"set-client-retry-policy"};
  }
  //! [set-retry-policy]
  auto options =
      google::cloud::Options{}
          .set<google::cloud::beyondcorp_appconnectors_v1::
                   AppConnectorsServiceConnectionIdempotencyPolicyOption>(
              CustomIdempotencyPolicy().clone())
          .set<google::cloud::beyondcorp_appconnectors_v1::
                   AppConnectorsServiceRetryPolicyOption>(
              google::cloud::beyondcorp_appconnectors_v1::
                  AppConnectorsServiceLimitedErrorCountRetryPolicy(3)
                      .clone())
          .set<google::cloud::beyondcorp_appconnectors_v1::
                   AppConnectorsServiceBackoffPolicyOption>(
              google::cloud::ExponentialBackoffPolicy(
                  /*initial_delay=*/std::chrono::milliseconds(200),
                  /*maximum_delay=*/std::chrono::seconds(45),
                  /*scaling=*/2.0)
                  .clone());
  auto connection = google::cloud::beyondcorp_appconnectors_v1::
      MakeAppConnectorsServiceConnection(options);

  // c1 and c2 share the same retry policies
  auto c1 =
      google::cloud::beyondcorp_appconnectors_v1::AppConnectorsServiceClient(
          connection);
  auto c2 =
      google::cloud::beyondcorp_appconnectors_v1::AppConnectorsServiceClient(
          connection);

  // You can override any of the policies in a new client. This new client
  // will share the policies from c1 (or c2) *except* for the retry policy.
  auto c3 =
      google::cloud::beyondcorp_appconnectors_v1::AppConnectorsServiceClient(
          connection, google::cloud::Options{}
                          .set<google::cloud::beyondcorp_appconnectors_v1::
                                   AppConnectorsServiceRetryPolicyOption>(
                              google::cloud::beyondcorp_appconnectors_v1::
                                  AppConnectorsServiceLimitedTimeRetryPolicy(
                                      std::chrono::minutes(5))
                                      .clone()));

  // You can also override the policies in a single call:
  // c3.SomeRpc(..., google::cloud::Options{}
  //     .set<google::cloud::beyondcorp_appconnectors_v1::AppConnectorsServiceRetryPolicyOption>(
  //       google::cloud::beyondcorp_appconnectors_v1::AppConnectorsServiceLimitedErrorCountRetryPolicy(10).clone()));
  //! [set-retry-policy]
}

void WithServiceAccount(std::vector<std::string> const& argv) {
  if (argv.size() != 1 || argv[0] == "--help") {
    throw google::cloud::testing_util::Usage{"with-service-account <keyfile>"};
  }
  //! [with-service-account]
  [](std::string const& keyfile) {
    auto is = std::ifstream(keyfile);
    is.exceptions(std::ios::badbit);  // Minimal error handling in examples
    auto contents = std::string(std::istreambuf_iterator<char>(is.rdbuf()), {});
    auto options =
        google::cloud::Options{}.set<google::cloud::UnifiedCredentialsOption>(
            google::cloud::MakeServiceAccountCredentials(contents));
    return google::cloud::beyondcorp_appconnectors_v1::
        AppConnectorsServiceClient(
            google::cloud::beyondcorp_appconnectors_v1::
                MakeAppConnectorsServiceConnection(options));
  }
  //! [with-service-account]
  (argv.at(0));
}

void AutoRun(std::vector<std::string> const& argv) {
  namespace examples = ::google::cloud::testing_util;
  using ::google::cloud::internal::GetEnv;
  if (!argv.empty()) throw examples::Usage{"auto"};
  examples::CheckEnvironmentVariablesAreSet(
      {"GOOGLE_CLOUD_CPP_TEST_SERVICE_ACCOUNT_KEYFILE"});
  auto const keyfile =
      GetEnv("GOOGLE_CLOUD_CPP_TEST_SERVICE_ACCOUNT_KEYFILE").value();

  std::cout << "\nRunning SetClientEndpoint() example" << std::endl;
  SetClientEndpoint({});

  std::cout << "\nRunning SetRetryPolicy() example" << std::endl;
  SetRetryPolicy({});

  std::cout << "\nRunning WithServiceAccount() example" << std::endl;
  WithServiceAccount({keyfile});
}

}  // namespace

int main(int argc, char* argv[]) {  // NOLINT(bugprone-exception-escape)
  google::cloud::testing_util::Example example({
      {"set-client-endpoint", SetClientEndpoint},
      {"set-retry-policy", SetRetryPolicy},
      {"with-service-account", WithServiceAccount},
      {"auto", AutoRun},
  });
  return example.Run(argc, argv);
}
