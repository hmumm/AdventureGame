#include "Game.h"

// Main game loop
void Game::Play()
{
    // Setup the player
    Console::PrintLn("Enter your name");
    std::string name = Console::Read();
    m_pPlayer = new Player(name);

    InitializeRooms();

    Console::PrintLn(m_pCurrentRoom->getDescription());

    do
    {
        std::string input = Console::Read();
        *m_pCommands = Parser::Parse(input);
        ExecuteCommands();
    } while(m_isPlaying);

    delete m_pCommands;
    delete m_pCurrentRoom;
    delete m_pPlayer;
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
        std::string secondCommand = m_pCommands->at(1);
        Room* nextRoom = m_pCurrentRoom->getExit(secondCommand);
        m_pCurrentRoom = nextRoom;
        Console::PrintLn(m_pCurrentRoom->getDescription());
        return;
        
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

void Game::InitializeRooms()
{
    Room* foyer = new Room("You're in a room inside a mansion. It looks vaguely familiar. There is a staircase on each side of the room. You could go up or straight");

    Room* hallway1 = new Room("You're in a hallway. This is a dead end for now. You could go back.");

    Room* foyerUpstairs = new Room("You are in the upstairs of the foyer. You could go straight, left, or down.");

    foyer->addExit("straight",hallway1);
    foyer->addExit("up",foyerUpstairs);

    hallway1->addExit("back",foyer);
    
    foyerUpstairs->addExit("down",foyer);

    // Starting room
    m_pCurrentRoom = foyer;

}

bool Game::m_isPlaying = true;
std::vector<std::string>* Game::m_pCommands = new std::vector<std::string>();
Room* Game::m_pCurrentRoom = nullptr;
Player* Game::m_pPlayer = nullptr;