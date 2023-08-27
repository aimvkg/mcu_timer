
cmake_minimum_required(VERSION 3.25.1)
include(CMakePrintHelpers)
project(${CMAKE_PROJECT_NAME} C CXX)
get_filename_component(PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}" DIRECTORY)
get_filename_component(PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}" DIRECTORY)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug build is selected.")
    set (CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/debug)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Release build is selected.")
    set (CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build/release)
endif()

# Set the output directory for object files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Add compiler flags
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DVK_PROTOTYPES")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_PROTOTYPES -E -Wall")


# Libraries - GLFW
find_package(GLFW)
set(GLFW_DIR ${PROJECT_SOURCE_DIR}/app/libs/glfw)
file(GLOB sources_glfw ${GLFW_DIR}/src/*.cpp)
include_directories(${GLFW_DIR}/include)

# Libraries - Dear ImGui
#find_package(ImGui)
set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/app/libs/imgui)
file(GLOB sources_imgui ${IMGUI_DIR}/src/*.cpp)
include_directories(${IMGUI_DIR}/include)

# Libraries - Vulkan
find_package(Vulkan REQUIRED)
set(VULKAN_DIR ${PROJECT_SOURCE_DIR}/app/libs/vulkan)
file(GLOB sources_vulkan ${VULKAN_DIR}/src/*.cpp)
include_directories(${VULKAN_DIR}/include)

set(LIBRARIES "glfw;Vulkan::Vulkan")

# App
set(APP_DIR ${PROJECT_SOURCE_DIR}/app)
file(GLOB sources_app ${APP_DIR}/src/*.cpp)
include_directories(${APP_DIR}/include)

add_executable(${CMAKE_PROJECT_NAME} ${sources_glfw} ${sources_imgui} ${sources_vulkan} ${sources_app})
target_link_libraries(${CMAKE_PROJECT_NAME} ${LIBRARIES})
target_compile_definitions(${CMAKE_PROJECT_NAME} PUBLIC -DImTextureID=ImU64)
# Set the output name of the executable (optional)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES OUTPUT_NAME ${CMAKE_PROJECT_NAME})



