#include "blackjack.h"

void Blackjack::StartRound(void)
{
  /**
   * @brief Starts the game by handing out two cards each to the player and the dealer
   * 
   * @return None
   */

  // player and dealer receive two cards at the start of the round
  for (int i = 0; i < 2; i++)
  {
    player.AddCard(deck.DrawCard());
    dealer.AddCard(deck.DrawCard());
  } 
  // std::vector<int> playerHand = player.ShowCards();
  // DisplayHand(playerHand);
  // std::cout << CalculateHand(playerHand) << std::endl;
  // std::cout << ValidHand(playerHand) << std::endl;
}

void Blackjack::ResetRound(void)
{
  /**
   * @brief resets the round by reseting the player and dealer hand
   */

  player.ResetHand();
  dealer.ResetHand();
}

void Blackjack::DisplayHand(std::vector<int> hand)
{
  /**
   * @brief shows the elements in the vector passed into it
   * 
   * @param hand Not pass by reference since we are accepting a new vector
   */
  for (int i = 0; i < hand.size(); i++)
  {
    std::cout << deck.Card(hand[i]) << " ";
  } 
  std::cout << std::endl;
}

int Blackjack::CalculateHand(std::vector<int> hand)
{
  /**
   * @brief calculates the current hand. Accounts for multiple ACEs in a hand
   * 
   * @param hand vector of indexes from the deck
   * 
   * @return integer holding the total sum of the hand
   */

  // keep in mind of the ace
  int sum = 0; 
  int aceCount = 0;
  for (int i = 0; i < hand.size(); i++)
  {
    if (deck.CardNumInt(hand[i]) == 1)
    {
      sum += 11;
      aceCount++;
    }
    // check if there is an "ACE"
    else if (deck.CardNumInt(hand[i]) > 10)
    {
      sum += 10;
    }
    else
    {
      sum += deck.CardNumInt(hand[i]);
    }
  }

  // handle the ACES
  while (sum > 21 && aceCount > 0)
  {
    sum -= 10;
    aceCount--;
  }

  return sum;
}

void Blackjack::DisplayMoney(void)
{
  /**
   * @brief displays the current amount of money the player has
   */
  std::cout << "$" << player.MoneyRemaining() << std::endl;
}

// TODO: Function to determine if the card hand is valid
bool Blackjack::ValidHand(std::vector<int> hand)
{
  /**
   * @brief Determines if the current hand is valid by adding up the cards
   * 
   * @param currHand Vector that holds the user's hand of cards
   * 
   * @return boolean value that will determine if the hand is valid or not
   */
  // use the calculate current hand function above
  return (CalculateHand(hand) <= 21) ? true : false; 
}


// TODO: Function to ask the player to hit or stand and determine that result
void Blackjack::PlayerAction(void)
{
  /** 
   * @brief Asks the player to hit or stand and determines the result of the current hand
   * 
   * @param userHand Vector that holds the user's hand of cards
   * 
   * @return None
   */

  std::cout << "Do you wish to 'hit' or 'stand'?" << std::endl;


}


// TODO: Function to run the dealers turn
void Blackjack::DealerAction(void)
{
  /**
   * @brief Runs the dealer's turn until the dealer reaches cards >= 17
   * 
   * @param dealerHand Vector that holds the dealer's hand of cards
   * 
   * @return None
   */
  
  // keep drawing cards until it is over 17
  // std::cout << "Dealer's turn" << std::endl;
  std::vector<int> dealerHand = dealer.ShowCards();
  // DisplayHand(dealerHand);
  // std::cout << CalculateHand(dealerHand) << std::endl;

  
  while (CalculateHand(dealerHand) < 17)
  {
    // draw a card
    dealer.AddCard(deck.DrawCard());
    dealerHand = dealer.ShowCards();
    // DisplayHand(dealerHand);
    // std::cout << CalculateHand(dealerHand) << std::endl;
  }
}

// TODO: Function to compare the player and dealer's hand
std::string Blackjack::CompareHands(void)
{
  /**
   * @brief Compares the player's and dealer's hand to determine who had the greater total
   * 
   * @param userHand Vector that holds the user's hand of cards
   * @param dealerHand Vector that holds the dealer's hand of cards
   * 
   * @return boolean of whether the player has won, lost, or tied the dealer
   */
  std::vector<int> playerHand = player.ShowCards();
  
  // check if the player busted 
  if (!ValidHand(playerHand))
    return "lose";
  
  std::vector<int> dealerHand = dealer.ShowCards();

  // check if dealer busted
  if (!ValidHand(dealerHand))
    return "win";

  // get the sums of the cards
  int playerSum = CalculateHand(playerHand);
  int dealerSum = CalculateHand(dealerHand);

  // player wins
  if (playerSum > dealerSum)
  {
    return "win";
  }
  // player ties 
  else if (playerSum == dealerSum)
  {
    return "tied";
  }
  // player loses
  else
  {
    return "lose";
  }
}

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
  blackjack.DisplayMoney();
  blackjack.DealerAction();

  return 0;
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


