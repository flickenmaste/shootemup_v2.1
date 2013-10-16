#include "vector2.h"

	vector2::vector2 scalarAdd(vector2 &w, float s) //scalar
	{
		vector2 temp;
		temp.x = w.x + s; 
		temp.y = w.y + s;
		return temp;
	}

	vector2::vector2 scalarSub(vector2 &w, float s) //scalar
	{
		vector2 temp;
		temp.x = w.x - s; 
		temp.y = w.y - s;
		return temp;
	}

	vector2::vector2 scalarMulti(vector2 &w, float s) //scalar
	{
		vector2 temp;
		temp.x = w.x * s; 
		temp.y = w.y * s;
		return temp;
	}