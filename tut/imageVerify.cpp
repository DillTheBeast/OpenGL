#include <iostream>
#include <fstream>
#include <string>

bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

int main() {
    // Verify texture file paths
    std::string planksTexPath = "/Users/dillonmaltese/Documents/GitHub/OpenGL/tut/textures/planks.png";
    std::string planksSpecPath = "/Users/dillonmaltese/Documents/GitHub/OpenGL/tut/textures/planksSpec.png";

    if (!fileExists(planksTexPath)) {
        std::cerr << "Error: Planks texture file not found: " << planksTexPath << std::endl;
        return -1;
    }

    if (!fileExists(planksSpecPath)) {
        std::cerr << "Error: PlanksSpec texture file not found: " << planksSpecPath << std::endl;
        return -1;
    }

    // Rest of your OpenGL initialization and rendering code goes here...

    return 0;
}
