// same as ifndef
#pragma once

#include <iostream>
#include <string>
#include <random>
#include <chrono>
// #include "general.h"

// void DeckInit(int (&deck)[DECK_SUITS][DECK_NUMS]);
// void PrintDeck(const int (&deck)[DECK_SUITS][DECK_NUMS]);
// void DrawCard(void);


// enum cardName
// {
//   Ace = 1,
//   Two,
//   Three,
//   Four, 
//   Five,
//   Six,
//   Seven,
//   Eight,
//   Nine,
//   Ten,
//   Jack,
//   Queen,
//   King
// };




class Deck
{
  private:
    int DECK_SIZE;
    int* DECK;
    int cardsDrawn;

    const std::string SPADES = "\u2664";
    const std::string HEARTS = "\u2665";
    const std::string DIAMONDS = "\u2666";
    const std::string CLUBS = "\u2667"; 
    const std::string SUITS[4] = {CLUBS, DIAMONDS, HEARTS, SPADES};

  public:
    // initialize the deck
    Deck(); // constructor
    Deck(int deckSize);  // overloaded constructor
    ~Deck();  // destructor

    // determine the value of the card
    // determine the suit of the card
    // draw a random card from the deck

    void ResetDeck(void);
    void PrintDeck(void);
    int DrawCard(void);
    std::string CardSuit(const int &cardIndex);
    int CardNumInt(const int &cardIndex);
    std::string CardNumStr(const int &cardIndex);
    std::string Card(const int&cardIndex);
};