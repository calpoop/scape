#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// adjust size of viewport when window size changes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // initialize GLFW; set versions
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // create GLFW window
    GLFWwindow* w = glfwCreateWindow(600, 600, "blank", NULL, NULL);
    if (w == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(w);

    // initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // set up viewport
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(w, framebuffer_size_callback);


    while(!glfwWindowShouldClose(w))
    {
        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
