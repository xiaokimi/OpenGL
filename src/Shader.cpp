#include "Shader.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& VertexPath, const std::string& FragmentPath)
{
    unsigned int Vertex = CreateShader(VertexPath, GL_VERTEX_SHADER);
    unsigned int Fragment = CreateShader(FragmentPath, GL_FRAGMENT_SHADER);

    m_ProgramID = glCreateProgram();
    glAttachShader(m_ProgramID, Vertex);
    glAttachShader(m_ProgramID, Fragment);
    glLinkProgram(m_ProgramID);

    int Success;
    glGetProgramiv(m_ProgramID, GL_LINK_STATUS, &Success);
    if (Success == GL_FALSE)
    {
        char InfoLog[1024];
        glGetProgramInfoLog(m_ProgramID, 1024, NULL, InfoLog);
        std::cout << "Link program failed.\n" << InfoLog << std::endl;
    }

    glDeleteShader(Vertex);
    glDeleteShader(Fragment);
}

Shader::~Shader()
{
    glDeleteProgram(m_ProgramID);
}

void Shader::Bind() const
{
    glUseProgram(m_ProgramID);
}

void Shader::UnBind() const
{
    glUseProgram(0);
}

unsigned int Shader::CreateShader(const std::string& FilePath, unsigned int ShaderType)
{
    std::string ShaderCode;

    std::ifstream File;
    File.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        std::stringstream FileStream;

        File.open(FilePath);
        FileStream << File.rdbuf();
        File.close();

        ShaderCode = FileStream.str();
    }
    catch (std::ifstream::failure& Error)
    {
        std::cout << "Failed open file : " << FilePath << "\n" << Error.what() << std::endl;
        return 0;
    }
    const char* ShaderData = ShaderCode.c_str();

    unsigned int ShaderID = glCreateShader(ShaderType);
    glShaderSource(ShaderID, 1, &ShaderData, NULL);
    glCompileShader(ShaderID);

    int Success;
    glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &Success);
    if (Success == GL_FALSE)
    {
        char InfoLog[1024];
        glGetShaderInfoLog(ShaderID, 1024, NULL, InfoLog);
        std::cout << "Compile shader failed : " << FilePath << "\n" << InfoLog << std::endl;
        glDeleteShader(ShaderID);
        return 0;
    }
    return ShaderID;
}
