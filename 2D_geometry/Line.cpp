#include "Line.h"

void Line::setLine(double Slope, double YIntercept)
{
	m_dSlope = Slope;
	m_dYIntercept = YIntercept;

	printf("y = %lfx + %lf", m_dSlope, m_dYIntercept);
}

void Line::setSlope(double Slope)
{
	m_dSlope = Slope;

	printf("y = %lfx + %lf", m_dSlope, m_dYIntercept);
}

void Line::setYIntercept(double YIntercept)
{
	m_dYIntercept = YIntercept;

	printf("y = %lfx + %lf", m_dSlope, m_dYIntercept);

}

Line Line::getLine() const
{
	printf("y = %lfx + %lf", m_dSlope, m_dYIntercept);

	return *this;
}

double Line::getX_inY(double y) const
{
	return (y - m_dYIntercept) / (m_dSlope);
}

double Line::getY_inX(double x) const
{
	return (x * m_dSlope) + m_dYIntercept;
}

bool Line::CollisionToPoint(Point B) const
{
	return (getY_inX(B.getX()) == B.getY()) ? true : false;
}


Point Line::CollisionToLine(Line B) const
{
	Point intersection;

	if (this->m_dSlope != B.m_dSlope) {
		intersection.setPoint(
			(B.m_dYIntercept - this->m_dYIntercept) / (this->m_dSlope - B.m_dSlope),
			(this->m_dSlope*B.m_dYIntercept - B.m_dSlope*this->m_dYIntercept) / (this->m_dSlope - B.m_dSlope)
		);

			cout << "교점 : "; intersection.showPoint(); cout << endl;
	}

	else {
		if (this->m_dYIntercept == B.m_dYIntercept) { //두 직선이 일치
			intersection.setPoint(0, m_dYIntercept);

			cout << "두 직선이 일치함" << endl;
			
		}
		else { //교점이 없음.
			intersection.setPoint(0, 0);
			
			cout << "두 직선이 평행함" << endl;
		}
	}

	return intersection;
}

Line::Line(double Slope, double YIntercept)
{
	cout << "Line 생성자 호출" << endl;
	m_dSlope = Slope;
	m_dYIntercept = YIntercept;
}

Line::~Line()
{
	cout << "Line 소멸자 호출" << endl;
}
