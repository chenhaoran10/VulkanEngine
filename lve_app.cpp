
#include "lve_app.hpp"

//std
#include <stdexcept>

namespace lve {

    LveApp::LveApp() {
        createPipelineLayout();
        createPipeline();
        createCommandBuffers();
    }

    LveApp::~LveApp() {
        vkDestroyPipelineLayout(lveDevice.device(),pipelineLayout, nullptr);
    }

    void LveApp::run() {
        while (!lveWindow.shouldClose()) {
            glfwPollEvents();
        }
    }

    void LveApp::createPipelineLayout() {
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        pipelineLayoutInfo.pSetLayouts = nullptr;
        pipelineLayoutInfo.pushConstantRangeCount = 0;
        pipelineLayoutInfo.pPushConstantRanges = nullptr;
        if (vkCreatePipelineLayout(lveDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout)
            != VK_SUCCESS) {
            throw std::runtime_error("failed to create pipeline layout");
        }

    }

    void LveApp::createPipeline() {
        auto pipelineConfig=LvePipeline::defaultPipelineConfigInfo(lveSwapChain.width(),lveSwapChain.height());
        pipelineConfig.renderPass = lveSwapChain.getRenderPass();
        pipelineConfig.pipelineLayout = pipelineLayout;
        lvePipeline =std::make_unique<LvePipeline>(
                lveDevice,
                "../shaders/simple_shader.vert.spv",
                "../shaders/simple_shader.frag.spv",
                pipelineConfig
                );
    }

    void LveApp::createCommandBuffers() {

    }

    void LveApp::drawFrame() {

    }
}  // namespace lve