#include "VertexArray.h"

#include <glad/glad.h>

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::AddBuffer(const VertexBuffer& VBO, const VertexBufferLayout& Layout)
{
    Bind();
    VBO.Bind();

    const std::vector<VertexBufferElement>& Elements = Layout.GetElements();
    unsigned int Offset = 0;
    for (unsigned int i = 0; i < Elements.size(); i++)
    {
        const VertexBufferElement& Element = Elements[i];

        glVertexAttribPointer(i, Element.Count, Element.Type, Element.Normalized, Layout.GetStride(), (void*)Offset);
        glEnableVertexAttribArray(i);

        Offset += VertexBufferElement::GetSizeOfType(Element.Type) * Element.Count;
    }

    UnBind();
    VBO.UnBind();
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_RendererID);
}

void VertexArray::UnBind() const
{
    glBindVertexArray(0);
}
