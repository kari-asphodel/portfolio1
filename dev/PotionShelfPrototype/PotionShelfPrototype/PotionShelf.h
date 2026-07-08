#ifndef POTIONSHELF_H
#define POTIONSHELF_H

#include "Potion.h"
#include <string>
#include <vector>

class PotionShelf
{
private:
    std::vector<Potion> potions;

public:
    void addPotion(std::string name, int quantity);
    void viewPotions() const;
    void usePotion(int index);
    int getPotionCount() const;
};

#endif
