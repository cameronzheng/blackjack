#pragma once

#include <iostream>
#include <vector>
#include "deck.h"

class Player
{
  private:
    int moneyTotal;
    std::vector<int> currentHand;
  
  public:
    Player(); // constructor
    void AddCard(const int &card);
    std::vector<int> ShowCards(void);
    void ResetHand(void);
    int MoneyRemaining(void);
    bool ValidBet(int &bet);
    // void AddTotal(void);
};