#pragma once

#define FIGURES_PER_PLAYER 16

class Figure
{
protected:
	int x;
	int y;
	bool isActive;
public:
	Figure();

	void deactivate();

	bool isAtPosition(int x, int y) const;
	virtual bool moveTo(int x, int y, Figure * enemyFigures[FIGURES_PER_PLAYER]) = 0;

	~Figure();
};

