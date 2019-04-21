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
    if(m_pCommands == nullptr)
    {
        return;
    }

    std::string firstCommand = m_pCommands->at(0);
    if(firstCommand == "quit")
    {
        m_isPlaying == false;
        return;
    } else if(firstCommand == "go")
    {

    } else if(firstCommand == "take")
    {
        for(int i = 0; i < m_pCurrentRoom->getItems().size(); i++)
        {
            
        }
    } else if(firstCommand == "attack")
    {

    } else {
        return;
    }
}

bool Game::m_isPlaying = true;
std::vector<std::string>* Game::m_pCommands = new std::vector<std::string>();
Room* Game::m_pCurrentRoom = new Room("Test room");