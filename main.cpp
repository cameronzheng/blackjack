#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

// User defined files
// #include "deck.h"

#define DECK_SUITS 4
#define DECK_NUMS 13

const string SPADE = "\u2664";
const string HEART = "\u2665";
const string DIAMOND = "\u2666";
const string CLUB = "\u2667";

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


int deck[DECK_SUITS][DECK_NUMS];

// deck functions
void deckInit(void);

void welcome();

int main()
{
  int money = 1000;
  bool running = true;
  string action;
  char i, j;

  // game logic sequence
  // 1. player will be welcomed
  // 2. dealer will pass out cards 
  // 3. present the actions the player can do with the cards (hit/stand)
  // 4. determine the result from the dealer
  // 5. repeat until money is gone
  // welcome();

  deckInit();
  cout << SPADE << endl;
  cout << DIAMOND << endl;
  cout << CLUB << endl;
  cout << HEART << endl;
  
  // while(running)
  // {
  //   // clear the screen
  //   system("clear");
  //   // display the amount of money the player currently has
  //   cout << "Bank: $" << money << endl;
  //   // wait for player to hit a key to start the game
  //   cin >> i;

  //   // pass out cards
  //   cout << "passing out cards!" << endl;
  //   cin >> j;

  //   // loop
  //     // ask the player if they want to "hit" or "stand"

  //   // calculate the results of the current round
  // }

  cout << "Game over :(" << endl;

  return 0;
}

void welcome()
{
  cout << "Hi Welcome to Blackjack!" << endl;
  cout << "Would you like to go over the rules? Press y for rules. Any other key to continue." << endl;
}

void rules()
{
  system("clear");
  cout << "Here are the rules of Blackjack!" << endl;
}


// puts all the cards in the deck
void deckInit(void)
{
  for (int i = 0; i < DECK_SUITS; i++)
  {
    for (int j = 0; j < DECK_NUMS; j++)
    {
      deck[i][j] = 1;
    }
  }
}