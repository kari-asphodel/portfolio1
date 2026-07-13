#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> guests;

    guests.push_back("Dracula");
    guests.push_back("Carmilla");
    guests.push_back("Nosferatu");

    for (int i = 0; i <= guests.size(); i++)
    {
        std::cout << guests[i] << "\n";
    }

    return 0;
}