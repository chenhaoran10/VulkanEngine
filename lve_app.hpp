#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_swap_chain.hpp"
#include "lve_model.hpp"

//std
#include <memory>
#include <vector>

namespace lve {

    class LveApp {
    public:
        LveApp();

        ~LveApp();

        LveApp(const LveApp &) = delete;

        LveApp &operator=(const LveApp &) = delete;

        void run();

        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

    private:
        void loadModels();

        void createPipelineLayout();

        void createPipeline();

        void createCommandBuffers();

        void drawFrame();

        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        LveDevice lveDevice{lveWindow};
        LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
        std::unique_ptr<LvePipeline> lvePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
        std::unique_ptr<LveModel> lveModel;
    };
}  // namespace lve