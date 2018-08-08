#pragma once
#include "Segment.h"


class Figure
{
protected:
	Point m_pCenterPoint;

public:
	void moveFigure(double x, double y);

public:
	Figure(double x = 0, double y = 0);
	~Figure();
};

