#include "Room.h"

Room::Room(std::string description)
{
    m_description = description;
}

void Room::removeItem(Item item)
{
    for(int i = 0; i < m_items.size(); i++)
    {
        if(item.getDescription() == m_items.at(i).getDescription())
        {
            m_items.erase(m_items.begin() + i);
            return;
        }
    }
}