#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> snacks;

    snacks.push_back("Bone Chips");
    snacks.push_back("Ghost Pretzels");
    snacks.push_back("Spider Cookies");

    int choice;

    std::cout << "Choose a snack:\n";
    std::cout << "1. Bone Chips\n";
    std::cout << "2. Ghost Pretzels\n";
    std::cout << "3. Spider Cookies\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    std::cout << "You selected: " << snacks[choice] << "\n";
    std::cin.get();
    return 0;
}