//Last Edit 10/23/2013
//Will Gilstrap
/////////////////////
//#define WIN32_LEAN_AND_MEAN
#include "shootup.h"

int frameCounter = 0;
void (*gameProcess)();

// entry point of the program
int main( int arc, char* argv[] )
{	
	// First we need to create our Game Framework
	Initialise(SCREEN_X, SCREEN_Y, false,"Shoot em up" );

	initGame();
	initMenu();
	initBoss();
	initGameOver();
	gameProcess = &menuState;	
	do {
		frameCounter++;

		if(frameCounter > 5000)
			frameCounter = 0;
		
		gameProcess();	// function pointer to run game
		
	} while ( FrameworkUpdate() == false );
	// clean up memory
	destroyGame();
	destroyMenu();
	destroyBoss();
	destroyGameOver();
	
	Shutdown();

	return 0;
}