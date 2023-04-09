#include "Renderer.h"

#include <iostream>

void GLAPIENTRY GLDebugMessageCallback(unsigned int source,
                                       unsigned int type,
                                       unsigned int id,
                                       unsigned int severity,
                                       int length,
                                       const char* message,
                                       const void* data)
{
    if (id == 131169 || id == 131185 || id == 131218 || id == 131204)
        return;

    std::cout << "---------------" << std::endl;
    std::cout << "Debug message (" << id << "): " << message << std::endl;

    switch (source) {
    case GL_DEBUG_SOURCE_API:
        std::cout << "Source: API" << std::endl;
        break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        std::cout << "Source: Window System" << std::endl;
        break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER:
        std::cout << "Source: Shader Compiler" << std::endl;
        break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:
        std::cout << "Source: Third Party" << std::endl;
        break;
    case GL_DEBUG_SOURCE_APPLICATION:
        std::cout << "Source: Application" << std::endl;
        break;
    case GL_DEBUG_SOURCE_OTHER:
        std::cout << "Source: Other" << std::endl;
        break;
    default:
        std::cout << "Source: Unknown" << std::endl;
        break;
    }

    switch (type)
    {
    case GL_DEBUG_TYPE_ERROR:
        std::cout << "Type: Error" << std::endl;
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        std::cout << "Type: Deprecated Behaviour" << std::endl;
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        std::cout << "Type: Undefined Behaviour" << std::endl;
        break;
    case GL_DEBUG_TYPE_PORTABILITY:
        std::cout << "Type: Portability" << std::endl;
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        std::cout << "Type: Performance" << std::endl;
        break;
    case GL_DEBUG_TYPE_MARKER:
        std::cout << "Type: Marker" << std::endl;
        break;
    case GL_DEBUG_TYPE_PUSH_GROUP:
        std::cout << "Type: Push Group" << std::endl;
        break;
    case GL_DEBUG_TYPE_POP_GROUP:
        std::cout << "Type: Pop Group" << std::endl;
        break;
    case GL_DEBUG_TYPE_OTHER:
        std::cout << "Type: Other" << std::endl;
        break;
    default:
        std::cout << "Type: Unknown" << std::endl;
        break;
    }

    switch (severity)
    {
    case GL_DEBUG_SEVERITY_HIGH:
        std::cout << "Severity: high" << std::endl;
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        std::cout << "Severity: medium" << std::endl;
        break;
    case GL_DEBUG_SEVERITY_LOW:
        std::cout << "Severity: low" << std::endl;
        break;
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        std::cout << "Severity: notification" << std::endl;
        break;
    default:
        std::cout << "Severity: Unknown" << std::endl;
        break;
    }

    __debugbreak(); // MSVC Compiler only
}