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

    // starts the blackjack round
    void StartRound(void);

    // resets the blackjack round (clearing the cards)
    void ResetRound(void);

    // display the current hand
    void DisplayHand(std::vector<int> hand);

    // Calculate the current hand total
    int CalculateHand(std::vector<int> hand);

    // display amount of money the player has
    void DisplayMoney(void);

    // valididate the player's hand
    bool ValidHand(std::vector<int> hand);

    // todo: function to ask the player if they want to "hit" or "stand"
    void PlayerAction(void);

    // todo: run the dealer's turn
    void DealerAction(void);

    // todo: compare the player's and dealer's hand and return if the player won
    std::string CompareHands(void);

    // todo: calculate the winnings of the round

};