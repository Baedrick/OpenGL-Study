#if !defined (VERTEXARRAY_H)
#define VERTEXARRAY_H

#include "VertexBuffer.h"

#include "VertexBufferLayout.h"

class VertexArray
{
private:
    unsigned int rendererId;
public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

    void Bind() const;
    void Unbind() const;
};

#endif
