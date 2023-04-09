#if !defined (RENDERER_H)
#define RENDERER_H

#include <GL/glew.h>

#define ASSERT(x) if (!(x)) __debugbreak();

void GLAPIENTRY GLDebugMessageCallback(unsigned int source,
                                       unsigned int type,
                                       unsigned int id,
                                       unsigned int severity,
                                       int length,
                                       const char* message,
                                       const void* data);

#endif