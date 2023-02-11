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
// source: google/cloud/batch/v1/batch.proto

#include "google/cloud/batch/internal/batch_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace batch_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

BatchServiceTracingConnection::BatchServiceTracingConnection(
    std::shared_ptr<batch::BatchServiceConnection> child)
    : child_(std::move(child)) {}

StatusOr<google::cloud::batch::v1::Job>
BatchServiceTracingConnection::CreateJob(
    google::cloud::batch::v1::CreateJobRequest const& request) {
  auto span = internal::MakeSpan("batch::BatchServiceConnection::CreateJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateJob(request));
}

StatusOr<google::cloud::batch::v1::Job> BatchServiceTracingConnection::GetJob(
    google::cloud::batch::v1::GetJobRequest const& request) {
  auto span = internal::MakeSpan("batch::BatchServiceConnection::GetJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetJob(request));
}

future<StatusOr<google::cloud::batch::v1::OperationMetadata>>
BatchServiceTracingConnection::DeleteJob(
    google::cloud::batch::v1::DeleteJobRequest const& request) {
  return child_->DeleteJob(request);
}

StreamRange<google::cloud::batch::v1::Job>
BatchServiceTracingConnection::ListJobs(
    google::cloud::batch::v1::ListJobsRequest request) {
  auto span = internal::MakeSpan("batch::BatchServiceConnection::ListJobs");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListJobs(std::move(request));
  return internal::MakeTracedStreamRange<google::cloud::batch::v1::Job>(
      std::move(span), std::move(sr));
}

StatusOr<google::cloud::batch::v1::Task> BatchServiceTracingConnection::GetTask(
    google::cloud::batch::v1::GetTaskRequest const& request) {
  auto span = internal::MakeSpan("batch::BatchServiceConnection::GetTask");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetTask(request));
}

StreamRange<google::cloud::batch::v1::Task>
BatchServiceTracingConnection::ListTasks(
    google::cloud::batch::v1::ListTasksRequest request) {
  auto span = internal::MakeSpan("batch::BatchServiceConnection::ListTasks");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListTasks(std::move(request));
  return internal::MakeTracedStreamRange<google::cloud::batch::v1::Task>(
      std::move(span), std::move(sr));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<batch::BatchServiceConnection>
MakeBatchServiceTracingConnection(
    std::shared_ptr<batch::BatchServiceConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<BatchServiceTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace batch_internal
}  // namespace cloud
}  // namespace google
