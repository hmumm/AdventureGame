#pragma once
#include <vector>
#include <string>

class Parser 
{
public:
    static std::vector<std::string> Parse(std::string str);

private:
    static bool Contains(std::string str, char cont);
};