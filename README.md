Node-Based Image Processor
A modular image processing application built with C++, OpenCV, ImGui, and ImNodes. It allows users to create image processing pipelines by connecting nodes (e.g., Brightness, Blur, Resize) in a graphical interface, processing images like ./assets/test.jpg and saving results to ./assets/output.jpg.
Features

Graphical Interface: Drag-and-drop node connections using ImNodes.
Modular Nodes: Includes Input, Output, Brightness, Blur, Contrast, Sharpen, Grayscale, Edge Detection, Saturation, Threshold, and Resize nodes.
Interactive Controls: Adjust node parameters (e.g., scale, threshold) via ImGui sliders.
Extensible: Easily add new nodes without modifying existing code.
OpenCV-Powered: Leverages OpenCV for robust image processing.

Prerequisites

System: Linux (tested on WSL with Ubuntu)
Dependencies:
CMake 3.10+
OpenCV (libopencv-dev)
SDL2 (libsdl2-dev)
OpenGL (libgl1-mesa-dev)



Installation

Clone the Repository:
git clone https://github.com/<your-username>/node-image-processor.git
cd node-image-processor


Install Dependencies (Ubuntu/WSL):
sudo apt-get update
sudo apt-get install libopencv-dev libsdl2-dev libgl1-mesa-dev cmake build-essential


Build the Project:
mkdir build && cd build
cmake ..
make


Ensure Assets:

Place an image (e.g., test.jpg) in assets/ or use the provided one.
The assets/ folder is copied to build/ during the build.



Usage

Run the Application:
./NodeImageProcessor


GUI Interaction:

Canvas: Drag links between nodes (e.g., Input → Resize → Output).
Properties: Adjust node settings (e.g., Resize scale to 0.5).
Input Node: Set path to ./assets/test.jpg.
Output Node: Set save path to ./assets/output.jpg, choose format (JPG/PNG), click "Save".


Example Workflow:

Connect: Input → Brightness → Blur → Output.
Set Brightness (+50), Blur (9), save to ./assets/output.jpg.
View output.jpg to see the processed image.


Verify Output:
ls ./assets/output.jpg



Project Structure
node-image-processor/
├── assets/               # Input/output images (e.g., test.jpg)
├── libs/                 # External libraries
│   ├── imgui/            # ImGui for GUI
│   └── imnodes/          # ImNodes for node graph
├── src/                  # Source code
│   ├── nodes/            # Node implementations
│   │   ├── InputNode.hpp/cpp
│   │   ├── OutputNode.hpp/cpp
│   │   ├── BrightnessNode.hpp/cpp
│   │   └── ...           # Other nodes (Blur, Resize, etc.)
│   ├── NodeBase.hpp/cpp  # Base node class
│   ├── NodeGraph.hpp/cpp # Graph management
│   └── main.cpp          # Application entry
├── CMakeLists.txt        # Build configuration
└── README.md             # Project documentation

Adding New Nodes

Create NewNode.hpp and NewNode.cpp in src/nodes/, inheriting from NodeBase.
Implement process() for image processing and renderProperties() for GUI controls.
Add to CMakeLists.txt under SOURCES.
Include in main.cpp, instantiate, and add to NodeGraph.
Rebuild and test.


