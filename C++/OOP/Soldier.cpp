#include "Soldier.h"



Soldier::Soldier()
	:Figure()
{
}

bool Soldier::moveTo(int x, int y, Figure * enemyFigures[FIGURES_PER_PLAYER])
{
	// Make checks for out of bound and direction based movements
	if (this->x == x && this->y == y)
		return false;

	Figure *enemy = nullptr;
	for (int i = 0; i < FIGURES_PER_PLAYER; ++i)
		if (enemyFigures[i]->isAtPosition(x, y))
			enemy = enemyFigures[i];

	if (enemy != nullptr && x != this->x)
		enemy->deactivate();
	if (enemy == nullptr && x != this->x)
		return false;

	this->x = x;
	this->y = y;
	return true;
}


Soldier::~Soldier()
{
}