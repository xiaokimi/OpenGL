#pragma once

#include <string>

enum class ShaderType
{
    VERTEXT,
    FRAGMENT,
    PROGRAM
};

class Shader
{
public:
    Shader(const std::string& VertexPath, const std::string& FragmentPath);

private:
    void CheckCompileError(unsigned int ShaderID, ShaderType Type);

private:
    unsigned int ID;
};