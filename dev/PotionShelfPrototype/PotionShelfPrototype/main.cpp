#include <iostream>
#include <string>
#include "PotionShelf.h"

int getNumberInput(std::string prompt)
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        try
        {
            return std::stoi(input);
        }
        catch (...)
        {
            std::cout << "Invalid input. Please enter a whole number.\n";
        }
    }
}

int getMenuChoice()
{
    int choice;

    while (true)
    {
        std::cout << "\n=== The Witch's Potion Shelf ===\n";
        std::cout << "1. Add Potion\n";
        std::cout << "2. View Potions\n";
        std::cout << "3. Use Potion\n";
        std::cout << "4. Exit\n";

        choice = getNumberInput("Choose an option between 1 and 4: ");

        if (choice >= 1 && choice <= 4)
        {
            return choice;
        }

        std::cout << "Invalid choice. Please choose 1, 2, 3, or 4.\n";
    }
}

int main()
{
    PotionShelf shelf;
    bool running = true;

    while (running)
    {
        int choice = getMenuChoice();

        if (choice == 1)
        {
            std::string name;
            int quantity;

            std::cout << "Enter potion name: ";
            std::getline(std::cin, name);

            if (name.empty())
            {
                std::cout << "A potion needs a name.\n";
            }
            else
            {
                quantity = getNumberInput("Enter starting quantity: ");

                if (quantity <= 0)
                {
                    std::cout << "Quantity must be greater than 0.\n";
                }
                else
                {
                    shelf.addPotion(name, quantity);
                }
            }
        }
        else if (choice == 2)
        {
            shelf.viewPotions();
        }
        else if (choice == 3)
        {
            shelf.viewPotions();

            if (shelf.getPotionCount() > 0)
            {
                int potionNumber = getNumberInput("Enter potion number to use: ");
                shelf.usePotion(potionNumber - 1);
            }
        }
        else if (choice == 4)
        {
            std::cout << "The shelf closes. Try not to drink anything glowing.\n";
            running = false;
        }
    }

    return 0;
}
