#include "gameplay.h"

void Blackjack(void)
{
  int deck[DECK_SUITS][DECK_NUMS] = {0};


  int money = 1000;
  bool running = true;

  // game logic sequence
  // 1. player will be welcomed
  // 2. dealer will pass out cards 
  // 3. present the actions the player can do with the cards (hit/stand)
  // 4. determine the result from the dealer
  // 5. repeat until money is gone

  DeckInit(deck);
  PrintDeck(deck);
  
  WelcomeScreen(running);

  for (int i = 0; i < 5; i++)
  {
    DrawCard();
  }
  // while(running)
  // {
    // menu screen
    // options:
      // 1. rules and how to play
      // 2. play the game
      // 3. exit the game

      
    // display the amount of money the player currently has
    // cout << "Bank: $" << money << endl;
    // wait for player to hit a key to start the game
    // cin >> i;

    // pass out cards
    // cout << "passing out cards!" << endl;
    // cin >> j;

    // loop
      // ask the player if they want to "hit" or "stand"

    // calculate the results of the current round
  // }

  // std::cout << "Game over :(" << std::endl;

}


void WelcomeScreen(bool& exit)
{
  system("clear");
  std::cout << "Welcome to Blackjack!" << std::endl;
  // present some options
  // how to play
  // play
  // exit

  std::cout << "Select an option below from the menu:" << std::endl;
  std::cout << "1. Rules and How to Play Blackjack" << std::endl;
  std::cout << "2. Play Blackjack" << std::endl;
  std::cout << "3. Exit Program" << std::endl;

  int option = 0;
  std::cin >> option;

  switch(option)
  {
    case 1:
      std::cout << "This is how you play blackjack boi" << std::endl;
      break;

    case 2: 
      std::cout << "Let's play blackjack!" << std::endl;
      break;

    case 3:
      std::cout << "Exiting program" << std::endl;
      exit = false;
      break;
    
    default:
      std::cout << "Umm that is not an option man" << std::endl;
      break;
  }
}

