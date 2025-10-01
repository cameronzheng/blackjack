// same as ifndef
#pragma once

#include "general.h"

#define DECK_SUITS 4
#define DECK_NUMS 13
#define CARDS 52

void DeckInit(int (&deck)[CARDS]);
void PrintDeck(const int (&deck)[CARDS]);
int DrawCard(int (&deck)[CARDS], int &cardsDrawn);
std::string CardName(const int &index);


const std::string SPADE = "\u2664";
const std::string HEART = "\u2665";
const std::string DIAMOND = "\u2666";
const std::string CLUB = "\u2667";

const std::string SUITS[4] = {SPADE, HEART, DIAMOND, CLUB};

enum cardName
{
  Ace = 1,
  Two,
  Three,
  Four, 
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack = 10,
  Queen = 10,
  King = 10
};
