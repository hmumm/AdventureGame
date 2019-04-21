#pragma once

#include <string>
#include <vector>
#include "Item.h"
#include "Weapon.h"

class Player
{
public:
    Player(std::string name);

    std::string getName()
    {
        return m_name;
    }

    std::vector<Item> getItems()
    {
        return m_items;
    }

    void setItems(std::vector<Item> items)
    {
        m_items = items;
    }

    void addItem(Item item);

    void removeItem(Item item);

    std::vector<Weapon> getWeapons()
    {
        return m_weapons;
    }

    void setWeapons(std::vector<Weapon> weapons)
    {
        m_weapons = weapons;
    }

    void addWeapon(Weapon weapon)
    {
        m_items.push_back(weapon);
    }

    void removeWeapon(Weapon weapon);



private:
    std::string m_name;
    std::vector<Item> m_items;
    std::vector<Weapon> m_weapons;
};