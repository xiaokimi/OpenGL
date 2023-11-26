#include "VertexBuffer.h"

#include <glad/glad.h>

VertexBuffer::VertexBuffer(const void* Data, unsigned int Size)
{
    glGenBuffers(1, &m_RendererID);

    Bind();
    glBufferData(GL_ARRAY_BUFFER, Size, Data, GL_STATIC_DRAW);
    UnBind();
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBuffer::UnBind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
