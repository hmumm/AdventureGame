#include "Game.h"
#include "Parser.h"
#include "Console.h"
#include <vector>

void Game::Play()
{
    do
    {
        std::string input;
        input = Console::Read();
        *pM_commands = Parser::Parse(input);
    
    } while(m_isPlaying);
    delete pM_commands;
}

bool Game::m_isPlaying = true;
std::vector<std::string>* Game::pM_commands = new std::vector<std::string>();