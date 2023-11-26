#pragma once

#include <glad/glad.h>

#include <vector>

struct VertexBufferElement
{
    unsigned int Type;
    unsigned int Count;
    unsigned char Normalized;

    static unsigned int GetSizeOfType(unsigned int InType)
    {
        switch (InType)
        {
        case GL_FLOAT:          return sizeof(float);
        case GL_UNSIGNED_INT:   return sizeof(unsigned int);
        }
        return 0;
    }
};

class VertexBufferLayout
{
public:
    template<typename T>
    void Push(unsigned int Count)
    {

    }

    template<>
    void Push<float>(unsigned int Count)
    {
        m_Elements.push_back({ GL_FLOAT, Count, GL_FALSE });
        m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * Count;
    }

    template<>
    void Push<unsigned int>(unsigned int Count)
    {
        m_Elements.push_back({ GL_UNSIGNED_INT, Count, GL_FALSE });
        m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * Count;
    }

public:
    VertexBufferLayout();
    virtual ~VertexBufferLayout();

    const std::vector<VertexBufferElement>& GetElements() const;
    unsigned int GetStride() const;

private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;
};