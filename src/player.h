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
    Player(Deck &deck); // constructor

    int currentBet = 99;

    void AddCard(const int &card);
    void ShowCards(void);
};