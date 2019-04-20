#include "Console.h"
#include <iostream>
#include <string>

void Console::PrintLn(std::string msg) {
    std::cout << msg << std::endl;
}

std::string Console::Read() {
    std::cout << ">";
    std::string temp;
    std::getline(std::cin,temp);
    return temp;
}