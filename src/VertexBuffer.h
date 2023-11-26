#pragma once

class VertexBuffer
{
public:
    VertexBuffer(const void* Data, unsigned int Size);
    virtual ~VertexBuffer();

    void Bind() const;
    void UnBind() const;

private:
    unsigned int m_RendererID;
};