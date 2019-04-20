#pragma once
#include <vector>
#include <string>

// Class for parsing the input
class Parser 
{
public:
    // Seperate the string based upon where the spaces are. Return a vector of each word
    static std::vector<std::string> Parse(std::string str);

private:
    // Return true if a string contains a specific char
    static bool Contains(std::string str, char cont);
};