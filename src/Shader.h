#pragma once

#include <string>

class Shader
{
public:
    Shader(const std::string& VertexPath, const std::string& FragmentPath);
    virtual ~Shader();

    void Bind() const;
    void UnBind() const;

private:
    unsigned int CreateShader(const std::string& FilePath, unsigned int ShaderType);

private:
    unsigned int m_ProgramID;
};