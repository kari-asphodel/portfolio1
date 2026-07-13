#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> potions;

    potions.push_back("Healing");
    potions.push_back("Poison");
    potions.push_back("Healing");
    potions.push_back("Strength");

    for (int i = 0; i < potions.size(); i++)
    {
        if (potions[i] != "Healing")
        {
            potions.erase(potions.begin() + i);
        }
    }

    for (int i = 0; i < potions.size(); i++)
    {
        std::cout << potions[i] << "\n";
    }

    return 0;
}