#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window,int width,int height)
{
    glViewport(0,0,width,height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void error_callback(int errorcode,const char* description)
{
    fprintf(stderr, "errorcode %d , description: %s\n", errorcode, description);
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwSetErrorCallback(error_callback);

    // 设置窗口属性
    // glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "LearnOpenGLES", NULL, NULL);

    if (!window)
    {
        const char* error_message;
        int errorcode = glfwGetError(&error_message);
        std::cout << "Error Exit " << error_message << " error code : " << errorcode << std::endl;
        glfwTerminate();
        return -1;
    }

    // 设置framebuffer callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glClearColor( 0.4f, 0.3f, 0.4f, 0.0f );

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        // handle input
        processInput(window);

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
