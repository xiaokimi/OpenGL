#pragma once

class ElementBuffer
{
public:
    ElementBuffer(unsigned int* Data, unsigned int Count);
    virtual ~ElementBuffer();

    void Bind() const;
    void UnBind() const;

private:
    unsigned int m_RendererID;
    unsigned int m_Count;
};