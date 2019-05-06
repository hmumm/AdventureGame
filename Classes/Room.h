#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include <map>

// Contains information about a room a player could be
class Room
{
public:
    Room(std::string description);

    std::string getDescription()
    {
        return m_description;
    }

    void setDescription(std::string description)
    {
        m_description = description;
    }

    std::vector<Item> getItems()
    {
        return m_items;
    }

    void addItem(Item item)
    {
        m_items.push_back(item);
    }

    void removeItem(Item item);

    void addExit(std::string name, Room* room)
    {
        m_exits.insert(std::pair<std::string,Room*>(name,room));
    }

    void removeExit(std::string name)
    {
        m_exits.erase(m_exits.find(name));
    }

    std::map<std::string,Room*> getExits()
    {
        return m_exits;
    }

    Room* getExit(std::string name)
    {
        return m_exits.at(name);
    }
    
private:
    // Description of the room, prints when the room is entered
    std::string m_description;
    // All of the items in the room
    std::vector<Item> m_items;
    // All of the exits in the room
    std::map<std::string,Room*> m_exits;

};