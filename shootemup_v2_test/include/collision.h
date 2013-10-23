//Last Edit 10/23/2013
//Will Gilstrap
/////////////////////
#ifndef _COLLISION_H_
#define _COLLISION_H_

#include "shootup.h"

class collision
{
public:
	bool checkCollision(movableObject& obj1, bullets& obj2);
	bool checkCollision(movableObject& obj1, movableObject& obj2);
	bool checkCollision(movableObject& obj1, enemybullets& obj2);
};


#endif