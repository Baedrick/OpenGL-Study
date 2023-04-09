#if !defined (INDEXBUFFER_H)
#define INDEXBUFFER_H

class IndexBuffer
{
private:
    unsigned int rendererId;
    unsigned int count;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return count; }
};

#endif