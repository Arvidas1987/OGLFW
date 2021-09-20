#ifndef _OGLFW_HPP_
#define _OGLFW_HPP_
#
#define GLEW_STATIC
#include <GL/glew.h>
#
#include <GLFW/glfw3.h>
#
#include <string>
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

    int create_window( int width, int height,
                       std::string const title,
                       GLFWmonitor* monitor = nullptr,
                       GLFWwindow* share = nullptr );

    GLFWwindow* ptr()const;

    int should_close( bool close = false );

    void swap_buffers();
    void poll_events();
    void terminate();


}; // class OGLFW
#
#endif // _OGLFW_HPP_
