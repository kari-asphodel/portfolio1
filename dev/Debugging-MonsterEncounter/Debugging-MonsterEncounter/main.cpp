#include <iostream>

int main()
{
    int monsterHealth = 10;
    int attackDamage = 3;

    while (monsterHealth > 0)
    {
        std::cout << "Monster health: " << monsterHealth << "\n";
        std::cout << "You attack the monster!\n";

        monsterHealth + attackDamage;
    }

    std::cout << "The monster has been defeated!\n";

    return 0;
}