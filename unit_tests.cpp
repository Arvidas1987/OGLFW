#include <iostream>
#include "OGLFW.hpp"
#
#define PRINTLN( x ) std::cout << x << '\n';
#define PRINT( x ) std::cout << x ;
#define NEWLN() std::cout << '\n';
#
#define TEST_NAME( x ) std::cout << x << std::endl;
#define TEST_EQUAL( method, value, message ) if( method == value )\
                    { PRINT("\t|-> ") PRINTLN(message) }

int main()
{
    PRINTLN("OGLFW UNITS TESTS")
    NEWLN()
    TEST_NAME( "=== GLFW initialization ===" )
    {
        Window okno;
        TEST_EQUAL( okno.init(), -1, "FAILED. GLFW inicjalization issue." )
        TEST_EQUAL( okno.init(),  0, "PASSED. GLFW inicjalization: OK." )
    }
    NEWLN()
    TEST_NAME( "=== Create window ===" )
    {
        Window okno;
        okno.init(); // if you want to try fail this test, comment that line
        TEST_EQUAL( okno.create_window(100,100,"Create window"), -1, "FAILED. Create window issue. "
                                               "Did You initialise GLFW? Use init()." )
        TEST_EQUAL( okno.create_window(100,100,"Create window"),  0, "PASSED. Create window: OK." )
    }
    NEWLN()
    TEST_NAME( "=== should_close(true) ===" )
    {
        Window okno;
        okno.init();
        okno.create_window(100,100,"Create window");

        bool should_be_close = true;

        while( true ){
            TEST_EQUAL( should_be_close,  true, "PASSED. Window is closed." )
            TEST_EQUAL( should_be_close, false, "FAILED. Window should close." )
            okno.should_close(should_be_close);
            break;
        }
    }
    NEWLN()
    TEST_NAME( "=== should_close(false) ===" )
    {
        Window okno;
        okno.init();
        okno.create_window(100,100,"Create window");

        bool should_be_close = false;

        while( true ){
            TEST_EQUAL( should_be_close, false, "PASSED. Window should not be closed." )
            TEST_EQUAL( should_be_close,  true, "FAILED. Window is closed." )
            okno.should_close(should_be_close);
            break;
        }
    }


    return 0;
}
