#pragma once
#include <string>

class Enemy
{
public:
    Enemy(std::string name, int health)
    {
        m_name = name;
        m_health = health;
    }

    std::string getName()
    {
        return m_name;
    }

    void setName(std::string name)
    {
        m_name = name;
    }

    int getHealth()
    {
        return m_health;
    }

    void setHealth(int health)
    {
        m_health = health;
    }
private:
    std::string m_name;
    int m_health;
};