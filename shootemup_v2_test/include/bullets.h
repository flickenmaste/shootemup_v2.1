//Last Edit 10/15/2013
//Will Gilstrap
/////////////////////
#ifndef _BULLETS_H_
#define _BULLETS_H_

#include "vector2.h"

class bullets
{
public:
	//struct vector2{
	//	float x;
	//	float y;
	//};

	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
	bool alive;
	bool dead;

};

#endif