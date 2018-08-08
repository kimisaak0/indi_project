#include "Segment.h"

void	Segment::setEndPoint(Point a)
{
	m_pEndPoint = a;
}
double	Segment::getLength()
{
	return m_dLength;
}
Point	Segment::getEndPoint()
{
	m_pEndPoint.showPoint();
	return m_pEndPoint;
}

Segment::Segment(Point Start, Point End) 
{
	m_pStartPoint = Start;
	m_pEndPoint = End;

	m_dSlope = (End.getY() - Start.getY()) / (End.getX() - Start.getX());
	m_dYIntercept = getY_inX(0);

	m_iDirection = static_cast<int> (atan2((End.getY() - Start.getY()), (End.getX() - Start.getX())));
	m_dLength = m_pStartPoint.disitance(m_pEndPoint);
}


Segment::~Segment()
{
}
