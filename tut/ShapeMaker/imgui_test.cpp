//g++ -std=c++17 \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include/glm \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include/imgui-full \
    -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include/imgui-full/backends \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/imgui_test.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/src/glad.c \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/EBO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/VAO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/VBO.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/tut/ShapeMaker/shaderClass.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/include/imgui-full/imgui.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/include/imgui-full/backends/imgui_impl_opengl3.cpp \
    /Users/dillonmaltese/Documents/GitHub/OpenGL/include/imgui-full/backends/imgui_impl_glfw.cpp \
    -o imgui_test \
    -L/Users/dillonmaltese/Documents/GitHub/OpenGL/lib \
    -lglfw3 \
    -framework OpenGL \
    -framework Cocoa \
    -framework IOKit \
    -framework CoreVideo

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui-full/imgui.h>
#include <imgui-full/backends/imgui_impl_opengl3.h>
#include <imgui-full/backends/imgui_impl_glfw.h>

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui Test", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Initialize OpenGL loader (GLAD)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll and handle events
        glfwPollEvents();

        // Start the ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // ImGui demo window
        ImGui::ShowDemoWindow();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // Terminate GLFW
    glfwTerminate();
    return 0;
}
