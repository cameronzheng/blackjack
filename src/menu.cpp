#include "menu.h"

// functions for the menu screen

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

// TODO: Function for menu options
/**
 * @brief Displays the options in the menu that the player can choose from
 * 
 * @param option The option the player has chosen
 * 
 * @return None
 */


