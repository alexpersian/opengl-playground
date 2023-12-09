#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
    // Start GL context and O/S window using the GLFW helper library
    if (!glfwInit())
    {
        std::cerr << "ERROR: GLFW3 startup failed." << std::endl;
        return 1;
    }

    // First we set the window properties
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Then we create the window
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Example", NULL, NULL);
    if (!window)
    {
        std::cerr << "ERROR: GLFW3 window creation failed." << std::endl;
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // Start the GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();

    // Get the renderer version info
    const GLubyte* renderer = glGetString(GL_RENDERER); // Renderer string
    const GLubyte* version = glGetString(GL_VERSION); // Version string
    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "Version: " << version << std::endl;

    // Close the GL context and any GLFW resources
    glfwTerminate();
    return 0;
}