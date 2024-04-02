//g++ -std=c++17 -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include/glm -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include/imgui-master -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include/imgui-master/backends \
tut/test.cpp /Users/dillonmaltese/Documents/GitHub/OpenGL/src/glad.c \
-o main -L/Users/dillonmaltese/Documents/GitHub/OpenGL/lib \
-lglfw3 -limgui -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

//g++ -std=c++17 -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include/glm -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include/imgui-master -I/Users/dillonmaltese/Documents/GitHub/OpenGL/include/imgui-master/backends tut/test.cpp /Users/dillonmaltese/Documents/GitHub/OpenGL/src/glad.c -o main -L/Users/dillonmaltese/Documents/GitHub/OpenGL/lib -lglfw3 -limgui -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

// Include OpenGL headers
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
    // Initialize GLFW
    glfwInit();
    
    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui Example", NULL, NULL);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
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
        
        // Create UI elements
        ImGui::Begin("Hello, world!");
        ImGui::Text("This is some text.");
        ImGui::End();
        
        // Rendering
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        // Swap buffers
        glfwSwapBuffers(window);
    }
    
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    // Close OpenGL window and terminate GLFW
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}
