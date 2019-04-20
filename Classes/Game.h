#pragma once

#include <string>
#include <vector>
#include "Console.h"
#include "Parser.h"

class Game {

public:

    static void Play();
    
    static void setIsPlaying(bool playing)
    {
        m_isPlaying = playing;
    }

    static bool getIsPlaying() {
        return m_isPlaying;
    }

    static std::vector<std::string> getCommands()
    {
        return *pM_commands;
    }

    static void setCommands(std::vector<std::string> commands)
    {
        *pM_commands = commands;
    }

private:
    static bool m_isPlaying;
    static std::vector<std::string>* pM_commands;

};