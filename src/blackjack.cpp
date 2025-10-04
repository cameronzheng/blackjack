#include "blackjack.h"

void Blackjack::StartRound(void)
{
  /**
   * @brief Starts the game by handing out two cards each to the player and the dealer
   * 
   * @return None
   */
  // player.AddCard(deck.DrawCard());
  //  dealer.AddCard(deck.DrawCard());
  //  player.AddCard(deck.DrawCard());
  //  dealer.AddCard(deck.DrawCard());

  //  player.ShowCards();
  //  dealer.ShowCards();
}
// void Blackjack(void)
// {
//   int deck[DECK_SUITS][DECK_NUMS] = {0};


//   int money = 1000;
//   bool running = true;

//   // game logic sequence
//   // 1. player will be welcomed
//   // 2. dealer will pass out cards 
//   // 3. present the actions the player can do with the cards (hit/stand)
//   // 4. determine the result from the dealer
//   // 5. repeat until money is gone

//   DeckInit(deck);
//   PrintDeck(deck);
  
//   WelcomeScreen(running);

//   for (int i = 0; i < 5; i++)
//   {
//     DrawCard();
//   }

//   // game pseudo code

//   /*
//     1. If the player enters a certain number on the menu screen, we will enter the gameplay screen
//     2. Displays the amount of money the player has to bet, cards in the deck
//     3. Pass out cards to the dealer and the player. Player first then dealer. Two cards each
//     4. Player should be asked to hit or stand. Hit adds a card to their hand. Stand makes them not draw a card
//     5. Calculate the players hand to make sure it is <= 21. If hand > 21, this is a bust and the dealer automatically wins
//     6. If the player is still in the game, the dealer will start to draw cards as well. if their total reaches >= 17, they will stop hitting. 
//     7. Compare their hand to the players hand and determine the result.
//     8. If the player wins, give them 1.5x their bet. Player loses, they will lose their bet.

//   */

//   // while loop
//     // ask the user for their menu option
//       // 1. Rules
//       // 2. Play the game
//       // 3. exit the program
//     // switch statement
//       // 1. run the rules function
//       // 2. run the game function
//       // 3. exit the program
//       // default: display that is not an option
      
      
//     // once an option is picked, we need to clear the screen

// }


// TODO: Function to display the total amount of money the player has
  /**
   * @brief Displays the total amount of money the player has
   * 
   * @param None
   * 
   * @return None
   */

// TODO: Function to calculate the current hand total
/**
 * @brief Calculates the current hands total
 * 
 * @param handOfCards vector that is dynamically sized for the current hand
 * 
 * @return Returns the total amount the hand adds up to
 */

// TODO: Function to draw two cards each for the Blackjack game (start of the game)
/**
 * @brief Draws two cards each for the blackjack game to start the game
 * 
 * @param userHand Vector for the user's hand of cards
 * @param dealerHand Vector for the dealer's hand of cards
 * 
 * @return None
 */

// TODO: Function to determine if the card hand is valid
/**
 * @brief Determines if the current hand is valid by adding up the cards
 * 
 * @param currHand Vector that holds the user's hand of cards
 * 
 * @return boolean value that will determine if the hand is valid or not
 */
// use the calculate current hand function above


// TODO: Function to ask the player to hit or stand and determine that result
/** 
 * @brief Asks the player to hit or stand and determines the result of the current hand
 * 
 * @param userHand Vector that holds the user's hand of cards
 * 
 * @return None
 */


// TODO: Function to run the dealers turn
/**
 * @brief Runs the dealer's turn until the dealer reaches cards >= 17
 * 
 * @param dealerHand Vector that holds the dealer's hand of cards
 * 
 * @return None
 */

// TODO: Function to compare the player and dealer's hand
/**
 * @brief Compares the player's and dealer's hand to determine who had the greater total
 * 
 * @param userHand Vector that holds the user's hand of cards
 * @param dealerHand Vector that holds the dealer's hand of cards
 * 
 * @return boolean of whether the player has won (True) or lost (False)
 */

// TODO: Function to calculate the total winnings for the player
/**
 * @brief Calcualtes the amount of money the player wins after winning the round
 * 
 * @param userBet The total amount of money the user bet during this round of play
 * 
 * @return integer value of the amount of money the player has won
 */

// ? Extra rules later

int main()
{
  Blackjack blackjack;
  blackjack.StartRound();
  return 0;
}