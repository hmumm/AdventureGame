#include "Player.h"

Player::Player(std::string name)
{
    m_name = name;
}

void Player::addItem(Item item)
{
    m_items.push_back(item);
}

void Player::removeItem(Item item)
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

void Player::removeWeapon(Weapon weapon)
{
    for(int i = 0; i < m_items.size(); i++)
    {
        if(weapon.getDescription() == m_weapons.at(i).getDescription())
        {
            m_weapons.erase(m_weapons.begin() + i);
            return;
        }
    }
}