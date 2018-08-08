#include "Header.h"
#include "Segment.h"
#include "Figure.h"

int main()
{
	Point A(10, 5);

	Line L1(3, 2);
	
	Line L2(4, 5);

	L1.CollisionToLine(L2);

	L1.CollisionToPoint(A);
}