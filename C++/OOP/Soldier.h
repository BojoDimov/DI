#pragma once
#include "Figure.h"
class Soldier :
	public Figure
{
private:
	int direction;
public:
	Soldier();

	bool moveTo(int x, int y, Figure * enemyFigures[FIGURES_PER_PLAYER]);

	~Soldier();
};

