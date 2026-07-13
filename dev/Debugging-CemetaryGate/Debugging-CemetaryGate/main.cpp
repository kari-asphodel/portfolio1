2#include <iostream>

int main()
{
    int gate = 1;

    while (gate <= 5)
    {
        if (gate % 2 == 0)
        {
            std::cout << "Gate " << gate << ": locked\n";
        }
        else
        {
            std::cout << "Gate " << gate << ": open\n";
        }

        gate++;
    }

    return 0;
}