#include "player.h"

void Player::AddCard(const int &card)
{
  /**
   * @brief Function to add a card to the user's hand
   */
  currentHand.push_back(card);
}