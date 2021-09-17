#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "shader.h"

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
    GLFWwindow* w = glfwCreateWindow(600, 600, "triangle", NULL, NULL);
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

    // array of triangle vertices
    float t[] =
    {
        -.5f, -.5f, 0.f,
        0.f, .5f, 0.f,
        .5f, -.5f, 0.f,
    };

    uint32_t v;
    glGenBuffers(1, &v);
    glBindBuffer(GL_ARRAY_BUFFER, v);
    glBufferData(GL_ARRAY_BUFFER, sizeof(t), t, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*3, (void*)0);
    glEnableVertexAttribArray(0);

    // set up viewport
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(w, framebuffer_size_callback);

    // build and compile shaders
    Shader myShader("vertex_shader.vs", "fragment_shader.fs");

    while(!glfwWindowShouldClose(w))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        myShader.use();

        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
