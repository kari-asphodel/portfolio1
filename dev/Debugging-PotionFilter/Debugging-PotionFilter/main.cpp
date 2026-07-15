#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> potions;
    std::vector<std::string> healingPotions;

    potions.push_back("Healing");
    potions.push_back("Poison");
    potions.push_back("Healing");
    potions.push_back("Strength");

    for (int i = 0; i < potions.size(); i++)
    {
        if (potions[i] == "Healing")
        {
            healingPotions.push_back(potions[i]);
        }
    }

    for (int i = 0; i < potions.size(); i++)
    {
        std::cout << potions[i] << "\n";
    }

    return 0;
}