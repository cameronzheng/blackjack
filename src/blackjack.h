#pragma once

#include "general.h"
#include <stdlib.h>
#include <cstdlib>

void test(void);

void Blackjack(void);
// void WelcomeScreen(bool& running);
void Menu(void);

void DisplayMoney(const double& money);
int CalculateHand(void);
void StartingHandDraw(std::vector<int> &userHand, std::vector<int> &dealerHand, int (&deck)[CARDS], int &cardsDrawn);