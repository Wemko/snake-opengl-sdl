#include <string>
#include <iostream>

void Log(const char* message) {
    std::cout << message << std::endl;
};

void Log(const char* message, const char* otherMessage) {
    std::cout << message << otherMessage << std::endl;
};