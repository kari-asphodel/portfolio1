#include "Potion.h"

Potion::Potion(std::string n, int q)
{
    name = n;
    quantity = q;
}

std::string Potion::getName() const
{
    return name;
}

int Potion::getQuantity() const
{
    return quantity;
}

bool Potion::usePotion()
{
    if (quantity <= 0)
    {
        return false;
    }

    quantity--;
    return true;
}
