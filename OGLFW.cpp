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
    glfwDestroyWindow( ptr() );
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

//-----------------------------------------------------------------------------
//                      create_window
//-----------------------------------------------------------------------------
int Window::create_window(int x_pos, int y_pos,
                          int width, int height,
                          const std::string title,
                          GLFWmonitor* monitor,
                          GLFWwindow* share)
{
    int err = create_window( width, height, title, monitor, share);
    glfwSetWindowPos( ptr(), x_pos, y_pos);
    return err;
}

//-----------------------------------------------------------------------------
//                      ptr()
//-----------------------------------------------------------------------------
GLFWwindow* Window::ptr()const
{
    return m_window;
}

//-----------------------------------------------------------------------------
//                      should_close()
//-----------------------------------------------------------------------------
int Window::should_close( bool close )
{
    int tmp = glfwWindowShouldClose( ptr() );
    return ( (close == true) ? tmp : !tmp );
}

//-----------------------------------------------------------------------------
//                      swap_buffers
//-----------------------------------------------------------------------------
void Window::swap_buffers()
{
    glfwSwapBuffers( ptr() );
}

//-----------------------------------------------------------------------------
//                      poll_events
//-----------------------------------------------------------------------------
void Window::poll_events()
{
    glfwPollEvents();
}

//-----------------------------------------------------------------------------
//                      terminate()
//-----------------------------------------------------------------------------
void Window::terminate()
{
    glfwTerminate();
}

//-----------------------------------------------------------------------------
//                      set_title
//-----------------------------------------------------------------------------
void Window::set_title( const std::string title )
{
    glfwSetWindowTitle( ptr(), title.c_str() );
}

//-----------------------------------------------------------------------------
//                      set_window_pos
//-----------------------------------------------------------------------------
void Window::set_window_pos( int xpos, int ypos )
{
    glfwSetWindowPos( ptr(), xpos, ypos );
}

//-----------------------------------------------------------------------------
//                      get_window_pos
//-----------------------------------------------------------------------------
void Window::get_window_pos( int* xpos, int* ypos )
{
    glfwGetWindowPos( ptr(), xpos, ypos );
}

//-----------------------------------------------------------------------------
//                      set_window_size
//-----------------------------------------------------------------------------
void Window::set_window_size( int width, int height )
{
    glfwSetWindowSize( ptr(), width, height );
}

//-----------------------------------------------------------------------------
//                      get_window_size
//-----------------------------------------------------------------------------
void Window::get_window_size( int* width, int* height )
{
    glfwGetWindowSize( ptr(), width, height );
}

//-----------------------------------------------------------------------------
//                      show_window
//-----------------------------------------------------------------------------
void Window::show_window()
{
    glfwShowWindow( ptr() );
}

//-----------------------------------------------------------------------------
//                      hideWindow
//-----------------------------------------------------------------------------
void Window::hide_window()
{
    glfwHideWindow( ptr() );
}

//-----------------------------------------------------------------------------
//                      set_key_callback
//-----------------------------------------------------------------------------
void Window::set_key_callback( GLFWkeyfun callback )
{
    glfwSetKeyCallback( ptr(), callback );
}

//-----------------------------------------------------------------------------
//                      set_cursor_pos
//-----------------------------------------------------------------------------
void Window::set_cursor_pos( double xpos, double ypos )
{
    glfwSetCursorPos( ptr(), xpos, ypos );
}

//-----------------------------------------------------------------------------
//                      get_cursor_pos
//-----------------------------------------------------------------------------
void Window::get_cursor_pos( double* xpos, double* ypos )
{
    glfwGetCursorPos( ptr(), xpos, ypos );
}
