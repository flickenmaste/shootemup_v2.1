//Last Edit 10/29/2013
//Will Gilstrap
/////////////////////
#pragma once

#include "shootup.h"

// global vars
unsigned int bgImage = -1;
unsigned int bgMenu = -1;
unsigned int bgGameOver = -1;
movableObject splash = {SCREEN_X/2, SCREEN_Y/2, 0, 0, -1 , SCREEN_X, SCREEN_Y};
movableObject player1 = {687, 386, 0, 0, -1 , 100, 50};
bullets playerBullet = {-100, 0, 0, 4, -1 , 10, 10, false, true};
bullets playerBullet2 = {-100, 0, -4, 4, -1 , 10, 10, false, true};
bullets playerBullet3 = {-100, 0, -4, 4, -1 , 10, 10, false, true};
movableObject enemy = {-500, 800, 0, 1, -1 , 50, 50};
movableObject enemy2 = {-500, 800, 0, 1, -1 , 50, 50};
movableObject enemy3 = {0, 0, 0, 1, -1 , 50, 50};
movableObject boss = {SCREEN_X / 2, SCREEN_Y / 6, 0, 1, -1 , 100, 100};
movableObject enemyB1 = {0, 0, 0, 1, -1 , 50, 50};
movableObject enemyB2 = {0, 0, 0, 1, -1 , 50, 50};
enemybullets enemyBullet = {600, -10, 0, 4, -1 , 10, 10, false, true};
movableObject playGame = {SCREEN_X / 2, SCREEN_Y / 2 + 50, 0, 0, -1 , 100, 30};
movableObject exitMenu = {SCREEN_X / 2, SCREEN_Y / 2 + 100, 0, 0, -1 , 100, 30};
bool g_gameOver = false;
bool menuEnd = false;
unsigned int scores = 0;
//vector<bullets> bulletLoaded;
//vector<bullets> bulletLoaded2;
//vector<bullets> bulletLoaded3;
enemybullets enemyHell[10];
enemybullets bossShot[10];
enemybullets bossShot2[10];
enemybullets miniShot[2];
int player1Score = 0;
highScore h;
unsigned int checkKilled = 0;
float circle = 10;
int bossHP = 2000;
int tick = 0;