#include "deck.h"

Deck::Deck()  // constructor
{
  DECK_SIZE = 52;
  DECK = new int[DECK_SIZE];
  ResetDeck();
}

Deck::Deck(int deckSize)  // overloaded constructor
{
  DECK_SIZE = deckSize;
  DECK = new int[DECK_SIZE];
  ResetDeck();
}

Deck::~Deck() // destructor
{
  delete[] DECK;  // free allocated memory from DECK
}

void Deck::ResetDeck(void)
{
  /**
   * @brief Resets the deck to have all the cards
   * 
   * @return 
   */
  // make sure the deck has cards in it
  if (sizeof(DECK) > 0)
  {
    cardsDrawn = 0;
    for (int i = 0; i < DECK_SIZE; i++)
    {
      DECK[i] = 1;
    }
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
void Deck::PrintDeck(void)
{

  // sizeof(SUITS[0]): 8 bits for the pointer, size, and capacity 
  // sizeof(SUITS): total size of the array including the SUITS[0], SUITS[1]...
  int numberOfSuits = sizeof(SUITS) / sizeof(SUITS[0]);

  for (int suit = 0; suit < numberOfSuits; suit++)
  {
    std::cout << SUITS[suit] << ": ";
    for (int number = 0; number < (DECK_SIZE/numberOfSuits); number++)
    {
      std::cout << DECK[(13 * suit) + number] << " ";
    }
    std::cout << std::endl;
  }
}

/*
TODO: how to draw a card
needs to take in a random suit and a random value from 0 to 12 (plus one since we are going from 1 to King)

*/
int Deck::DrawCard(void)
{
  /**
   * @brief Draws a random card from the deck.
   * 
   * @return integer containing the index of the card from the deck
   */
  bool validCard = false;

  if (cardsDrawn == 52)
  {
    std::cout << "The max amount of cards have been drawn, reset the deck" << std::endl;
    return -1;
  }

  int card;

  while (validCard == false)
  {
    // using uniform integer distribution
  
    // construct a trivial random number generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
  
    std::uniform_int_distribution<int> distribution (0, DECK_SIZE);
  
    card = distribution(generator);

    if (DECK[card] == 1)
    {
      cardsDrawn++;
      DECK[card] = 0;
      validCard = true;
    }
  }

  return card;

  // // generate random number between 1 and 13
  // int cardNum = rand() % 13 + 1;
  // // generate random number between 0 and 3
  // int cardSuit = rand() % 4;

  // std::cout << "Card: " << cardNum << SUITS[cardSuit] << std::endl;
}

std::string Deck::CardSuit(const int &cardIndex)
{
  /**
   * @brief Gets the suit of the card
   * 
   * @param cardIndex the index of the card in the deck
   * 
   * @return String of the suit the card has
   */

  return SUITS[cardIndex / 13];
   
}

int Deck::CardNumInt(const int &cardIndex)
{
  /**
   * @brief Gets the number value of the card
   * 
   * @param cardIndex the index of the card in the deck
   * 
   * @return Integer of the number value
   */

  return (cardIndex % 13) + 1;
}

std::string Deck::CardNumStr(const int &cardIndex)
{
  /**
   * @brief Gets the string value of the number drawn
   * 
   * @return String of the numerical value of the card drawn
   */

  switch(CardNumInt(cardIndex))
  {
    case 1:
      return "Ace";
    case 2:
      return "2";
    case 3:
      return "3";
    case 4:
      return "4";
    case 5: 
      return "5";
    case 6:
      return "6";
    case 7:
      return "7";
    case 8: 
      return "8";
    case 9: 
      return "9";
    case 10: 
      return "10";
    case 11: 
      return "Jack";
    case 12: 
      return "Queen";
    case 13:
      return "King";
    default:
      return "...";
  }
}



std::string Deck::Card(const int &cardIndex)
{
  /**
   * @brief The string of the card itself
   * 
   * @return String of the card
   */
  return CardNumStr(cardIndex) + CardSuit(cardIndex);
}

// int main()
// {
//   Deck deck;

//   deck.PrintDeck();
//   int card;

//   for (int i = 0; i < 10; i++)
//   {
//     card = deck.DrawCard();
//     std::cout << "Card index drawn: " << card << std::endl;
//     std::cout << "Card drawn: " << deck.Card(card) << std::endl;
//     // std::cout << "Card suit: " << deck.CardSuit(card) << std::endl; 
//     // std::cout << "Card val: " << deck.CardNum(card) << std::endl;
//     // std::cout << "Card: " << deck.CardNum(card) << deck.CardSuit(card) << std::endl;
//     deck.PrintDeck();
//   }

//   // deck.PrintDeck();
//   return 0;
// }