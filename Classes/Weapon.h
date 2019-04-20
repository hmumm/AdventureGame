#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
    Weapon(std::string description, int strength);
private:
    int m_strength;
};