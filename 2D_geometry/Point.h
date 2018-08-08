#pragma once
#include "Header.h"

class Point
{
private:
	double x;
	double y;

public:
	void	setPoint(int nx, int ny);
	Point	getPoint() const;

	double	getX() const;
	double	getY() const;

	void	showPoint() const;
	void	MovePoint(int nx, int ny);
	double	disitance(Point oP) const;

	Point(int nx = 0, int ny = 0);
	~Point();

};