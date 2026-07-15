#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Potion
{
private:
    std::string name;
    int dangerLevel;

public:
    Potion(std::string potionName, int level)
    {
        name = potionName;
        dangerLevel = level;
    }

    std::string GetName() const
    {
        return name;
    }

    int GetDangerLevel() const
    {
        return dangerLevel;
    }
};

int main()
{
    std::vector<Potion> potions;

    potions.push_back(Potion("Moon Rot", 2));
    potions.push_back(Potion("Grave Bloom", 5));
    potions.push_back(Potion("Spider Milk", 1));

    std::sort(potions.begin(), potions.end(), [](const Potion& first, const Potion& second)
        {
            return first.GetDangerLevel() > second.GetDangerLevel();
        });

    for (int i = 0; i < potions.size(); i++)
    {
        std::cout << potions[i].GetName() << "\n";
    }
    std::cin.get();
    return 0;
}