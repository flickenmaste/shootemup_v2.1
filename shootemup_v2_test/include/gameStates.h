//Last Edit 10/16/2013
//Will Gilstrap
/////////////////////
#ifndef _GAMESTATES_H_
#define _GAMESTATES_H_

#include "shootup.h"

// functions for game states
void initMenu();
void updateMenu();
void drawMenu();
void destroyMenu();
void menuState();
void playState();
void initGameOver();
void updateGameOver();
void drawGameOver();
void destroyGameOver();
void gameOverState();

#endif