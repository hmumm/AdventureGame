#pragma once
#include "Item.h"

// A weapon is a type of item, used for attacking
class Weapon : public Item
{
public:
    Weapon(std::string description, int strength);
private:
    int m_strength;
};