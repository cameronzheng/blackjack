#include "deck.h"

// puts all the cards in the deck
void deckInit(void)
{
  for (int i = 0; i < DECK_SUITS; i++)
  {
    for (int j = 0; j < DECK_NUMS; j++)
    {
      std::cout << i << " " << j << std::endl;
      // deck[i][j] = 1;
    }
  }
}
