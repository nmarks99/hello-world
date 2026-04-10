module;

#include <string_view>
#include <iostream>

export module hello;

export void greet(std::string_view s) {
    std::cout << "Hello " << s << std::endl;
}
