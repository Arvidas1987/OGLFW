#include "OGLFW.hpp"
//-----------------------------------------------------------------------------
//                      konstructor domyslny
//                      implicite ctor
//-----------------------------------------------------------------------------
Window::Window():m_window(nullptr)
{}

//-----------------------------------------------------------------------------
//                      destructor
//-----------------------------------------------------------------------------
Window::~Window()
{
    glfwDestroyWindow( m_window );
    glfwTerminate();
    m_window = nullptr;
}

//-----------------------------------------------------------------------------
//                      init()
//-----------------------------------------------------------------------------
int Window::init()
{
///* Initialize the GLFW library *///
    if ( GLFW_FALSE == glfwInit() )
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

//-----------------------------------------------------------------------------
//                      create_window()
//-----------------------------------------------------------------------------
int Window::create_window( int width, int height,
                           std::string const title,
                           GLFWmonitor* monitor,
                           GLFWwindow* share)
{
    m_window = glfwCreateWindow( width, height, title.c_str(), monitor, share );
    if ( m_window == nullptr )
    {
        glfwTerminate();
        return -1;
    }
    return 0;
}

