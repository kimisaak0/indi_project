#pragma once
#include "Header.h"

class move
{
	int x;
	int y;
	char shape;

public:
	void keyInput();
	void showShape();

	move();
	move(char c);
	virtual ~move();
};

