#pragma once
#include "Point.h"

class Line
{
protected:
	double m_dSlope;
	double m_dYIntercept;

public:
	void setLine(double Slope, double YIntercept);
	void setSlope(double Slope);
	void setYIntercept(double YIntercept);

	Line getLine() const;
	double getX_inY(double y) const;
	double getY_inX(double x) const;

	Point	CollisionToLine(Line B) const;
	bool	CollisionToPoint(Point B) const;


	Line(double Slope = 0, double YIntercept = 0);
	~Line();
};

