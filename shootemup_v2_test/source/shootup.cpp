//Last Edit 10/22/2013
//Will Gilstrap
/////////////////////
#include "shootup.h"

// global vars
unsigned int bgImage = -1;
unsigned int bgMenu = -1;
unsigned int bgGameOver = -1;
movableObject player1 = {687, 386, 0, 0, -1 , 100, 50};
bullets playerBullet = {-100, 0, 0, 4, -1 , 10, 10, false, true};
bullets playerBullet2 = {-100, 0, -4, 4, -1 , 10, 10, false, true};
bullets playerBullet3 = {-100, 0, -4, 4, -1 , 10, 10, false, true};
movableObject enemy = {-500, 800, 0, 1, -1 , 50, 50};
movableObject enemy2 = {-500, 800, 0, 1, -1 , 50, 50};
movableObject enemy3 = {0, 0, 0, 1, -1 , 50, 50};
movableObject boss = {SCREEN_X / 2, SCREEN_Y / 6, 0, 1, -1 , 100, 100};
enemybullets enemyBullet = {600, -10, 0, 4, -1 , 10, 10, false, true};
movableObject playGame = {SCREEN_X / 2, SCREEN_Y / 2 + 50, 0, 0, -1 , 100, 30};
movableObject exitMenu = {SCREEN_X / 2, SCREEN_Y / 2 + 100, 0, 0, -1 , 100, 30};
bool g_gameOver = false;
bool menuEnd = false;
unsigned int scores = 0;
vector<bullets> bulletLoaded;
//vector<bullets> bulletLoaded2;
//vector<bullets> bulletLoaded3;
enemybullets enemyHell[10];
enemybullets bossShot[10];
int player1Score = 0;
highScore h;
unsigned int checkKilled = 0;

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

bool checkCollision(movableObject& obj1, enemybullets& obj2) {
	int x; int y;
	GetMouseLocation(x,y);
	double rE = obj1.position.x;
	double radiusEnemy = 5;

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

void spawnEnemySide(movableObject& obj)	// function to spawn a basic enemy
{
	int spawn = rand() % SCREEN_X;
	

	int spawnSide = 0;


	if (obj.position.x >= 640)
	{
		obj.position.x -= 1;
		obj.position.y += obj.speed.y;
	}
	
	if (obj.position.x <= 640)
	{
		obj.position.x += 1;
		obj.position.y += obj.speed.y;
	}

	if (obj.position.y > SCREEN_Y / 2)
		obj.position.y += obj.speed.y;

	if (obj.position.y > SCREEN_Y)
		resetEnemySide(enemy3);

}

void resetEnemySide(movableObject& obj)
{
	int spawn = rand() % SCREEN_X;

	obj.position.x = spawn;
	obj.position.y = 0;
}

void enemyShoot(enemybullets& obj, int x, int y)
{
	
	float speed = 2;

	if (obj.position.y <= 0)
	{
		obj.position.x = enemy.position.x;
		obj.position.y = enemy.position.y;
	}

	if (obj.position.y >= 780)
	{
		obj.position.x = enemy.position.x;
		obj.position.y = enemy.position.y;
	}
	
	
	obj.position.y += speed;
}

void enemyShoot(int x, int y)
{
	float speed = 2;
	float sideShot = -5;
	for (int i = 0; i < 10; i++)
	{
	if (enemyHell[i].position.y <= 0)
	{
		enemyHell[i].position.x = enemy3.position.x;
		enemyHell[i].position.y = enemy3.position.y;
	}

	if (enemyHell[i].position.y >= 780)
	{
		enemyHell[i].position.x = enemy3.position.x;
		enemyHell[i].position.y = enemy3.position.y;
	}
	
	enemyHell[i].position.x += sideShot;
	enemyHell[i].position.y += speed;
	sideShot++;
	}
}

void bossShoot(int x, int y)
{
	static float angle = 0.0;
	float pi = 3.14;
	angle += 0.01;
	float inc = 0.0;
	float circle = 10;
	for(int i = 0; i<10; i++)			
	{
		bossShot[i].position.x = (boss.position.x) + cosf( angle+inc ) * circle;
		bossShot[i].position.y = (boss.position.y) + sinf( angle+inc ) * circle;
		MoveSprite(bossShot[i].sprite, bossShot[i].position.x, bossShot[i].position.y);			
		inc += 2*pi / 30;
		circle += 60;
	}
	/*
	static float angle = 0.0;
	float pi = 3.14;
	angle += 0.01;
	float inc = 0.0;
	float speed = 2;
	float sideShot = -5;
	//float sideShot = (boss.position.x) + cosf( angle+inc ) * 300;

	for (int i = 0; i < 10; i++)
	{
	if (bossShot[i].position.y <= 0)
	{
		bossShot[i].position.x = boss.position.x;
		bossShot[i].position.y = boss.position.y;
	}

	if (bossShot[i].position.y >= 780)
	{
		bossShot[i].position.x = boss.position.x;
		bossShot[i].position.y = boss.position.y;
	}
	
	bossShot[i].position.x += sideShot;
	bossShot[i].position.y += speed;
	inc += 2*(3.14) / 30;
	sideShot++;
}
*/
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
	player1.sprite = CreateSprite( "./images/player.png", PLAYER1_W, PLAYER1_H, true );
	playerBullet.sprite = CreateSprite( "./images/bullet.png", 10, 10, true );
	playerBullet2.sprite = CreateSprite( "./images/bullet.png", 10, 10, true );
	playerBullet3.sprite = CreateSprite( "./images/bullet.png", 10, 10, true );
	enemy.sprite = CreateSprite( "./images/enemy.png", 50, 50, true );
	enemy2.sprite = CreateSprite( "./images/enemy.png", 50, 50, true );
	enemy3.sprite = CreateSprite( "./images/enemy.png", 50, 50, true );
	enemyBullet.sprite = CreateSprite( "./images/enemybullet.png", 10, 10, true );

	for (int i = 0; i < 10; i++)
	{
		enemyHell[i].sprite = CreateSprite( "./images/enemybullet.png", 10, 10, true );
		enemyHell[i].position.x = 600;
		enemyHell[i].position.y = -10;
		enemyHell[i].speed.x = 0;
		enemyHell[i].speed.y = 4;
		enemyHell[i].width = 10;
		enemyHell[i].height = 10;
	}
	
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
	DestroySprite(enemy3.sprite);
	DestroySprite(enemyBullet.sprite);
	for (int i = 0; i < 10; i++)
	{
		DestroySprite(enemyHell[i].sprite);
	}
}

void checkEnemyCollision()
{
	if (playerBullet.dead == true && playerBullet2.dead == true && playerBullet3.dead == true)
		ifDead(playerBullet, playerBullet2, playerBullet3);

	if (checkCollision(enemy, playerBullet) == true || checkCollision(enemy, playerBullet2) == true || checkCollision(enemy, playerBullet3) == true)
	{
		scores++;
		checkKilled++;
		resetEnemy(enemy);
	}

	if (checkCollision(enemy2, playerBullet) == true || checkCollision(enemy2, playerBullet2) == true || checkCollision(enemy2, playerBullet3) == true)
	{
		scores++;
		checkKilled++;
		resetEnemy(enemy2);
	}

	if (checkCollision(enemy3, playerBullet) == true || checkCollision(enemy3, playerBullet2) == true || checkCollision(enemy3, playerBullet3) == true)
	{
		scores++;
		checkKilled++;
		resetEnemy(enemy3);
	}
}

// update the game logic here
void updateGame() {
	//playerBullet.alive = false; playerBullet2.alive = false; playerBullet3.alive = false; 
	ClearScreen();
	movePlayer(player1);
	playerShoot(playerBullet, playerBullet2, playerBullet3);
	spawnEnemy(enemy);
	enemyShoot(enemyBullet, getPlayerLocationX(), getPlayerLocationY());
	enemyShoot(getPlayerLocationX(), getPlayerLocationY());
	if (playerBullet.alive == true && playerBullet2.alive == true && playerBullet3.alive == true)
		ifAlive(playerBullet, playerBullet2, playerBullet3);


	if (playerBullet.dead == true && playerBullet2.dead == true && playerBullet3.dead == true)
		ifDead(playerBullet, playerBullet2, playerBullet3);

	checkEnemyCollision();

	spawnEnemy(enemy2);
	spawnEnemySide(enemy3);

	if (checkCollision(enemy, player1) == true) {
		gameProcess = &gameOverState;
		writeHS();
	}
	if (checkCollision(enemy2, player1) == true) {
		gameProcess = &gameOverState;
		writeHS();
	}

	if (checkCollision(enemy3, player1) == true) {
		gameProcess = &gameOverState;
		writeHS();
	}

	if (checkCollision(player1,enemyBullet) == true) {
		gameProcess = &gameOverState;
		writeHS();
	}
	for (int i = 0; i < 10; i++)
	{
	if (checkCollision(player1,enemyHell[i]) == true) {
		gameProcess = &gameOverState;
		writeHS();
	}
	}

	if (checkKilled >= 2)
		gameProcess = &bossState;

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
	MoveSprite(enemy3.sprite, enemy3.position.x, enemy3.position.y);
	MoveSprite(enemyBullet.sprite, enemyBullet.position.x, enemyBullet.position.y);
	for (int i = 0; i < 10; i++)
	{
	MoveSprite(enemyHell[i].sprite, enemyHell[i].position.x, enemyHell[i].position.y);
	}

	if (IsKeyDown(KEY_SPECIAL+38) == true)
		gameProcess = &menuState;

	//playerBullet.alive = false; playerBullet2.alive = false; playerBullet3.alive = false; 
}

// draws each frame of the game
void drawGame() {

	DrawSprite(bgImage);
	DrawSprite(playerBullet.sprite);
	DrawSprite(playerBullet2.sprite);
	DrawSprite(playerBullet3.sprite);
	DrawSprite(player1.sprite);
	DrawSprite(enemy.sprite);
	DrawSprite(enemy2.sprite);
	DrawSprite(enemy3.sprite);
	DrawSprite(enemyBullet.sprite);
	for (int i = 0; i < 10; i++)
	{
		DrawSprite(enemyHell[i].sprite);
	}
}
// Menu fuctions
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
// Play state function
void playState()
{
	ClearScreen();
	updateGame();
	drawGame();
}

// Boss state
void initBoss()
{
	boss.sprite = CreateSprite( "./images/enemy.png", 100, 100, true );
		for (int i = 0; i < 10; i++)
	{
		bossShot[i].sprite = CreateSprite( "./images/enemybullet.png", 10, 10, true );
		bossShot[i].position.x = 600;
		bossShot[i].position.y = -10;
		bossShot[i].speed.x = 0;
		bossShot[i].speed.y = 4;
		bossShot[i].width = 10;
		bossShot[i].height = 10;
	}
}

void updateBoss()
{
	movePlayer(player1);
	playerShoot(playerBullet, playerBullet2, playerBullet3);
	bossShoot(getPlayerLocationX(), getPlayerLocationY());
	if (playerBullet.alive == true && playerBullet2.alive == true && playerBullet3.alive == true)
		ifAlive(playerBullet, playerBullet2, playerBullet3);


	if (playerBullet.dead == true && playerBullet2.dead == true && playerBullet3.dead == true)
		ifDead(playerBullet, playerBullet2, playerBullet3);
	MoveSprite(boss.sprite, boss.position.x, boss.position.y);
	for (int i = 0; i < 10; i++)
	{
		MoveSprite(bossShot[i].sprite, bossShot[i].position.x, bossShot[i].position.y);
	}

	for (int i = 0; i < 10; i++)
	{
	if (checkCollision(player1,bossShot[i]) == true) {
		gameProcess = &gameOverState;
		writeHS();
	}
	}

	RotateSprite(player1.sprite, 0);
	MoveSprite(player1.sprite, player1.position.x, player1.position.y);
	
	RotateSprite(playerBullet.sprite, 0);
	MoveSprite(playerBullet.sprite, playerBullet.position.x, playerBullet.position.y);
	RotateSprite(playerBullet2.sprite, 0);
	MoveSprite(playerBullet2.sprite, playerBullet2.position.x, playerBullet2.position.y);
	RotateSprite(playerBullet3.sprite, 0);
	MoveSprite(playerBullet3.sprite, playerBullet3.position.x, playerBullet3.position.y);
}

void drawBoss()
{
	DrawSprite(player1.sprite);
	DrawSprite(playerBullet.sprite);
	DrawSprite(playerBullet2.sprite);
	DrawSprite(playerBullet3.sprite);
	DrawSprite(boss.sprite);
	for (int i = 0; i < 10; i++)
	{
		DrawSprite(bossShot[i].sprite);
	}
}

void destroyBoss()
{
	DestroySprite(boss.sprite);
}

void bossState()
{
	ClearScreen();
	updateBoss();
	drawBoss();
}

// Game Over functions
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
	resetEnemySide(enemy3);
	enemyBullet.position.y = -10;
	playerBullet.position.x = 0;
	playerBullet.position.y = 0;
	playerBullet2.position.x = 0;
	playerBullet2.position.y = 0;
	playerBullet3.position.x = 0;
	playerBullet3.position.y = 0;
	for (int i = 0; i < 10; i++)
	{
		enemyHell[i].position.x = 0;
		enemyHell[i].position.y = 0;
	}
	scores = 0;
	checkKilled = 0;
}
// Write high scores
void writeHS()
{
	h.write(scores);
}