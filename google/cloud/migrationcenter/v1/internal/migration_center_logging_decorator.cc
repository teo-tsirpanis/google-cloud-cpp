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
// source: google/cloud/migrationcenter/v1/migrationcenter.proto

#include "google/cloud/migrationcenter/v1/internal/migration_center_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/migrationcenter/v1/migrationcenter.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace migrationcenter_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

MigrationCenterLogging::MigrationCenterLogging(
    std::shared_ptr<MigrationCenterStub> child, TracingOptions tracing_options,
    std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::migrationcenter::v1::ListAssetsResponse>
MigrationCenterLogging::ListAssets(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::ListAssetsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::ListAssetsRequest const&
                 request) { return child_->ListAssets(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::Asset>
MigrationCenterLogging::GetAsset(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::GetAssetRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::migrationcenter::v1::GetAssetRequest const& request) {
        return child_->GetAsset(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::Asset>
MigrationCenterLogging::UpdateAsset(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::UpdateAssetRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::UpdateAssetRequest const&
                 request) { return child_->UpdateAsset(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::BatchUpdateAssetsResponse>
MigrationCenterLogging::BatchUpdateAssets(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::BatchUpdateAssetsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::BatchUpdateAssetsRequest const&
                 request) {
        return child_->BatchUpdateAssets(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status MigrationCenterLogging::DeleteAsset(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::DeleteAssetRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::DeleteAssetRequest const&
                 request) { return child_->DeleteAsset(context, request); },
      context, request, __func__, tracing_options_);
}

Status MigrationCenterLogging::BatchDeleteAssets(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::BatchDeleteAssetsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::BatchDeleteAssetsRequest const&
                 request) {
        return child_->BatchDeleteAssets(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ReportAssetFramesResponse>
MigrationCenterLogging::ReportAssetFrames(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::ReportAssetFramesRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::ReportAssetFramesRequest const&
                 request) {
        return child_->ReportAssetFrames(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::AggregateAssetsValuesResponse>
MigrationCenterLogging::AggregateAssetsValues(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::AggregateAssetsValuesRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::
                 AggregateAssetsValuesRequest const& request) {
        return child_->AggregateAssetsValues(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncCreateImportJob(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::CreateImportJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::CreateImportJobRequest const&
                 request) {
        return child_->AsyncCreateImportJob(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ListImportJobsResponse>
MigrationCenterLogging::ListImportJobs(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::ListImportJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::ListImportJobsRequest const&
                 request) { return child_->ListImportJobs(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ImportJob>
MigrationCenterLogging::GetImportJob(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::GetImportJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::GetImportJobRequest const&
                 request) { return child_->GetImportJob(context, request); },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncDeleteImportJob(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::DeleteImportJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::DeleteImportJobRequest const&
                 request) {
        return child_->AsyncDeleteImportJob(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncUpdateImportJob(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::UpdateImportJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::UpdateImportJobRequest const&
                 request) {
        return child_->AsyncUpdateImportJob(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncValidateImportJob(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::ValidateImportJobRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::ValidateImportJobRequest const&
                 request) {
        return child_->AsyncValidateImportJob(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncRunImportJob(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::RunImportJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::RunImportJobRequest const&
                 request) {
        return child_->AsyncRunImportJob(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ImportDataFile>
MigrationCenterLogging::GetImportDataFile(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::GetImportDataFileRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::GetImportDataFileRequest const&
                 request) {
        return child_->GetImportDataFile(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ListImportDataFilesResponse>
MigrationCenterLogging::ListImportDataFiles(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::ListImportDataFilesRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::migrationcenter::v1::ListImportDataFilesRequest const&
              request) {
        return child_->ListImportDataFiles(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncCreateImportDataFile(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::CreateImportDataFileRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::migrationcenter::v1::CreateImportDataFileRequest const&
              request) {
        return child_->AsyncCreateImportDataFile(cq, std::move(context),
                                                 request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncDeleteImportDataFile(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::DeleteImportDataFileRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::migrationcenter::v1::DeleteImportDataFileRequest const&
              request) {
        return child_->AsyncDeleteImportDataFile(cq, std::move(context),
                                                 request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ListGroupsResponse>
MigrationCenterLogging::ListGroups(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::ListGroupsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::ListGroupsRequest const&
                 request) { return child_->ListGroups(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::Group>
MigrationCenterLogging::GetGroup(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::GetGroupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::migrationcenter::v1::GetGroupRequest const& request) {
        return child_->GetGroup(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncCreateGroup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::CreateGroupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::CreateGroupRequest const&
                 request) {
        return child_->AsyncCreateGroup(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncUpdateGroup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::UpdateGroupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::UpdateGroupRequest const&
                 request) {
        return child_->AsyncUpdateGroup(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncDeleteGroup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::DeleteGroupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::DeleteGroupRequest const&
                 request) {
        return child_->AsyncDeleteGroup(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncAddAssetsToGroup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::AddAssetsToGroupRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::AddAssetsToGroupRequest const&
                 request) {
        return child_->AsyncAddAssetsToGroup(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncRemoveAssetsFromGroup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::RemoveAssetsFromGroupRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::
                 RemoveAssetsFromGroupRequest const& request) {
        return child_->AsyncRemoveAssetsFromGroup(cq, std::move(context),
                                                  request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ListErrorFramesResponse>
MigrationCenterLogging::ListErrorFrames(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::ListErrorFramesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::ListErrorFramesRequest const&
                 request) { return child_->ListErrorFrames(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ErrorFrame>
MigrationCenterLogging::GetErrorFrame(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::GetErrorFrameRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::GetErrorFrameRequest const&
                 request) { return child_->GetErrorFrame(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ListSourcesResponse>
MigrationCenterLogging::ListSources(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::ListSourcesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::ListSourcesRequest const&
                 request) { return child_->ListSources(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::Source>
MigrationCenterLogging::GetSource(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::GetSourceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::migrationcenter::v1::GetSourceRequest const& request) {
        return child_->GetSource(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncCreateSource(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::CreateSourceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::CreateSourceRequest const&
                 request) {
        return child_->AsyncCreateSource(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncUpdateSource(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::UpdateSourceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::UpdateSourceRequest const&
                 request) {
        return child_->AsyncUpdateSource(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncDeleteSource(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::DeleteSourceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::DeleteSourceRequest const&
                 request) {
        return child_->AsyncDeleteSource(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ListPreferenceSetsResponse>
MigrationCenterLogging::ListPreferenceSets(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::ListPreferenceSetsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::migrationcenter::v1::ListPreferenceSetsRequest const&
              request) { return child_->ListPreferenceSets(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::PreferenceSet>
MigrationCenterLogging::GetPreferenceSet(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::GetPreferenceSetRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::GetPreferenceSetRequest const&
                 request) {
        return child_->GetPreferenceSet(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncCreatePreferenceSet(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::CreatePreferenceSetRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::migrationcenter::v1::CreatePreferenceSetRequest const&
              request) {
        return child_->AsyncCreatePreferenceSet(cq, std::move(context),
                                                request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncUpdatePreferenceSet(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::UpdatePreferenceSetRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::migrationcenter::v1::UpdatePreferenceSetRequest const&
              request) {
        return child_->AsyncUpdatePreferenceSet(cq, std::move(context),
                                                request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncDeletePreferenceSet(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::DeletePreferenceSetRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::migrationcenter::v1::DeletePreferenceSetRequest const&
              request) {
        return child_->AsyncDeletePreferenceSet(cq, std::move(context),
                                                request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::Settings>
MigrationCenterLogging::GetSettings(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::GetSettingsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::GetSettingsRequest const&
                 request) { return child_->GetSettings(context, request); },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncUpdateSettings(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::UpdateSettingsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::UpdateSettingsRequest const&
                 request) {
        return child_->AsyncUpdateSettings(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncCreateReportConfig(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::CreateReportConfigRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::migrationcenter::v1::CreateReportConfigRequest const&
              request) {
        return child_->AsyncCreateReportConfig(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ReportConfig>
MigrationCenterLogging::GetReportConfig(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::GetReportConfigRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::GetReportConfigRequest const&
                 request) { return child_->GetReportConfig(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ListReportConfigsResponse>
MigrationCenterLogging::ListReportConfigs(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::ListReportConfigsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::ListReportConfigsRequest const&
                 request) {
        return child_->ListReportConfigs(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncDeleteReportConfig(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::DeleteReportConfigRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::migrationcenter::v1::DeleteReportConfigRequest const&
              request) {
        return child_->AsyncDeleteReportConfig(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncCreateReport(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::CreateReportRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::CreateReportRequest const&
                 request) {
        return child_->AsyncCreateReport(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::Report>
MigrationCenterLogging::GetReport(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::GetReportRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::migrationcenter::v1::GetReportRequest const& request) {
        return child_->GetReport(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::migrationcenter::v1::ListReportsResponse>
MigrationCenterLogging::ListReports(
    grpc::ClientContext& context,
    google::cloud::migrationcenter::v1::ListReportsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::migrationcenter::v1::ListReportsRequest const&
                 request) { return child_->ListReports(context, request); },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncDeleteReport(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::migrationcenter::v1::DeleteReportRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::cloud::migrationcenter::v1::DeleteReportRequest const&
                 request) {
        return child_->AsyncDeleteReport(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
MigrationCenterLogging::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return child_->AsyncGetOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<Status> MigrationCenterLogging::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::shared_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return child_->AsyncCancelOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace migrationcenter_v1_internal
}  // namespace cloud
}  // namespace google
