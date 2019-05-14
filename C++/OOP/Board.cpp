#include "Board.h"
#include "Knight.h"


Board::Board()
{
	/// init all figures for both players
	player1[0] = new Knight();
	player1[1] = new Knight();

	player2[0] = new Knight();
	player2[1] = new Knight();
}

void Board::makeTurn(int fromX, int fromY, int toX, int toY)
{
	Figure *figure = nullptr;
	for (int i = 0; i < FIGURES_PER_PLAYER; i++) {
		if (this->turn % 2 == 0 && player1[i]->isAtPosition(fromX, fromY))
			figure = player1[i];
		if (this->turn % 2 == 1 && player2[i]->isAtPosition(fromX, fromY))
			figure = player2[i];
	}

	if (figure == nullptr || !figure->moveTo(toX, toY, turn % 2 == 0 ? player2 : player1))
		throw "Invalid move";

	turn++;
}


Board::~Board()
{
	for (int i = 0; i < FIGURES_PER_PLAYER; i++) {
		delete player1[i];
		delete player2[i];
	}
}
