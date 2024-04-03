#ifndef GUI_CLASS_H
#define GUI_CLASS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>

class GUI
{   
public:
    bool showImGuiWindow = false; // Declaration of showImGuiWindow variable
    bool settingsMenuToggled = false; // Add a flag to track settings menu toggling
    GUI();
    void dropDown(GLFWwindow* window);
};

#endif
