#include <iostream>

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
        std::cout << "You cast Fire.\n";
        std::cout << "The room gets warmer.\n";
        std::cout << "The enemy takes 10 damage.\n";
    }
    else if (spellChoice == 2)
    {
        std::cout << "You cast Ice.\n";
        std::cout << "The room gets colder.\n";
        std::cout << "The enemy takes 8 damage.\n";
    }
    else if (spellChoice == 3)
    {
        std::cout << "You cast Shadow.\n";
        std::cout << "The lights flicker.\n";
        std::cout << "The enemy takes 12 damage.\n";
    }
    else
    {
        std::cout << "Invalid spell.\n";
    }

    return 0;
}