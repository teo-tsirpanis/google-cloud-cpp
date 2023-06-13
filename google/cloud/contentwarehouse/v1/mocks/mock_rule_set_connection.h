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
// source: google/cloud/contentwarehouse/v1/ruleset_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTENTWAREHOUSE_V1_MOCKS_MOCK_RULE_SET_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTENTWAREHOUSE_V1_MOCKS_MOCK_RULE_SET_CONNECTION_H

#include "google/cloud/contentwarehouse/v1/rule_set_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace contentwarehouse_v1_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * A class to mock `RuleSetServiceConnection`.
 *
 * Application developers may want to test their code with simulated responses,
 * including errors, from an object of type `RuleSetServiceClient`. To do so,
 * construct an object of type `RuleSetServiceClient` with an instance of this
 * class. Then use the Google Test framework functions to program the behavior
 * of this mock.
 *
 * @see [This example][bq-mock] for how to test your application with GoogleTest.
 * While the example showcases types from the BigQuery library, the underlying
 * principles apply for any pair of `*Client` and `*Connection`.
 *
 * [bq-mock]: @cloud_cpp_docs_link{bigquery,bigquery-read-mock}
 */
class MockRuleSetServiceConnection
    : public contentwarehouse_v1::RuleSetServiceConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(StatusOr<google::cloud::contentwarehouse::v1::RuleSet>,
              CreateRuleSet,
              (google::cloud::contentwarehouse::v1::CreateRuleSetRequest const&
                   request),
              (override));

  MOCK_METHOD(
      StatusOr<google::cloud::contentwarehouse::v1::RuleSet>, GetRuleSet,
      (google::cloud::contentwarehouse::v1::GetRuleSetRequest const& request),
      (override));

  MOCK_METHOD(StatusOr<google::cloud::contentwarehouse::v1::RuleSet>,
              UpdateRuleSet,
              (google::cloud::contentwarehouse::v1::UpdateRuleSetRequest const&
                   request),
              (override));

  MOCK_METHOD(Status, DeleteRuleSet,
              (google::cloud::contentwarehouse::v1::DeleteRuleSetRequest const&
                   request),
              (override));

  MOCK_METHOD(
      StreamRange<google::cloud::contentwarehouse::v1::RuleSet>, ListRuleSets,
      (google::cloud::contentwarehouse::v1::ListRuleSetsRequest request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace contentwarehouse_v1_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTENTWAREHOUSE_V1_MOCKS_MOCK_RULE_SET_CONNECTION_H
