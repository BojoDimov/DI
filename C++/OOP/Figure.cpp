#include "Figure.h"



Figure::Figure()
{
}

Figure::Figure(const Figure & copy)
{
	//detect self-assignment
	if (this == &copy)
		return;

	this->x = copy.x;
	this->y = copy.y;
	this->isActive = copy.isActive;
}

Figure::Figure(const Figure && other)
{
}

Figure & Figure::operator=(const Figure & copy)
{
	//detect self-assignment
	if (this == &copy)
		return *this;

	this->x = copy.x;
	this->y = copy.y;
	this->isActive = copy.isActive;
	return *this;
}

void Figure::deactivate()
{
	this->isActive = false;
}

bool Figure::isAtPosition(int x, int y) const
{
	return this->isActive && this->x == x && this->y == y;
}


Figure::~Figure()
{
}
