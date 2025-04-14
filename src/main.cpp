// #include "NodeGraph.hpp"
// #include "nodes/InputNode.hpp"
// #include "nodes/OutputNode.hpp"
// #include <imgui.h>
// #include <imgui_impl_sdl2.h>
// #include <imgui_impl_opengl3.h>
// #include <imnodes.h>
// #include <SDL.h>
// #include <GL/gl.h>

// int main(int, char**) {
//     SDL_Init(SDL_INIT_VIDEO);
//     SDL_Window* window = SDL_CreateWindow("Node Image Processor",
//         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//         1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
//     SDL_GLContext gl_context = SDL_GL_CreateContext(window);
//     SDL_GL_MakeCurrent(window, gl_context);
//     SDL_GL_SetSwapInterval(1);

//     IMGUI_CHECKVERSION();
//     ImGui::CreateContext();
//     ImNodes::CreateContext();
//     ImGui::StyleColorsDark();
//     ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
//     ImGui_ImplOpenGL3_Init("#version 130");

//     NodeGraph graph;
//     std::shared_ptr<InputNode> input_node = std::make_shared<InputNode>();
//     std::shared_ptr<OutputNode> output_node = std::make_shared<OutputNode>();
//     graph.addNode(input_node);
//     graph.addNode(output_node);
//     graph.connectNodes(input_node->getId(), 0, output_node->getId(), 0);

//     bool running = true;
//     while (running) {
//         SDL_Event event;
//         while (SDL_PollEvent(&event)) {
//             ImGui_ImplSDL2_ProcessEvent(&event);
//             if (event.type == SDL_QUIT) running = false;
//         }

//         ImGui_ImplOpenGL3_NewFrame();
//         ImGui_ImplSDL2_NewFrame();
//         ImGui::NewFrame();
//         ImNodes::PushAttributeFlag(ImNodesAttributeFlags_EnableLinkCreationOnSnap);

//         if (ImGui::BeginMainMenuBar()) {
//             if (ImGui::BeginMenu("File")) {
//                 if (ImGui::MenuItem("Exit")) running = false;
//                 ImGui::EndMenu();
//             }
//             ImGui::EndMainMenuBar();
//         }

//         ImGui::Begin("Canvas");
//         graph.render();
//         ImGui::End();

//         ImGui::Begin("Properties");
//         input_node->renderProperties();
//         output_node->renderProperties();
//         ImGui::End();

//         graph.process();

//         ImGui::Render();
//         glClear(GL_COLOR_BUFFER_BIT);
//         ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//         SDL_GL_SwapWindow(window);
//     }

//     ImNodes::DestroyContext();
//     ImGui_ImplOpenGL3_Shutdown();
//     ImGui_ImplSDL2_Shutdown();
//     ImGui::DestroyContext();
//     SDL_GL_DeleteContext(gl_context);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return 0;
// }



// #include "NodeGraph.hpp"
// #include "nodes/InputNode.hpp"
// #include "nodes/OutputNode.hpp"
// #include <imgui.h>
// #include <imgui_impl_sdl2.h>
// #include <imgui_impl_opengl3.h>
// #include <imnodes.h>
// #include <SDL.h>
// #include <GL/gl.h>

// int main(int, char**) {
//     SDL_Init(SDL_INIT_VIDEO);
//     SDL_Window* window = SDL_CreateWindow("Node Image Processor",
//         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//         1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
//     SDL_GLContext gl_context = SDL_GL_CreateContext(window);
//     SDL_GL_MakeCurrent(window, gl_context);
//     SDL_GL_SetSwapInterval(1);

//     IMGUI_CHECKVERSION();
//     ImGui::CreateContext();
//     ImNodes::CreateContext();
//     ImGui::StyleColorsDark();
//     ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
//     ImGui_ImplOpenGL3_Init("#version 130");

//     NodeGraph graph;
//     std::shared_ptr<InputNode> input_node = std::make_shared<InputNode>();
//     std::shared_ptr<OutputNode> output_node = std::make_shared<OutputNode>();
//     graph.addNode(input_node);
//     graph.addNode(output_node);
//     // No programmatic connection

//     bool running = true;
//     while (running) {
//         SDL_Event event;
//         while (SDL_PollEvent(&event)) {
//             ImGui_ImplSDL2_ProcessEvent(&event);
//             if (event.type == SDL_QUIT) running = false;
//         }

//         ImGui_ImplOpenGL3_NewFrame();
//         ImGui_ImplSDL2_NewFrame();
//         ImGui::NewFrame();
//         ImNodes::PushAttributeFlag(ImNodesAttributeFlags_EnableLinkCreationOnSnap);

//         if (ImGui::BeginMainMenuBar()) {
//             if (ImGui::BeginMenu("File")) {
//                 if (ImGui::MenuItem("Exit")) running = false;
//                 ImGui::EndMenu();
//             }
//             ImGui::EndMainMenuBar();
//         }

//         ImGui::Begin("Canvas");
//         graph.render();
//         graph.handleLinkCreation();
//         ImGui::End();

//         ImGui::Begin("Properties");
//         input_node->renderProperties();
//         output_node->renderProperties();
//         ImGui::End();

//         graph.process();

//         ImGui::Render();
//         glClear(GL_COLOR_BUFFER_BIT);
//         ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//         SDL_GL_SwapWindow(window);
//     }

//     ImNodes::DestroyContext();
//     ImGui_ImplOpenGL3_Shutdown();
//     ImGui_ImplSDL2_Shutdown();
//     ImGui::DestroyContext();
//     SDL_GL_DeleteContext(gl_context);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return 0;
// }

#include "NodeGraph.hpp"
#include "nodes/InputNode.hpp"
#include "nodes/OutputNode.hpp"
#include "nodes/BrightnessNode.hpp"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>
#include <imnodes.h>
#include <SDL.h>
#include <GL/gl.h>

int main(int, char**) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Node Image Processor",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImNodes::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 130");

    NodeGraph graph;
    std::shared_ptr<InputNode> input_node = std::make_shared<InputNode>();
    std::shared_ptr<BrightnessNode> brightness_node = std::make_shared<BrightnessNode>();
    std::shared_ptr<OutputNode> output_node = std::make_shared<OutputNode>();
    graph.addNode(input_node);
    graph.addNode(brightness_node);
    graph.addNode(output_node);
    // No programmatic connections

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT) running = false;
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        ImNodes::PushAttributeFlag(ImNodesAttributeFlags_EnableLinkCreationOnSnap);

        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("File")) {
                if (ImGui::MenuItem("Exit")) running = false;
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        ImGui::Begin("Canvas");
        graph.render();
        graph.handleLinkCreation();
        ImGui::End();

        ImGui::Begin("Properties");
        input_node->renderProperties();
        brightness_node->renderProperties();
        output_node->renderProperties();
        ImGui::End();

        graph.process();

        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

    ImNodes::DestroyContext();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}