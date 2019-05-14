#include "Figure.h"



Figure::Figure()
{
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
