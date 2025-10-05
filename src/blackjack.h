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
    Player player;
    Player dealer;
  
  public:
    // Blackjack();  // constructor

    // todo: initialize the player and the dealer 

    // todo: starts the blackjack round
    void StartRound(void);

    // todo: display the current hand
    void DisplayHand(std::vector<int> hand);

    // TODO: Calculate the current hand total
    int CalculateHand(std::vector<int> hand);

    // todo: display amount of money the player has
    void DisplayMoney(void);

    // todo: valididate the player's hand
    bool ValidHand(std::vector<int> hand);

    // todo: function to ask the player if they want to "hit" or "stand"

    // todo: run the dealer's turn

};