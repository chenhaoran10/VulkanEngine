#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"

namespace lve {

    class LveApp {
    public:
        LveApp() = default;

        LveApp(const LveApp &) = delete;

        LveApp &operator=(const LveApp &) = delete;

        void run();

        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

    private:
        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        LvePipeline lvePipeline{"C://Users//90646//Desktop//Vulkan/VulkanEngine/shaders/simple_shader.vert.spv",
                                "C://Users//90646//Desktop//Vulkan/VulkanEngine/shaders/simple_shader.frag.spv"};
    };
}  // namespace lve