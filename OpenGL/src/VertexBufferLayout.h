#if !defined (VERTEXBUFFERLAYOUT_H)
#define VERTEXBUFFERLAYOUT_H

#include "Renderer.h"

#include <GL/glew.h>

#include "assert.h"
#include <vector>

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned int normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {
        switch(type) {
            case GL_FLOAT:
                return sizeof(GL_FLOAT);
            case GL_UNSIGNED_INT:
                return sizeof(GL_UNSIGNED_INT);
            case GL_UNSIGNED_BYTE:
                return sizeof(GL_UNSIGNED_BYTE);
        }
        ASSERT(false);
        return 0;
    }
};

class VertexBufferLayout
{
private:
    std::vector<VertexBufferElement> elements;
    unsigned int stride;
public:
    VertexBufferLayout()
        : stride(0) {}

    template<typename T>
    void Push(unsigned int count)
    {
        assert(false);
    }

    template<>
    void Push<float>(unsigned int count)
    {
        elements.push_back({ GL_FLOAT, count, GL_FALSE });
        stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
    }

    template<>
    void Push<unsigned int>(unsigned int count)
    {
        elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
        stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
    }

    template<>
    void Push<unsigned char>(unsigned int count)
    {
        elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
        stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
    }

    inline const std::vector<VertexBufferElement> GetElements() const& { return elements; }
    inline unsigned int GetStride() const { return stride; }
};

#endif
