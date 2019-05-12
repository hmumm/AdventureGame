#pragma once

#include <string>
#include <vector>
#include "Console.h"
#include "Parser.h"
#include "Room.h"
#include "Player.h"

class Game {

public:

    static void Play();

    static void ExecuteCommands();

    static void InitializeRooms();
    
    static void setIsPlaying(bool playing)
    {
        m_isPlaying = playing;
    }

    static bool getIsPlaying() {
        return m_isPlaying;
    }

    static std::vector<std::string> getCommands()
    {
        return *m_pCommands;
    }

    static void setCommands(std::vector<std::string> commands)
    {
        *m_pCommands = commands;
    }

private:
    static bool m_isPlaying;
    static std::vector<std::string>* m_pCommands;
    static std::vector<Room*> m_rooms;
    static Room* m_pCurrentRoom;
    static Player* m_pPlayer;

};