#include <iostream>
#include <string>

namespace my_lib {

    // static means here this can only be included and used once
    static void greet(std::string name) {
        std::cout << "Hello " << name << std::endl;
    }
}
