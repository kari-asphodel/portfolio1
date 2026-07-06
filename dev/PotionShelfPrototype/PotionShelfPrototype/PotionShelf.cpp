#include "PotionShelf.h"
#include <iostream>

void PotionShelf::addPotion(std::string name, int quantity)
{
    Potion newPotion(name, quantity);
    potions.push_back(newPotion);

    std::cout << "Potion added to the shelf.\n";
}

void PotionShelf::viewPotions() const
{
    if (potions.empty())
    {
        std::cout << "The potion shelf is empty.\n";
        return;
    }

    std::cout << "\n=== Potion Shelf ===\n";

    for (int i = 0; i < potions.size(); i++)
    {
        std::cout << i + 1 << ". "
                  << potions[i].getName()
                  << " | Quantity: "
                  << potions[i].getQuantity()
                  << "\n";
    }
}

void PotionShelf::usePotion(int index)
{
    if (index < 0 || index >= potions.size())
    {
        std::cout << "That potion number does not exist.\n";
        return;
    }

    if (potions[index].usePotion())
    {
        std::cout << "Potion used successfully.\n";
    }
    else
    {
        std::cout << "That potion bottle is already empty.\n";
    }
}

int PotionShelf::getPotionCount() const
{
    return static_cast<int>(potions.size());
}
