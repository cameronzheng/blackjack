#include "menu.h"

// functions for the menu screen

void WelcomeScreen(void)
{
  system("clear");
  std::cout << "Welcome to Blackjack!" << std::endl;
  // present some options
  // how to play
  // play
  // exit
}

// TODO: Function for menu options
void Menu(bool& exit)
{
  /**
   * @brief Displays the options in the menu that the player can choose from
   * 
   * @param option The option the player has chosen
   * 
   * @return None
   */
  std::cout << "Select an option below from the menu:" << std::endl;
  std::cout << "1. Rules and How to Play Blackjack" << std::endl;
  std::cout << "2. Play Blackjack" << std::endl;
  std::cout << "3. Exit Program" << std::endl;

  int option = 0;
  std::cin >> option;

  switch(option)
  {
    case 1:
      Rules();
      break;

    case 2: 
      std::cout << "Let's play blackjack!" << std::endl;
      break;

    case 3:
      std::cout << "Exiting program" << std::endl;
      exit = true;
      break;
    
    default:
      std::cout << "Umm that is not an option man" << std::endl;
      break;
  }
}

void Rules(void)
{
  /**
   * @brief describes the rules of blackjack and how to play
   * 
   * @return none
   */
  std::cout << "This is how you play blackjack boi" << std::endl;

  char exit = ' ';
  std::cout << "\nPress Enter to exit rules";
  std::cin >> exit;
  std::cout << std::endl;
}
