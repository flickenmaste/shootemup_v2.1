//Last Edit 10/16/2013
//Will Gilstrap
/////////////////////
#ifndef _HIGHSCORES_H_
#define _HIGHSCORES_H_

#include <string>
#include "shootup.h"

class highScore
{
public:
	std::string line;
	void write(int scores);
	void read();
};

#endif