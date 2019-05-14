#pragma once
#include "Figure.h"
class Knight :
	public Figure
{
public:
	Knight();

	bool moveTo(int x, int y, Figure * enemyFigures[FIGURES_PER_PLAYER]);

	~Knight();
};

