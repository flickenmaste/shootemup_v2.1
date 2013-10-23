//Last Edit 10/22/2013
//Will Gilstrap
/////////////////////
#pragma once
#ifndef _SHOOTUP_H_
#define _SHOOTUP_H_

#include "AIE.h"
//#include "KeyCodes.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <ctime>
#include <iostream>
#include <vector>
//#include "vector2.h"
#include "gameStates.h"
#include "movableObject.h"
#include "bullets.h"
#include "highScores.h"
#include "moveFilter.h"

using namespace std;

extern void (*gameProcess)();

// Global consts
const int SPEED = 10;
const int SCREEN_X = 1280;
const int SCREEN_Y = 780;

const int PLAYER1_X = 100;
const int PLAYER1_W = 100;
const int PLAYER1_H = 50;

// functions
// collision
bool checkCollision(movableObject& obj1, bullets& obj2);
bool checkCollision(movableObject& obj1, movableObject& obj2);
bool checkCollision(movableObject& obj1, enemybullets& obj2);
// player movement/shoot
void seekX(movableObject &player, movableObject& ball);
void seekY(movableObject &player, movableObject& ball);
void movePlayer(movableObject& obj);
void playerShoot(bullets& obj, bullets& obj2, bullets& obj3);
void ifAlive(bullets& obj, bullets& obj2, bullets& obj3);
int getPlayerLocationX();
int getPlayerLocationY();
void ifDead(bullets& obj, bullets& obj2, bullets& obj3);
// enemy functions
void spawnEnemy(movableObject& obj);
void resetEnemy(movableObject& obj);
void spawnEnemySide(movableObject& obj);
void resetEnemySide(movableObject& obj);
void enemyShoot(enemybullets& obj);
void enemyShoot(int x, int y);
void bossShoot(int x, int y);
bool checkCollision(movableObject& obj1);
// game stuff
void initGame();
void destroyGame();
void checkEnemyCollision();
void updateGame();
void drawGame();
void writeHS();

#endif