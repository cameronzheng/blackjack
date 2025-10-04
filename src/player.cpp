#include "player.h"

Player::Player(Deck &deck)
{

}

void Player::AddCard(const int &card)
{
  /**
   * @brief Function to add a card to the user's hand
   */
  currentHand.push_back(card);
}

void Player::ShowCards(void)
{
  /**
   * @brief displays the cards in the player's hand
   */
  for (int i = 0; i < currentHand.size(); i++)
  {
    std::cout << currentHand[i] << ' ';
  }
  std::cout << std::endl;
}