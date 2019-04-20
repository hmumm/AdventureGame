#pragma once
#include <string>
#include <vector>
#include "Item.h"

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

private:
    std::string m_description;
    std::vector<Item> m_items;

};