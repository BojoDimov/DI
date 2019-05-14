#pragma once

#define FIGURES_PER_PLAYER 16

class Figure
{
protected:
	int x;
	int y;
	bool isActive;
public:
	/// The four BASE operations with objects
	Figure();														//default constructor
	Figure(const Figure &);							//copy-constructor
	Figure(const Figure &&);						//move-constructor, its advanced mechanism in c++s
	Figure& operator=(const Figure &);	//assignment operator
	~Figure();													//destructor

	void deactivate();

	bool isAtPosition(int x, int y) const;
	virtual bool moveTo(int x, int y, Figure * enemyFigures[FIGURES_PER_PLAYER]) = 0;

	
};

