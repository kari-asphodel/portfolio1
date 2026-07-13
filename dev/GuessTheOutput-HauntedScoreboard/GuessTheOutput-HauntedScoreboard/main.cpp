#include <iostream>
#include <vector>
#include <string>

class Player
{
private:
    std::string name;
    int score;

public:
    Player(std::string playerName, int playerScore)
    {
        name = playerName;
        score = playerScore;
    }

    void AddScore(int amount)
    {
        score += amount;
    }

    std::string GetName() const
    {
        return name;
    }

    int GetScore() const
    {
        return score;
    }
};

int main()
{
    std::vector<Player> players;

    players.push_back(Player("Mina", 10));
    players.push_back(Player("Edgar", 20));
    players.push_back(Player("Lenore", 15));

    players[0].AddScore(5);
    players[2].AddScore(10);

    for (int i = 0; i < players.size(); i++)
    {
        std::cout << players[i].GetName() << ": "
            << players[i].GetScore() << "\n";
    }
    std::cin.get();
    return 0;
}