//Last Edit 10/23/2013
//Will Gilstrap
/////////////////////
#include "collision.h"

// check collision of bullet and enemy
bool collision::checkCollision(movableObject& obj1, bullets& obj2) {
	int x; int y;
	GetMouseLocation(x,y);
	double rE = obj1.position.x;
	double radiusEnemy = obj1.width / 2;

	double rB = obj2.position.x;
	double radiusBullet = obj2.width / 2;

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
bool collision::checkCollision(movableObject& obj1, movableObject& obj2) {
	int x; int y;
	GetMouseLocation(x,y);
	double rE = obj1.position.x;
	double radiusEnemy = obj1.width / 2;

	double rB = obj2.position.x;
	double radiusBullet = obj2.width / 2;

	double distX = obj1.position.x - obj2.position.x;
	double distY = obj1.position.y - obj2.position.y;

	double dist = sqrt((distX * distX) + (distY * distY));
	double radii = (radiusEnemy + radiusBullet) * (radiusEnemy + radiusBullet);

	if (dist < radiusEnemy + radiusBullet)
		return true;
	else
		return false;
}

bool collision::checkCollision(movableObject& obj1, enemybullets& obj2) {
	int x; int y;
	GetMouseLocation(x,y);
	double rE = obj1.position.x;
	double radiusEnemy = 5;

	double rB = obj2.position.x;
	double radiusBullet = obj2.width / 2;

	double distX = obj1.position.x - obj2.position.x;
	double distY = obj1.position.y - obj2.position.y;

	double dist = sqrt((distX * distX) + (distY * distY));
	double radii = (radiusEnemy + radiusBullet) * (radiusEnemy + radiusBullet);

	if (dist < radiusEnemy + radiusBullet)
		return true;
	else
		return false;
}