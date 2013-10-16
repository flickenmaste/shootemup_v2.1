//Last Edit 10/16/2013
//Will Gilstrap
/////////////////////
#ifndef _HIGHSCORES_H_
#define _HIGHSCORES_H_

#include <string>
#include "shootup.h"

static class highScore
{
public:
	std::string line;
	void write(int scores);
	void read();
};

#endif