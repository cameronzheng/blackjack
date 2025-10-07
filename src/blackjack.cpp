#include "blackjack.h"

void Blackjack::Menu(void)
{
  /**
   * @brief menu to display to the user the options
   */
  bool exit = false;
  int userInput;

  while(!exit)
  {
    system("clear");
    // menu to display various options
     // 1. how to play
     // 2. gameplay
     // 3. exit the game
    std::cout << "Select an option from the menu below: " << std::endl;
    std::cout << "1. How to play Blackjack" << std::endl;
    std::cout << "2. Play Blackjack" << std::endl;
    std::cout << "3. Exit program" << std::endl;

    std::cin >> userInput;

    switch(userInput)
    {
      case 1:
        std::cout << "This is how you play blackjack" << std::endl;
        break;

      case 2: 
        Gameplay();
        break;

      case 3: 
        std::cout << "Exiting game :(" << std::endl;
        exit = true;
        break;

      default:
        std::cout << "That is not an option. Please select a valid opiton" << std::endl;
        break;
    }
  }
}

void Blackjack::Gameplay(void)
{
  /**
   * @brief runs the game of blackjack
   */

  // check if the player has enough money
   // display the money
   // start a round
   // ask user if they want to keep playing

  bool exit = false;
  char userChoice;
  round = 1;
  lastMove = "";
  while (!exit)
  {
    Round();

    std::cout << "Do you want to keep playing? (y/n): ";
    std::cin >> userChoice;

    if (userChoice == 'n')
      exit = true;
  }

  // display the results of the round

}

void Blackjack::Round(void)
{
  /**
   * @brief starts the round for blackjack
   */

   // playing the game
   // ask the player to put in bets before the game starts
  // loop till the player puts an acceptable amount of money
  do
  {
    bet = 0;
    Scoreboard(); 
    std::cout << "Place your bet: " << std::endl;
    std::cin >> bet;

  } while (!player.ValidBet(bet));
  
  // get the round started
  StartRound();       // draw the two cards for the player and the dealer to start the round
  PlayerAction();     // ask the player for their action
  DealerAction();     // dealer does their action
  CompareHands();     // compare the player and dealer's hand
  CalculateRound();   // give out money based on results
  round++;
}

void Blackjack::Scoreboard(void)
{
  /**
   * @brief Displays the following:
   * ---------- Round 1 ----------
   * Money Remaining: $1000 
   * Current Bet:
   * -----------------------------
   * Dealer's Hand: 
   * Player's Hand:
   * -----------------------------
   * Last Move: 
   * -----------------------------
   * ~Displays current round action~
   */
  playerHandStr = CardsToStringVec(playerHand);
  dealerHandStr = CardsToStringVec(dealerHand);
  system("clear");
  std::cout << "---------- Round " << round << " ----------" << std::endl;
  std::cout << "Money Remaining: $" << player.MoneyRemaining() - bet << std::endl;
  std::cout << "Current Bet: $" << bet << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Dealer's Hand: ";
  for (int i = 0; i < dealerHandStr.size(); i++)
    std::cout << dealerHandStr[i] << " ";
  std::cout << std::endl;

  std::cout << "Player's Hand: ";
  for (int i = 0; i < playerHandStr.size(); i++)
    std::cout << playerHandStr[i] << " ";
  if (bust)
    std::cout << "BUST";
  std::cout << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Hand Total: " << CalculateHand(playerHand) << std::endl;
  std::cout << "Last Move: " << lastMove << std::endl;
  std::cout << "-----------------------------" << std::endl;
}

void Blackjack::StartRound(void)
{
  /**
   * @brief Starts the game by handing out two cards each to the player and the dealer
   * 
   * @return None
   */

  bust = false;
  // player and dealer receive two cards at the start of the round
  for (int i = 0; i < 2; i++)
  {
    player.AddCard(deck.DrawCard());
    dealer.AddCard(deck.DrawCard());
  } 
}

void Blackjack::ResetRound(void)
{
  /**
   * @brief resets the round by reseting the player and dealer hand
   */

  player.ResetHand();
  dealer.ResetHand();

}

std::vector<std::string> Blackjack::CardsToStringVec(std::vector<int> hand)
{
  /**
   * @brief shows the elements in the vector passed into it
   * 
   * @param hand Not pass by reference since we are accepting a new vector
   * 
   * @return vecotr of strings that contains the cards in the hand
   */
  std::vector<std::string> cards;

  for (int i = 0; i < hand.size(); i++)
  {
    cards.push_back(deck.Card(hand[i]));
    // std::cout << deck.Card(hand[i]) << " ";
  } 
  // std::cout << std::endl;
  return cards;
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

  int userSelection = 0;
  bool exit = false;
  playerHand = player.ShowCards();
  bool error = false;

  while(!exit)
  {
    Scoreboard();
    if (error)
      std::cout << "ERROR: Not a valid selection, please choose again" << std::endl;
    std::cout << "Select one of the options below:" << std::endl;
    std::cout << "1. Hit" << std::endl;
    std::cout << "2. Stand" << std::endl;

    std::cin >> userSelection;
    switch(userSelection)
    {
      case 1:
        lastMove = "Hit";
        player.AddCard(deck.DrawCard());
        playerHand = player.ShowCards();
        break;
      case 2: 
        lastMove = "Stand";
        exit = true;
        break;
      default:
        error = true;
        break;
    }

    // calculate the player's hand to see if they can still do an action
    if (CalculateHand(playerHand) > 21)
    {
      bust = true;
      exit = true;
    }
  }
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
  dealerHand = dealer.ShowCards();
  // DisplayHand(dealerHand);
  // std::cout << CalculateHand(dealerHand) << std::endl;
  // DisplayHand(dealerHand);
  // std::cout << "Total: " << CalculateHand(dealerHand) << std::endl;

  
  while (CalculateHand(dealerHand) < 17)
  {
    // draw a card
    // std::cout << "HIT!" << std::endl;

    dealer.AddCard(deck.DrawCard());
    dealerHand = dealer.ShowCards();
    
    // DisplayHand(dealerHand);
    // std::cout << "Total: " << CalculateHand(dealerHand) << std::endl;
  }
}

// TODO: Function to compare the player and dealer's hand
void Blackjack::CompareHands(void)
{
  /**
   * @brief Compares the player's and dealer's hand to determine who had the greater total
   * 
   * @param userHand Vector that holds the user's hand of cards
   * @param dealerHand Vector that holds the dealer's hand of cards
   * 
   * @return boolean of whether the player has won, lost, or tied the dealer
   */
  playerHand = player.ShowCards();
  
  // check if the player busted 
  if (!ValidHand(playerHand))
    roundResult = "Lose";
  
  dealerHand = dealer.ShowCards();

  // check if dealer busted
  if (!ValidHand(dealerHand))
    roundResult = "Win";

  // get the sums of the cards
  int playerSum = CalculateHand(playerHand);
  int dealerSum = CalculateHand(dealerHand);

  // player wins
  if (playerSum > dealerSum)
  {
    roundResult = "Win";
  }
  // player ties 
  else if (playerSum == dealerSum)
  {
    roundResult = "Tie";
  }
  // player loses
  else
  {
    roundResult = "Lose";
  }
}

// TODO: Function to calculate the total winnings for the player
void Blackjack::CalculateRound(void)
{
  /**
   * @brief Calcualtes the amount of money the player wins or loses based on round
   * 
   * @param userBet The total amount of money the user bet during this round of play
   * 
   * @return integer value of the amount of money the player has won
   */

  if (roundResult == "Win")
  {
    // add to the player's total
    player.AddTotal(bet);
  }
  else if (roundResult == "Lose")
  {
    // subtract the bet from the total
    player.SubTotal(bet);
  }
  // else is a tie, which we don't change anything
}

// ? Extra rules later

int main()
{
  
  Blackjack blackjack;
  blackjack.Menu();
  // blackjack.StartRound();
  // blackjack.PlayerAction();
  // blackjack.DealerAction();

  // std::cout << blackjack.CompareHands() << std::endl;
  // blackjack.DisplayMoney();
  // blackjack.DealerAction();

  return 0;
}