#pragma once

#include "player.h"
#include "deck.h"
#include <cstdlib>

class Blackjack
{
  private:
    Deck deck;
    Player player;
    Player dealer;

    std::vector<int> playerHand;
    std::vector<int> dealerHand;

    std::vector<std::string> playerHandStr;
    std::vector<std::string> dealerHandStr;

    std::string lastMove;

    int round;
    int bet;
    bool bust;
    std::string roundResult;
  
  public:
    void Gameplay(void);

    void Menu(void);

    void Round(void);

    void Scoreboard(void);

    // starts the blackjack round
    void StartRound(void);
    
    // resets the blackjack round (clearing the cards)
    void ResetRound(void);

    // display the current hand
    std::vector<std::string> CardsToStringVec(std::vector<int> hand);

    // Calculate the current hand total
    int CalculateHand(std::vector<int> hand);

    // valididate the player's hand
    bool ValidHand(std::vector<int> hand);

    // todo: function to ask the player if they want to "hit" or "stand"
    void PlayerAction(void);

    // todo: run the dealer's turn
    void DealerAction(void);

    // todo: compare the player's and dealer's hand and return if the player won
    void CompareHands(void);

    // todo: calculate the winnings of the round
    void CalculateRound(void);

};