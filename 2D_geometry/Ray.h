#pragma once
#include "Line.h"


class Ray :public Line
{
protected:
	Point	m_pStartPoint;
	int		m_iDirection;	//Degree °ª »ç¿ë.

public:
	void	setStartPoint(Point S);
	void	setDirection(int D);

	Point	getStartPoint() const;
	int		getDirection() const;

	bool	CollisionToPoint(Point A);

	Ray();
	Ray(Point start, int Direction);
	~Ray();
};

