#include "Parser.h"
#include <vector>
#include <string>

std::vector<std::string> Parser::Parse(std::string str)
{
    std::vector<std::string> commands;
    while(Contains(str,' '))
    {
        std::string word = str.substr(0,str.find_first_of(" "));
        commands.push_back(word);
        str = str.substr(str.find_first_of(" ") + 1,str.length());
    }
    commands.push_back(str);
    return commands;
}

bool Parser::Contains(std::string str, char cont)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == cont)
        {
            return true;
        }
    }
    return false;
}