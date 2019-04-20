#pragma once

#include <string>

class Item
{
public:
    Item(std::string description);

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
};