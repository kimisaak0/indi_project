#include "Point.h"

void	Point::setPoint(int nx, int ny)
{
	x = nx;
	y = ny;

	printf("(%.2lf,%.2lf) \n", x, y);
}

Point	Point::getPoint() const
{
	printf("(%.2lf,%.2lf) \n", x, y);

	return *this;
}


void	Point::MovePoint(int nx, int ny)
{
	x += nx;
	y += ny;

	printf("(%.2lf,%.2lf) \n", x, y);
}
double		Point::disitance(Point oP) const
{
	cout << "거리 : " << pow(pow(oP.x - x, 2) + pow(oP.y - y, 2), 1 / 2) << endl;

	return pow(pow(oP.x - x, 2) + pow(oP.y - y, 2), 1 / 2);
}


double	Point::getX() const
{
	return x;
}

double	Point::getY() const
{
	return y;
}

void	Point::showPoint() const
{
	printf("(%.2lf,%.2lf)", x, y);

}


Point::Point(int nx, int ny)
{
	x = nx;
	y = ny;

	cout << "Point 생성자 호출 ";
	printf("(%.2lf,%.2lf) \n", x, y);
}


Point::~Point()
{
	cout << "Point 소멸자 호출 ";
}