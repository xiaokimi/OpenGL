#include "ElementBuffer.h"

#include <glad/glad.h>

ElementBuffer::ElementBuffer(unsigned int* Data, unsigned int Count)
: m_Count(Count)
{
    glGenBuffers(1, &m_RendererID);

    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * Count, Data, GL_STATIC_DRAW);
    UnBind();
}

ElementBuffer::~ElementBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void ElementBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void ElementBuffer::UnBind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
