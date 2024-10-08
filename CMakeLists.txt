cmake_minimum_required(VERSION 3.10)
project(SNOW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

# Add SDL3 subdirectory
add_subdirectory(external/SDL3)

# Include directories
include_directories(include)
include_directories(external/gl3w/include)
include_directories(external/imgui)
include_directories(external/imgui/backends)
include_directories(external/glm)
include_directories(${CMAKE_SOURCE_DIR}/external/SDL3/include)

# Source files
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
)

# ImGui source files
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# Add gl3w source file
set(GL3W_SOURCES external/gl3w/src/gl3w.c)

# Add executable
add_executable(PhysicsEngine ${SOURCES} ${IMGUI_SOURCES} ${GL3W_SOURCES})

# Link SDL3
if (WIN32)
    target_link_libraries(PhysicsEngine SDL3::SDL3)
elseif (APPLE)
    target_link_libraries(PhysicsEngine SDL3::SDL3)
elseif (UNIX)
    target_link_libraries(PhysicsEngine SDL3::SDL3)
endif()

# Link OpenGL libraries
find_package(OpenGL REQUIRED)
target_link_libraries(PhysicsEngine OpenGL::GL)

# Add ImGui library
add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PRIVATE ${IMGUI_DIR} ${IMGUI_DIR}/backends)
target_link_libraries(PhysicsEngine imgui)

# Link gl3w
add_library(gl3w STATIC ${GL3W_SOURCES})
target_include_directories(gl3w PUBLIC external/gl3w/include)
target_link_libraries(PhysicsEngine gl3w)
