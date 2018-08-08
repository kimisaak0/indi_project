#include "Ray.h"

void	Ray::setStartPoint(Point S)
{
	m_pStartPoint = S;
}

void	Ray::setDirection(int D)
{
	m_iDirection = D;
}
		
Point	Ray::getStartPoint() const
{
	return m_pStartPoint;
}
int		Ray::getDirection() const
{
	return m_iDirection;
}
		
bool	Ray::CollisionToPoint(Point A)
{
	if (Line::CollisionToPoint(A) == true) {
		if (m_iDirection > 90 && m_iDirection < 270) {
			return m_pStartPoint.getX() > A.getX() ? true : false;
		}
		else if (m_iDirection == 90) {
			return A.getY() > m_pStartPoint.getY() ? true : false;
		}
		else if (m_iDirection == 270) {
			return A.getY() < m_pStartPoint.getY() ? true : false;
		}
		else {
			return m_pStartPoint.getX() > A.getX() ? true : false;

		}
	}
	else {
		return false;
	}
}

Ray::Ray() 
{

}

Ray::Ray(Point start, int Direction) : m_pStartPoint(start.getX(), start.getY())
{
	m_iDirection = Direction % 360;

	m_dSlope = tan(DtR(Direction));

	m_dYIntercept = getY_inX(start.getX());
}


Ray::~Ray()
{
}
