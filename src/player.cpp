#include "player.h"

Player::Player()
{
  moneyTotal = 1000;
}

void Player::AddCard(const int &card)
{
  /**
   * @brief Function to add a card to the user's hand
   */
  currentHand.push_back(card);
}

std::vector<int> Player::ShowCards(void)
{
  /**
   * @brief displays the cards in the player's hand
   */
  return currentHand;
}

void Player::ResetHand(void)
{
  /**
   * @brief Resets the player's hand
   * 
   * @return None
   */

  if (currentHand.empty() == false)
  {
    // std::cout << currentHand.size() << std::endl;
    currentHand.pop_back();
    currentHand.erase(currentHand.begin(), currentHand.end());
  }
}

int Player::MoneyRemaining(void)
{
  /**
   * @brief returns the amount of money remaining
   * 
   * @return integer value of the money
   */
  return moneyTotal;
}

bool Player::ValidBet(int &bet)
{
  /**
   * @brief determines if the bet is valid
   * 
   * @param bet total bet the player placed
   * 
   * @return boolean value whether the bet is valid or not
   */
  return (bet <= moneyTotal) ? true : false;
}