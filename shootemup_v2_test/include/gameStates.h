//Last Edit 10/21/2013
//Will Gilstrap
/////////////////////
#ifndef _GAMESTATES_H_
#define _GAMESTATES_H_

#include "shootup.h"

// functions for game states
// Menu functions
void initMenu();
void updateMenu();
void drawMenu();
void destroyMenu();
void menuState();
// Play state
void playState();
// Game Over functions
void initGameOver();
void updateGameOver();
void drawGameOver();
void destroyGameOver();
void gameOverState();

#endif