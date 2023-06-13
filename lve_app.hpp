#pragma once

#include "lve_device.hpp"
#include "lve_model.hpp"
#include "lve_pipeline.hpp"
#include "lve_swap_chain.hpp"
#include "lve_window.hpp"

// std
#include <memory>
#include <vector>

namespace lve {
    class LveApp {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        LveApp();

        ~LveApp();

        LveApp(const LveApp &) = delete;

        LveApp &operator=(const LveApp &) = delete;

        void run();

    private:
        void loadModels();
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();

        void drawFrame();

        void freeCommandBuffers();

        void recreateSwapChain();

        void recordCommandBuffer(int imageIndex);

        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        LveDevice lveDevice{lveWindow};
        std::unique_ptr<LveSwapChain> lveSwapChain;
        std::unique_ptr<LvePipeline> lvePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        std::unique_ptr<LveModel> lveModel;
    };
}  // namespace lve