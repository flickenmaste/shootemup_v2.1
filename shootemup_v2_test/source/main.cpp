//Last Edit 10/15/2013
//Will Gilstrap
/////////////////////
#include "shootup.h"

int frameCounter = 0;
void (*gameProcess)();

// entry point of the program
int main( int arc, char* argv[] )
{	
	// First we need to create our Game Framework
	Initialise(SCREEN_X, SCREEN_Y, false );
	/*
	initMenu();
	menuProcess = &updateMenu;
	do {
		menuProcess();
	} while (menuEnd == false);
	*/
	initGame();
	initMenu();
	initGameOver();
	gameProcess = &menuState;	
	do {
		frameCounter++;

		if(frameCounter > 5000)
			frameCounter = 0;
		
		gameProcess();
		
	} while ( FrameworkUpdate() == false );

	destroyGame();
	
	Shutdown();

	return 0;
}