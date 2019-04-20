#include "Game.h"

// Main game loop
void Game::Play()
{
    do
    {
        Console::PrintLn(m_pCurrentRoom->getDescription());
        std::string input;
        input = Console::Read();
        *m_pCommands = Parser::Parse(input);
    
    } while(m_isPlaying);
    delete m_pCommands;
    delete m_pCurrentRoom;
    Console::PrintLn("Goodbye");
}

void Game::ExecuteCommands()
{
    for(int i = 0; i < m_pCommands->size(); i++)
    {
        
    }
}

bool Game::m_isPlaying = true;
std::vector<std::string>* Game::m_pCommands = new std::vector<std::string>();
Room* Game::m_pCurrentRoom = new Room("Test room");