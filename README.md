Node Image Processor
Node Image Processor is a simple tool to edit images by connecting blocks called nodes. Each node does one job, like making an image brighter or blurry. We can mix and match nodes to create cool effects, all through a drag-and-drop interface.
Features

Graphical Interface: Built with ImGui and ImNodes for easy node-based editing.
Dynamic Node Creation: Right-click to add any node, as many times as needed.
Nodes:
Input Node: Loads an image (e.g., ./assets/test.jpg).
Output Node: Saves the edited image (e.g., ./assets/output.jpg) as jpg or png.
Brightness Node: Adjusts image lightness or darkness.
Blur Node: Makes the image fuzzy with adjustable blur size.
Contrast Node: Changes color strength for bold or faded looks.
Sharpen Node: Makes edges clearer.
Grayscale Node: Turns the image black-and-white.
Edge Detection Node: Finds outlines, like a sketch.
Saturation Node: Adjusts color brightness.
Threshold Node: Creates a black-and-white image with no grays.
Resize Node: Changes image size.
Color Channel Splitter Node: Splits image into blue, green, and red channels.



Requirements

OS: Linux (tested on WSL with Ubuntu)
Dependencies:
CMake 3.10+
OpenCV 4.x
SDL2
OpenGL
A C++17 compiler (e.g., g++)



Installation

Clone the Repository:
git clone https://github.com/yourusername/node-image-processor.git
cd node-image-processor


Install Dependencies (Ubuntu/WSL):
sudo apt-get update
sudo apt-get install libopencv-dev libsdl2-dev libgl1-mesa-dev cmake g++


Build the Project:
mkdir build && cd build
cmake ..
make


Copy Test Image:
cp ../assets/test.jpg ./assets/test.jpg



Usage

Run the Program:
./NodeImageProcessor


Basic Steps:

Canvas Window:
Starts with an Input Node.
Right-click to add nodes (e.g., Output, Brightness, Color Channel Splitter).
Drag to connect nodes (e.g., Input -> Brightness -> Output).


Properties Window:
Input Node: Set path to ./assets/test.jpg.
Output Node: Set save path (e.g., ./assets/output.jpg), pick jpg/png, click Save.
Other Nodes: Adjust settings like brightness or blur size.


Example:
Add Color Channel Splitter and three Output Nodes.
Connect: Input -> Splitter -> Output (Blue), Output (Green), Output (Red).
Save as ./assets/output_blue.jpg, etc.




View Outputs:
ls ./assets/output*.jpg

Copy to view outside WSL:
cp ./assets/output.jpg /mnt/c/Users/YourName/Desktop/output.jpg



Project Structure

src/: Main code and node logic.
src/nodes/: Individual node implementations.
assets/: Sample images like test.jpg.
libs/: ImGui and ImNodes libraries.

Contributing
We welcome contributions! To help out:

Fork the repository.
Create a branch: git checkout -b my-feature.
Make changes and commit: git commit -m "Add my feature".
Push to your fork: git push origin my-feature.
Open a pull request.

Please include tests and update this README if you add new nodes or features.
License
MIT License. See LICENSE file for details.
Contact
Questions? Open an issue on GitHub or email yourusername@example.com.
Happy image editing!
