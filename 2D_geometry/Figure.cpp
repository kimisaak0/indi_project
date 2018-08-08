#include "Figure.h"

void Figure::moveFigure(double x, double y)
{
	m_pCenterPoint.MovePoint(x, y);
}

Figure::Figure(double x, double y) :m_pCenterPoint(x,y)
{
}

Figure::~Figure()
{
}
