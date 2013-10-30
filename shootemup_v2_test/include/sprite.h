//Last Edit 10/29/2013
//Will Gilstrap
/////////////////////
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "vector2.h"

class movableObject
{
public:
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
};

#endif