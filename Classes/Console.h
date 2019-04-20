#pragma once
#include <iostream>
#include <string>

// Some tools to make console printing easier
class Console 
{

public:

    // Print the message and go to the next line
    static void PrintLn(std::string msg);

    // Get the input from the console
    static std::string Read();
    
private:


};