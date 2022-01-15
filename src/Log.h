#include <string>
#include <iostream>

namespace Log {
    static void log(std::string text) {
        std::cout << text << std::endl;
    }
};