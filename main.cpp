#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

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
  welcome();
  
  while(running)
  {
    // clear the screen
    system("clear");
    // display the amount of money the player currently has
    cout << "Bank: $" << money << endl;
    // wait for player to hit a key to start the game
    cin >> i;

    // pass out cards
    cout << "passing out cards!" << endl;
    cin >> j;

    // loop
      // ask the player if they want to "hit" or "stand"

    // calculate the results of the current round



  }

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