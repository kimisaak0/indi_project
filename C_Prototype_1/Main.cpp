#include "structure.h"



int main()
{
	phase = phase0;
	srand((unsigned)time(NULL));

	while (true) {
		phase();
		if (phase == phase3) {
			return 0;
		}
	}

}//메인함수 끝