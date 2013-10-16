//class vector 2d
//Last Edit 10/15/2013
//Will Gilstrap
/////////////////////
#ifndef _VECTOR2_H_
#define _VECTOR2_H_

class vector2
{
public:
	float x;
	float y;
	/*
	vector2() {x = 0; y = 0;}
	~vector2(){}

	float GetX() {return x;}
	float GetY() {return y;}

	void SetX(int nextX) {x = nextX;}
	void SetY(int nextY) {y = nextY;}

	vector2 operator+ (const vector2 &w)
	{
		vector2 temp;
		temp.x = this->x + w.x;
		temp.y = this->x + w.y;
		return temp;
	}

	vector2 operator+ (float s) //scalar add
	{
		vector2 temp;
		temp.x = this->x + s; 
		temp.y = this->y + s;
		return temp;
	}

	vector2 operator- (const vector2 &w)
	{
		vector2 temp;
		temp.x = this->x - w.x;
		temp.y = this->x - w.y;
		return temp;
	}

	vector2 operator- (float s) //scalar sub
	{
		vector2 temp;
		temp.x = this->x - s; 
		temp.y = this->y - s;
		return temp;
	}

	vector2 operator* (float s) //scalar multi
	{
		vector2 temp;
		temp.x = this->x * s; 
		temp.y = this->y * s;
		return temp;
	}

	float dotProduct(vector2 &a, vector2 &b) 
	{ 
		return (a.x * b.x + a.y * b.y); 
	} 
	*/
};

#endif