#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
public:
    VertexArray();
    virtual ~VertexArray();

    void AddBuffer(const VertexBuffer& VBO, const VertexBufferLayout& Layout);

    void Bind() const;
    void UnBind() const;

private:
    unsigned int m_RendererID;
};