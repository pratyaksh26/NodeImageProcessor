
cmake_minimum_required(VERSION 3.10)
project(NodeImageProcessor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# ImGui setup
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/libs/imgui)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends)
file(GLOB IMGUI_SOURCES 
    ${IMGUI_DIR}/*.cpp
    ${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# ImNodes setup
set(IMNODES_DIR ${CMAKE_SOURCE_DIR}/libs/imnodes)
include_directories(${IMNODES_DIR})
set(IMNODES_SOURCES
    ${IMNODES_DIR}/imnodes.cpp
)

# Source files
set(SOURCES
    src/main.cpp
    src/NodeGraph.cpp
    src/nodes/NodeBase.cpp
    src/nodes/InputNode.cpp
    src/nodes/OutputNode.cpp
    src/nodes/BrightnessNode.cpp
    src/nodes/BlurNode.cpp
)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# Executable
add_executable(NodeImageProcessor 
    ${SOURCES}
    ${IMGUI_SOURCES}
    ${IMNODES_SOURCES}
)

# Link libraries
target_link_libraries(NodeImageProcessor 
    ${OpenCV_LIBS}
    ${SDL2_LIBRARIES}
    GL
)

# Copy assets
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})