#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <GLFW/glfw3.h>

class Renderer
{
public:
    Renderer(){

    }
    ~Renderer(){

    }
    void init(){

    }
    void render(){

    }
    // void update();
    // void destroy();
    // void setWindow(GLFWwindow* window);
    // void setShader(const char* vertex_shader_text, const char* fragment_shader_text);
    // void setVertexData(const float* vertex_data, int vertex_count);
    // void setUniformData(const float* uniform_data, int uniform_count);

private:
    GLuint vertex_buffer;

};
#endif