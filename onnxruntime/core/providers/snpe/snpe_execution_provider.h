// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "core/framework/execution_provider.h"
#include "SnpeLib.h"

namespace onnxruntime {

class SNPEExecutionProvider : public IExecutionProvider {
 public:
  SNPEExecutionProvider(const ProviderOptions& provider_options_map);
  virtual ~SNPEExecutionProvider();

  std::vector<std::unique_ptr<ComputeCapability>> GetCapability(
      const onnxruntime::GraphViewer& graph,
      const std::vector<const KernelRegistry*>& ) const override;
    
  std::shared_ptr<KernelRegistry> GetKernelRegistry() const override;
  std::unordered_map<std::string, std::string> GetRuntimeOptions() const { return runtime_options_; }

 private:
  ProviderOptions runtime_options_;
};
}  // namespace onnxruntime