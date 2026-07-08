#ifndef POTION_H
#define POTION_H

#include <string>

class Potion
{
private:
    std::string name;
    int quantity;

public:
    Potion(std::string n, int q);

    std::string getName() const;
    int getQuantity() const;

    bool usePotion();
};

#endif
