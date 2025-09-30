// same as ifndef
#pragma once

#include "general.h"

#define DECK_SUITS 4
#define DECK_NUMS 13

void DeckInit(int (&deck)[DECK_SUITS][DECK_NUMS]);
void PrintDeck(const int (&deck)[DECK_SUITS][DECK_NUMS]);
void DrawCard(void);


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
  Jack,
  Queen,
  King
};
