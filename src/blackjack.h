#pragma once

#include "player.h"
#include "deck.h"

// void Blackjack(void);
// // void WelcomeScreen(bool& running);
// void Menu(void);

// void DisplayMoney(void);


class Blackjack
{
  private:
    Deck deck;
    // Player player;
    // Player dealer;
  
  public:

    // todo: initialize the player and the dealer 
    void StartRound(void);
    // TODO: Calculate the current hand total
    // todo: display amount of money the player has
    // todo: valididate the player's hand
};