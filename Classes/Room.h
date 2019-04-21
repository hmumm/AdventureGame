#pragma once
#include <string>
#include <vector>
#include "Item.h"

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

    
private:
    // Description of the room, prints when the room is entered
    std::string m_description;
    // All of the items in the room
    std::vector<Item> m_items;

};