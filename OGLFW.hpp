#ifndef _OGLFW_HPP_
#define _OGLFW_HPP_
#
#define GLEW_STATIC
#include <GL/glew.h>
#
#include <GLFW/glfw3.h>
#
class Window
{
private:
    GLFWwindow *m_window;
public:
    Window();
    ~Window();

    // return -1 if not initialised
    int init();


}; // class OGLFW
#
#endif // _OGLFW_HPP_
