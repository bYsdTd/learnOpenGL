#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Renderer
{
public:
    Renderer();
    ~Renderer();
    void init();
    void render();
    // void update();
    // void destroy();
    // void setWindow(GLFWwindow* window);
    // void setShader(const char* vertex_shader_text, const char* fragment_shader_text);
    // void setVertexData(const float* vertex_data, int vertex_count);
    // void setUniformData(const float* uniform_data, int uniform_count);

private:
    GLuint VAO;
    GLuint VBO;
    GLuint vertex_shader;
    GLuint fragment_shader;
    GLuint program;
    GLint mvp_location, vpos_location, vcol_location;
};

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void Renderer::init()
{
    // 生成绑定VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // 生成绑定VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // 传输定点数据
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 绑定VAO指针到一个属性的配置，这个配置与当前绑定的VBO是相关的
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 解绑VAO,VBO
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);

    const char* vertex_shader_text =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
    
    const char* fragment_shader_text =
    "#version 330 core\n"
    "out vec4 FragColor;"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(0.5, 0.5, 0.5, 1.0);\n"
    "}\n";

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);
    int  success;
    char infoLog[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::LINK_PROJGRAM_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void Renderer::render()
{
    glUseProgram(program);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

#endif