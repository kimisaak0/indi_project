#pragma once
#include "Header.h"


class ScreenDrawer
{
	const static int row = 10;
	const static int col = 10;

	int screen[row][col];

public:
	void setMap(int map[10][10]);
	void drawMap();

	ScreenDrawer();
	virtual ~ScreenDrawer();
};

