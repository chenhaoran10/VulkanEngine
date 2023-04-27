project(VulkanEngine)

if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif (CMAKE_HOST_APPLE)
    set(MACOS 1)
elseif (CMAKE_HOST_UNIX)
    set(LINUX 1)
endif ()


set(CMAKE_CXX_STANDARD 17)


add_executable(VulkanEngine main.cpp)


target_link_libraries(VulkanEngine glfw3)

set(GLM_INCLUDE_DIRS C:/Users/90646/Desktop/Vulkan/vs/Libraries/glm)
include_directories(${GLM_INCLUDE_DIRS})

find_package(Vulkan REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)