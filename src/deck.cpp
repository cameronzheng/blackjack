#include "deck.h"

/**
 * @brief Initializes the deck to contain all possible cards
 * 
 * @param int (&deck)[DECK_SUITS][DECK_NUMS]:
 * 
 * @return Returns None
 * 
 */
void DeckInit(int (&deck)[CARDS])
{
  for (int i = 0; i < CARDS; i++)
  {
    deck[i] = 1;
  }
}

/**
 * @brief Prints out the cards in the deck
 * 
 * @param const int (&deck)[DECK_SUITS][DECK_NUMS]: 
 * Pass-by-Reference and read-only multidimensional array.
 * 
 * @return Returns None
 */
void PrintDeck(const int (&deck)[CARDS])
{
  for (int i = 0; i < DECK_SUITS; i++)
  {
    std::cout << SUITS[i] << ": ";
    for (int j = i * DECK_NUMS; j < (i * DECK_NUMS) + DECK_NUMS; j++)
    {
      std::cout << deck[j] << " ";
    }
    std::cout << std::endl;
  }
}

/*
TODO: how to draw a card
needs to take in a random suit and a random value from 0 to 12 (plus one since we are going from 1 to King)

*/
void DrawCard(int (&deck)[CARDS])
{
  // using uniform integer distribution

  bool validCard = false;

  // construct a trivial random number generator engine from a time-based seed:
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);

  std::uniform_int_distribution<int> distribution (0, 51);

  system("clear");
  PrintDeck(deck);

  int index = distribution(generator);
  std::cout << "Index: " << index << std::endl;
  if (deck[index] == 0)
  {
    std::cout << "The card has already been drawn" << std::endl;
  }
  else
  {
    deck[index] = 0;
    std::cout << "we drew the card. heres the new deck" << std::endl;
    PrintDeck(deck);
  }
  

  // // generate random number between 1 and 13
  // int cardNum = rand() % 13 + 1;
  // // generate random number between 0 and 3
  // int cardSuit = rand() % 4;

  // std::cout << "Card: " << cardNum << SUITS[cardSuit] << std::endl;
}

// TODO: Names of the card