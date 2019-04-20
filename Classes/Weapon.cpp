#include "Weapon.h"

Weapon::Weapon(std::string description, int strength) : Item(description)
{
    m_strength = strength;
}