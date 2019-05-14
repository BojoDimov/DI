#pragma once
#include "Figure.h"

class Board
{
private:
	int turn;
	Figure * player1[FIGURES_PER_PLAYER];
	Figure * player2[FIGURES_PER_PLAYER];
public:
	Board();

	void makeTurn(int fromX, int fromY, int toX, int toY);

	~Board();
};

