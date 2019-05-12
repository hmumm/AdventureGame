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
    std::cin.get();
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
        if(m_pCommands->size() < 1)
        {
            Console::PrintLn("Go where?");
            return;
        }
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
    Room* pFoyer = new Room("You're in a room inside a mansion. It looks vaguely familiar. There is a staircase on each side of the room. You could go up or straight");

    Room* pHallway1 = new Room("You're in a hallway. This is a dead end for now. You could go back.");

    Room* pFoyerUpstairs = new Room("You are in the upstairs of the foyer. You could go straight, left, or down.");

    Room* pParlor = new Room("You're in the Parlor. There is a table in the middle as well as some creepy paintings hanging on the each wall. They dont make any sound now but you vaguely rememeber them making noise before. There also seesm to be a vacuum on the table in the middle. Wonder what that is for? This is a dead end for now.");

    // Add exits to all the rooms
    pFoyer->addExit("straight",pHallway1);
    pFoyer->addExit("up",pFoyerUpstairs);

    pHallway1->addExit("back",pFoyer);
    
    pFoyerUpstairs->addExit("down",pFoyer);
    pFoyerUpstairs->addExit("straight",pParlor);

    pParlor->addExit("back",pFoyerUpstairs);

    // Add items to the rooms
    pParlor->addWeapon(Weapon("Polturgust 2000",10));

    // Starting room
    m_pCurrentRoom = pFoyer;

    // Add all the rooms to m_rooms, so they can all be deleted when the game ends
    m_rooms.push_back(pFoyer);
    m_rooms.push_back(pHallway1);
    m_rooms.push_back(pFoyerUpstairs);
    m_rooms.push_back(pParlor);



}

bool Game::m_isPlaying = true;
std::vector<std::string>* Game::m_pCommands = new std::vector<std::string>();
Room* Game::m_pCurrentRoom = nullptr;
Player* Game::m_pPlayer = nullptr;