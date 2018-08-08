#include "ScreenDrawer.h"

void gotoxy(int x, int y)
{
	COORD Pos = { (short)x - 1, (short)y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


ScreenDrawer::ScreenDrawer()
{
	//system("mode con cols = 40 lines = 50");
}


ScreenDrawer::~ScreenDrawer()
{
}

void ScreenDrawer::setMap(int map[10][10])
{
	for (int iCnt = 0; iCnt < row; iCnt++) {
		for (int kCnt = 0; kCnt < col; kCnt++) {
			screen[iCnt][kCnt] = map[iCnt][kCnt];
		}
	}
}

void ScreenDrawer::drawMap()
{
	for (int iCnt = 0; iCnt < row; iCnt++) {
		for (int kCnt = 0; kCnt < col; kCnt++) {
			gotoxy(iCnt * 2+10, kCnt+10); 
			switch (screen[kCnt][iCnt]) {
				case 0: 	std::cout << '.' << std::endl; break;
				case 1:		std::cout << '#' << std::endl; break;
			}
		}
	}
}
