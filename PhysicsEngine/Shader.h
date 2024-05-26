#ifndef SHADER_H
#define SHADER_H

#include <string>

// Function to read shader source code from file
std::string readFile(const char* filePath);

// Function to compile shaders
unsigned int compileShader(unsigned int type, const char* source);

// Function to create shader program
unsigned int createShaderProgram(const char* vertexPath, const char* fragmentPath);

#endif // SHADER_H