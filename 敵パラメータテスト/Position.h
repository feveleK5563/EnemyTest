#pragma once
#include "MyPG.h"

class Position	//x‚Æy‚ÌŠÇ—
{
public:
	float x, y;

	Position() : x(0.f), y(0.f) {};
	Position(float cx, float cy) : x(cx), y(cy) {};
	Position(int cx, int cy) : x(float(cx)), y(float(cy)) {};

	Position operator =(const Position& pos)
	{
		this->x = pos.x;
		this->y = pos.y;
		return *this;
	}

	Position operator +(const Position& pos)
	{
		return { this->x + pos.x, this->y + pos.y };
	}

	Position operator -(const Position& pos)
	{
		return { this->x - pos.x, this->y - pos.y };
	}

	Position operator +=(const Position& pos)
	{
		this->x += pos.x;
		this->y += pos.y;
		return *this;
	}

	Position operator -=(const Position& pos)
	{
		this->x -= pos.x;
		this->y -= pos.y;
		return *this;
	}
};
