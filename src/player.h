#pragma once

#include <vector>

class Player
{
  private:
    int moneyTotal;
    std::vector<int> currentHand;
  public:

    int currentBet;

    void AddCard(const int &card);

};