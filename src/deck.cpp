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

int DrawCard(int (&deck)[CARDS], int &cardsDrawn)
{
  /**
   * @brief Draws a card at random from the deck of cards. Makes sure a new card is drawn.
   * 
   * @param int(&deck)[CARDS] Deck of cards.
   * @param int &cardsDrawn Reference to total amount of cards drawn this round.
   * 
   * @return integer in the form of the index of the deck.
   */  
  // using uniform integer distribution

  bool validCard = false;
  int index = -1;

  do 
  {
    // construct a trivial random number generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
  
    std::uniform_int_distribution<int> distribution (0, 51);
    index = distribution(generator);

    if (deck[index] != 0) // card is drawn
    {
      // card is drawn
      deck[index] = 0;
      validCard = true;
      cardsDrawn++;
    }

  } while (validCard == false && cardsDrawn < 52);

  if (cardsDrawn == 52)
  {
    std::cout << "ERROR: Max amount of cards drawn." << std::endl;  
    return -1;
  }

  return index;
  

  // // generate random number between 1 and 13
  // int cardNum = rand() % 13 + 1;
  // // generate random number between 0 and 3
  // int cardSuit = rand() % 4;

  // std::cout << "Card: " << cardNum << SUITS[cardSuit] << std::endl;
}

// TODO: Names of the card
std::string CardName(const int &index)
{
  /**
   * @brief returns the name of the card that was drawn
   * 
   * @return String of the name and suit of the card
   */

  // getting the card value out of 13 cards
  int cardVal = (index % 13) + 1;

  // get the suit symbol from the index of the deck
  std::string cardSuit = SUITS[((index + 1) / 13) % 4];
  std::string cardName = "";

  switch(cardVal)
  {
    case(1):
      cardName = "Ace";
      break;

    case(11):
      cardName = "Jack";
      break;
    
    case(12):
      cardName = "Queen";
      break;
    
    case(13):
      cardName = "King";
      break;

    default:
      cardName = std::to_string(cardVal);
      break;
  }

  // if the card number is greater than 10 
  return cardName + cardSuit;
}

int CardNumberValue(const int &index)
{
  /**
   * @brief returns the card value from 1 to 10
   * 
   * @param index index value for the deck (52)
   * 
   * @return returns the value from 1 to 10
   */

  // getting the card value out of 13 cards
  int cardVal = (index % 13) + 1;
  if (cardVal > 10)
    cardVal = 10;
  return cardVal;
}