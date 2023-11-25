#include "Shader.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& VertexPath, const std::string& FragmentPath)
{
    std::string VertexCode, FragmentCode;
    std::ifstream VertexFile, FragmentFile;

    VertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    FragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        VertexFile.open(VertexPath);
        FragmentFile.open(FragmentPath);

        std::stringstream VertexStream, FragmentStream;
        VertexStream << VertexFile.rdbuf();
        FragmentStream << VertexFile.rdbuf();

        VertexFile.close();
        FragmentFile.close();

        VertexCode = VertexStream.str();
        FragmentCode = FragmentStream.str();
    }
    catch (std::ifstream::failure& Error)
    {
        std::cout << "Error::Shader : File open failed. Reason: " << Error.what() << std::endl;
    }

    unsigned int Vertex = glCreateShader(GL_VERTEX_SHADER);

}

void Shader::CheckCompileError(unsigned int ShaderID, ShaderType Type)
{
    int Success;
    char Log[1024];

    if (Type == ShaderType::PROGRAM)
    {
        glGetProgramiv(ShaderID, GL_LINK_STATUS, &Success);
        if (!Success)
        {
            glGetProgramInfoLog(ShaderID, 1024, NULL, Log);

        }
    }
}