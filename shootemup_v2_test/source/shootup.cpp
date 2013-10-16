//Last Edit 10/16/2013
//Will Gilstrap
/////////////////////
#include "shootup.h"

// global vars
unsigned int bgImage = -1;
unsigned int bgFilterRed = -1;
unsigned int bgFilterBlue = -1;
unsigned int bgMenu = -1;
unsigned int bgGameOver = -1;
movableObject player1 = {687, 386, 0, 0, -1 , 100, 50};
bullets playerBullet = {0, 0, 0, 4, -1 , 10, 10, false, true};
bullets playerBullet2 = {0, 0, -4, 4, -1 , 10, 10, false, true};
bullets playerBullet3 = {0, 0, -4, 4, -1 , 10, 10, false, true};
movableObject enemy = {-500, 800, 0, 1, -1 , 50, 50};
movableObject enemy2 = {-500, 800, 0, 1, -1 , 50, 50};
movableObject playGame = {SCREEN_X / 2, SCREEN_Y / 2 + 50, 0, 0, -1 , 100, 30};
movableObject exitMenu = {SCREEN_X / 2, SCREEN_Y / 2 + 100, 0, 0, -1 , 100, 30};
bool g_gameOver = false;
bool menuEnd = false;
unsigned int scores = 0;
vector<bullets> bulletLoaded;
//vector<bullets> bulletLoaded2;
//vector<bullets> bulletLoaded3;
int player1Score = 0;
highScore h;

// check collision of bullet and enemy
bool checkCollision(movableObject& obj1, bullets& obj2) {
	int x; int y;
	GetMouseLocation(x,y);
	double rE = obj1.position.x;
	double radiusEnemy = 25;

	double rB = obj2.position.x;
	double radiusBullet = 5;

	double distX = obj1.position.x - obj2.position.x;
	double distY = obj1.position.y - obj2.position.y;

	double dist = sqrt((distX * distX) + (distY * distY));
	double radii = (radiusEnemy + radiusBullet) * (radiusEnemy + radiusBullet);

	if (dist < radiusEnemy + radiusBullet)
		return true;
	else
		return false;
}
// check collision of enemy and player
bool checkCollision(movableObject& obj1, movableObject& obj2) {
	int x; int y;
	GetMouseLocation(x,y);
	double rE = obj1.position.x;
	double radiusEnemy = 25;

	double rB = obj2.position.x;
	double radiusBullet = 25;

	double distX = obj1.position.x - obj2.position.x;
	double distY = obj1.position.y - obj2.position.y;

	double dist = sqrt((distX * distX) + (distY * distY));
	double radii = (radiusEnemy + radiusBullet) * (radiusEnemy + radiusBullet);

	if (dist < radiusEnemy + radiusBullet)
		return true;
	else
		return false;
}

void seekX(movableObject &player, movableObject& ball) // code to make the player sprite follow behind mouse
{
	float speed = 1;

	if(player.position.x < ball.position.x - speed) {
		int diff = ball.position.x - player.position.x;
		if(diff > speed)
			player.position.x += speed;
		else
			player.position.x += diff;
	}
	else if (player.position.x > ball.position.x + speed) {
		int diff = player.position.x - ball.position.x;
		if(diff > speed)
			player.position.x -= speed;
		else
			player.position.x -= diff;
	}
}

void seekY(movableObject &player, movableObject& ball) // code to make the player sprite follow behind mouse
{
	float speed = 1;

	if(player.position.y < ball.position.y - speed) {
		int diff = ball.position.y - player.position.y;
		if(diff > speed)
			player.position.y += speed;
		else
			player.position.y += diff;
	}
	else if (player.position.y > ball.position.y + speed) {
		int diff = player.position.y - ball.position.y;
		if(diff > speed)
			player.position.y -= speed;
		else
			player.position.y -= diff;
	}
}

void movePlayer(movableObject& obj)	// function to make the player sprite follow mouse
{
	int x; int y;
	GetMouseLocation(x,y);
	//obj.position.x = x;
	//obj.position.y = y;
	movableObject mouse = {x, y, 0, 0, -1 , 50, 50};
	if (x <= SCREEN_X) // to keep player going off screen
		seekX(player1, mouse);
	if (y <= SCREEN_Y)	// to keep player going off screen
		seekY(player1, mouse);
	MoveSprite(player1.sprite, player1.position.x, player1.position.y);
	return;
}

void playerShoot(bullets& obj, bullets& obj2, bullets& obj3)	// function to test if player is shooting or not
{
	// bullet 1
	int x; int y;
	GetMouseLocation(x,y);
	if (obj.position.y < 0)
	obj.dead = true;
	else
		obj.dead = false;
	if (obj.position.y < 0)
	obj.dead = true;
	else
		obj.dead = false;
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true)
	obj.alive = true;
	

	// bullet 2
	if (obj2.position.y < 0 || obj2.position.x < 0)
	obj2.dead = true;
	else
		obj2.dead = false;
	if (obj2.position.y < 0 || obj2.position.x < 0)
	obj2.dead = true;
	else
		obj2.dead = false;
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true)
	obj2.alive = true;
	

	//bullet 3
	if (obj3.position.y < 0)
	obj3.dead = true;
	else
		obj3.dead = false;
	if (obj3.position.y < 0)
	obj3.dead = true;
	else
		obj3.dead = false;
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true)
	obj3.alive = true;
	

	return;
}

void ifAlive(bullets& obj, bullets& obj2, bullets& obj3)	// function executed if player is shooting
{
	//bullet 1
	obj.position.y -= obj.speed.y;
	//bullet 2
	obj2.position.x -= 1;
	obj2.position.y -= obj2.speed.y;
	//bullet 3
	obj3.position.x += 1;
	obj3.position.y -= obj3.speed.y;

}

int getPlayerLocationX()
{
	int locX = player1.position.x;
	return locX;
}

int getPlayerLocationY()
{
	int locY = player1.position.y;
	return locY;
}

void ifDead(bullets& obj, bullets& obj2, bullets& obj3)	// executed if bullets leave screen
{
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true) {
	// bullet 1
	int x; int y;
	x = getPlayerLocationX(); y = getPlayerLocationY();
	//GetMouseLocation(x,y);
	if (obj.position.y < 0)
	obj.position.x = x;
	if (obj.position.y < 0)
	obj.position.y = y;

	// bullet 2
	if (obj2.position.y < 0 || obj2.position.x < 0)
	obj2.position.x = x;
	if (obj2.position.y < 0 || obj2.position.x < 0)
	obj2.position.y = y;

	//bullet 3
	if (obj3.position.y < 0)
	obj3.position.x = x;
	if (obj3.position.y < 0)
	obj3.position.y = y;

	playerBullet.alive = false; playerBullet2.alive = false; playerBullet3.alive = false;
	}
}

void spawnEnemy(movableObject& obj)	// function to spawn a basic enemy
{
	int spawn = rand() % SCREEN_X;
	if (obj.position.y > SCREEN_Y)
	obj.position.x = spawn;
	if (obj.position.y > SCREEN_Y)
	obj.position.y = 0;
	else
	obj.position.y += obj.speed.y;
}

void resetEnemy(movableObject& obj)
{
	int spawn = rand() % SCREEN_X;
	obj.position.x = spawn;
	obj.position.y = 0;
}

// check if one object has collided with another object
// returns true if the two objects have collided
bool checkCollision(movableObject& obj1) {	
	int x; int y;
	GetMouseLocation(x,y);
	if (GetMouseButtonDown(MOUSE_BUTTON_1) == true && obj1.position.x - obj1.width < x && obj1.position.x + obj1.width > x &&
			obj1.position.y > y - obj1.height &&
			obj1.position.y < y + obj1.height)
		return true;
	else
		return false;
}

// initialize all the variables in the game
void initGame() {
	srand(time(0));
	
	h.read();

	// Now load some sprites
	bgImage = CreateSprite( "./images/bg.png", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgImage, SCREEN_X>>1, SCREEN_Y>>1);
	bgFilterRed = CreateSprite( "./images/softred.png", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgFilterRed, SCREEN_X>>1, SCREEN_Y>>1);
	//MoveSprite(bgFilterRed, 0, 2340);
	bgFilterBlue = CreateSprite( "./images/softblue.png", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgFilterBlue, SCREEN_X>>1, SCREEN_Y>>1);
	//MoveSprite(bgFilterBlue, 0, 1560);
	player1.sprite = CreateSprite( "./images/player.png", PLAYER1_W, PLAYER1_H, true );
	playerBullet.sprite = CreateSprite( "./images/bullet.png", 10, 10, true );
	playerBullet2.sprite = CreateSprite( "./images/bullet.png", 10, 10, true );
	playerBullet3.sprite = CreateSprite( "./images/bullet.png", 10, 10, true );
	enemy.sprite = CreateSprite( "./images/enemy.png", 50, 50, true );
	enemy2.sprite = CreateSprite( "./images/enemy.png", 50, 50, true );
	
}

// destroy all the sprites and clean up any memory
void destroyGame() {
	DestroySprite(bgImage);
	DestroySprite(player1.sprite);
	DestroySprite(playerBullet.sprite);
	DestroySprite(playerBullet2.sprite);
	DestroySprite(playerBullet3.sprite);
	DestroySprite(enemy.sprite);
	DestroySprite(enemy2.sprite);
}

void checkEnemyCollision()
{
	if (playerBullet.dead == true && playerBullet2.dead == true && playerBullet3.dead == true)
		ifDead(playerBullet, playerBullet2, playerBullet3);

	if (checkCollision(enemy, playerBullet) == true || checkCollision(enemy, playerBullet2) == true || checkCollision(enemy, playerBullet3) == true)
	{
		scores++;
		resetEnemy(enemy);
	}

	if (checkCollision(enemy2, playerBullet) == true || checkCollision(enemy2, playerBullet2) == true || checkCollision(enemy2, playerBullet3) == true)
	{
		scores++;
		resetEnemy(enemy2);
	}
}

// update the game logic here
void updateGame() {
	//playerBullet.alive = false; playerBullet2.alive = false; playerBullet3.alive = false; 
	ClearScreen();
	movePlayer(player1);
	playerShoot(playerBullet, playerBullet2, playerBullet3);
	spawnEnemy(enemy);
	if (playerBullet.alive == true && playerBullet2.alive == true && playerBullet3.alive == true)
		ifAlive(playerBullet, playerBullet2, playerBullet3);


	if (playerBullet.dead == true && playerBullet2.dead == true && playerBullet3.dead == true)
		ifDead(playerBullet, playerBullet2, playerBullet3);

	checkEnemyCollision();

	spawnEnemy(enemy2);

	if (checkCollision(enemy, player1) == true) {
		gameProcess = &gameOverState;
		writeHS();
	}
	if (checkCollision(enemy2, player1) == true) {
		gameProcess = &gameOverState;
		writeHS();
	}

	char score[10];
	itoa(scores,score,10);
	DrawString("Score: ", 1000, 25, SColour(0,0xFF,0,0));
	DrawString(score, 1100, 25, SColour(0,0x7F,0,0x7F));

	RotateSprite(player1.sprite, 0);
	MoveSprite(player1.sprite, player1.position.x, player1.position.y);
	
	RotateSprite(playerBullet.sprite, 0);
	MoveSprite(playerBullet.sprite, playerBullet.position.x, playerBullet.position.y);
	RotateSprite(playerBullet2.sprite, 0);
	MoveSprite(playerBullet2.sprite, playerBullet2.position.x, playerBullet2.position.y);
	RotateSprite(playerBullet3.sprite, 0);
	MoveSprite(playerBullet3.sprite, playerBullet3.position.x, playerBullet3.position.y);

	RotateSprite(enemy.sprite, 0);
	MoveSprite(enemy.sprite, enemy.position.x, enemy.position.y);
	MoveSprite(enemy2.sprite, enemy2.position.x, enemy2.position.y);

	if (IsKeyDown(KEY_SPECIAL+38) == true)
		gameProcess = &menuState;

	//playerBullet.alive = false; playerBullet2.alive = false; playerBullet3.alive = false; 
}

// draws each frame of the game
void drawGame() {

	DrawSprite(bgImage);
	DrawSprite(bgFilterRed);
	DrawSprite(bgFilterBlue);
	DrawSprite(playerBullet.sprite);
	DrawSprite(playerBullet2.sprite);
	DrawSprite(playerBullet3.sprite);
	DrawSprite(player1.sprite);
	DrawSprite(enemy.sprite);
	DrawSprite(enemy2.sprite);
}

void initMenu()
{
	bgMenu = CreateSprite( "./images/menu3.jpg", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgMenu, SCREEN_X>>1, SCREEN_Y>>1);
}

void updateMenu()
{
	if (IsKeyDown(32) == true)
		gameProcess = &playState;
	//if (GetMouseButtonDown(MOUSE_BUTTON_1) == true && checkMouseClick(playGame) == true)
		//gameProcess = &playState;
}

void drawMenu()
{
	//DrawSprite(bgMenu);
	DrawString("Menu", SCREEN_X / 2, SCREEN_Y / 2, SColour(0,0xFF,0,0));
	DrawString("Press SPACE to play...", SCREEN_X / 2 - 100, SCREEN_Y / 2 + 50, SColour(0,255,255,255));
	//DrawString("Exit", SCREEN_X / 2, SCREEN_Y / 2 + 100, SColour(255,4,45,255));
	DrawString("Controls: LEFT MOUSE to shoot", 870, 750, SColour(0,255,0,255));
	DrawSprite(bgMenu);
}

void destroyMenu()
{
	DestroySprite(bgMenu);
}

void menuState()
{
	ClearScreen();
	updateMenu();
	drawMenu();
}

void playState()
{
	ClearScreen();
	updateGame();
	drawGame();
}

void initGameOver()
{
	bgGameOver = CreateSprite( "./images/gameover.jpg", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgGameOver, SCREEN_X>>1, SCREEN_Y>>1);
}

void updateGameOver()
{
	if (IsKeyDown(KEY_SPECIAL+38) == true)
		gameProcess = &menuState;
	//if (GetMouseButtonDown(MOUSE_BUTTON_1) == true && checkMouseClick(playGame) == true)
		//gameProcess = &playState;

}

void drawGameOver()
{
	//DrawSprite(bgMenu);
	DrawString("Game over", SCREEN_X / 2, SCREEN_Y / 2, SColour(0,0xFF,0,0));
	DrawSprite(bgGameOver);
}

void destroyGameOver()
{
	DestroySprite(bgGameOver);
}

void gameOverState()
{
	ClearScreen();
	updateGameOver();
	drawGameOver();
	resetEnemy(enemy);
	resetEnemy(enemy2);
	scores = 0;
}

void writeHS()
{
	h.write(scores);
}