//Last Edit 10/16/2013
//Will Gilstrap
/////////////////////
#ifndef _MOVABLEOBJECT_H_
#define _MOVABLEOBJECT_H_

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