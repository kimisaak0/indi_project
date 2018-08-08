#pragma once
#include "Ray.h"

class Segment : public Ray
{
protected:
	Point m_pEndPoint;
	double m_dLength;

public:
	void	setEndPoint(Point a);
	
	double	getLength();
	Point	getEndPoint();

public:
	Segment(Point Start, Point End);
	~Segment();
};

