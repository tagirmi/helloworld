#include <iostream>

#include "lib.h"

int main()
{
    std::cout << "Hello World!" << std::endl;    
    std::cout << "Version " << mylib::version() << std::endl;

    return 0;
}
