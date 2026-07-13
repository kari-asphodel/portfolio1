#include <iostream>
void CastSpell(std::string spellName,std::string effect, int damage)
{
    std::cout << "You cast " << spellName << ".\n";
    std::cout << effect << "\n";
    std::cout << "The enemy takes " << damage << " damage.\n";
}
int main()
{
    int spellChoice;

    std::cout << "Choose a spell:\n";
    std::cout << "1. Fire\n";
    std::cout << "2. Ice\n";
    std::cout << "3. Shadow\n";
    std::cout << "Enter choice: ";
    std::cin >> spellChoice;

    if (spellChoice == 1)
    {
        CastSpell("Fire", "The room gets warmer.", 10);
        std::cin.get();

    }
    else if (spellChoice == 2)
    {
        CastSpell("Ice", "The room gets colder.", 8);
        std::cin.get();

    }
    else if (spellChoice == 3)
    {
        CastSpell("Shadow", "The lights flicker.", 12);
        std::cin.get();
    }
    else
    {
        std::cout << "Invalid spell.\n";
        std::cin.get();
    }
    std::cin.get();
}