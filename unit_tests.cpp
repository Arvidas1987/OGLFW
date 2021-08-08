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

    return 0;
}
