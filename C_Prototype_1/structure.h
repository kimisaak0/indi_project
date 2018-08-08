#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

struct character {
	int iHP;
	int iAttack;
	int iBlock;
	int iHeal;
};

character PC = { 30, 10, 5, 10 };
character Enemy = { 0,0,0,0 };

void phase0();
void phase1();
void phase2();
void phase3();


void(*phase) ();



void CreativeEnemy(int difficulty, character PC, character* Enemy)
{
	int BasePercent;

	switch (difficulty) {
	case 1: //쉬움
		BasePercent = 70;
		break;

	case 2:	//보통
		BasePercent = 80;
		break;

	case 3:	//어려움
		BasePercent = 90;
		break;
	}
	
	Enemy->iHP = (int)(PC.iHP * ((BasePercent + (rand() % 41)) / 100.0));
	Enemy->iAttack = (int)(PC.iAttack * ((BasePercent + (rand() % 41)) / 100.0));
	Enemy->iBlock = (int)(PC.iBlock * ((BasePercent + (rand() % 41)) / 100.0));
	Enemy->iHeal = (int)(PC.iHeal * ((BasePercent + (rand() % 41)) / 100.0));
}

void action(character* PC, character* Enemy, int iActionCode)
{
	switch (iActionCode) {
	case 1: // attack/attack
	{
		{

			printf("내 행동: 공격, 적 행동 : 공격 \n");
			int damage_PtoE = PC->iAttack - Enemy->iBlock;
			if (damage_PtoE < 0) {	// 방어가 공격보다 높으면 0으로 처리.
				damage_PtoE = 0;
			}
			Enemy->iHP = Enemy->iHP - damage_PtoE;
		}

		{
			int damage_EtoP = Enemy->iAttack - PC->iBlock;
			if (damage_EtoP < 0) {  // 방어가 공격보다 높으면 0으로 처리.
				damage_EtoP = 0;
			}
			PC->iHP = PC->iHP - damage_EtoP;
		}
		break;
	}

	case 2:	// attack/block
	{
		printf("내 행동: 공격, 적 행동 : 방어 \n");
		{
			int damage_PtoE = PC->iAttack - Enemy->iBlock * 2;
			if (damage_PtoE < 0) {  // 방어가 공격보다 높으면 0으로 처리.
				damage_PtoE = 0;
			}
			Enemy->iHP = Enemy->iHP - damage_PtoE;
		}
		break;
	}

	case 3:	// attack/heal
	{

		printf("내 행동: 공격, 적 행동 : 회복 \n");
		{
			int damage_PtoE = PC->iAttack;
			Enemy->iHP = Enemy->iHP - damage_PtoE;

			Enemy->iHP = Enemy->iHP + Enemy->iHeal;
		}
		break;
	}

	case 4: // block/attack
	{

		printf("내 행동: 방어, 적 행동 : 공격 \n");
		{
			int damage_EtoP = Enemy->iAttack - PC->iBlock*2;
			if (damage_EtoP < 0) {  // 방어가 공격보다 높으면 0으로 처리.
				damage_EtoP = 0;
			}
			PC->iHP = PC->iHP - damage_EtoP;
		}
		break;
	}

	case 5: // block/block
	{
		printf("내 행동: 방어, 적 행동 : 방어 \n");
		break;
	}

	case 6: //block/heal
	{
		printf("내 행동: 방어, 적 행동 : 회복 \n");
		Enemy->iHP = Enemy->iHP + Enemy->iHeal;
		break;
	}

	case 7: //heal/attack
	{
		printf("내 행동: 회복, 적 행동 : 공격 \n");
		int damage_EtoP = Enemy->iAttack;
		PC->iHP = PC->iHP - damage_EtoP;

		PC->iHP = PC->iHP + PC->iHeal;
		break;
	}

	case 8: //heal/block
	{
		printf("내 행동: 회복, 적 행동 : 방어 \n");
		PC->iHP = PC->iHP + PC->iHeal;
		break;
	}

	case 9: //heal/heal
	{
		printf("내 행동: 회복, 적 행동 : 회복 \n");
		PC->iHP = PC->iHP + PC->iHeal;

		Enemy->iHP = Enemy->iHP + Enemy->iHeal;
		break;
	}

	}//케이스문 끝
}

void reward(character* PC, character* Enemy)
{

	system("cls");


	int iRewardSelect;

	for (int iCnt = 3; iCnt > 0; iCnt--) {
		printf("올리고 싶은 능력치를 선택하세요.\n");
		
		printf("1. 공격력 (현재 : %d) \n",PC->iAttack);
		printf("2. 방어력 (현재 : %d) \n",PC->iBlock);
		printf("3. 회복력 (현재 : %d) \n",PC->iHeal);

		printf("보상 선택 기회가 %d번 남았습니다. \n", iCnt);

		scanf_s("%d", &iRewardSelect);

		switch (iRewardSelect)
		{
		case 1: //공격력
			PC->iAttack += rand() % 3 + 1;
			break;

		case 2: //방어력
			PC->iBlock += rand() % 3 + 1;
			break;

		case 3:	//회복력
			PC->iHeal += rand() % 3 + 1;
			break;
		}
	}
}

void savedata()
{
	FILE* fp;

	fopen_s(&fp, "savedata.bin", "wb");

	fwrite(&PC, sizeof(character), 1, fp);

//	fprintf(fp, "%4d %4d %4d %4d", PC.iHP, PC.iAttack, PC.iBlock, PC.iHeal);

	fclose(fp);
}

void loaddata()
{
	FILE* fp;

	fopen_s(&fp, "savedata.bin", "rb");

	fread(&PC, sizeof(character), 1, fp);

//	fscanf_s(fp, "%4d %4d %4d %4d", &PC.iHP, &PC.iAttack, &PC.iBlock, &PC.iHeal);

	fclose(fp);
}

void phase0()
{
	while (true) {//phase0:
		Sleep(500);

		system("cls");

		int input_0;

		printf("메뉴를 선택하세요 : \n");
		printf("1. 게임 시작 \n");
		printf("2. 불러오기 \n");
		printf("3. 종료 \n");

		scanf_s("%d", &input_0);

		if (input_0 < 1 || input_0 > 3) {
			printf("잘못 입력하셨습니다. \n");
			_getch();
			continue;
		}

		switch (input_0) {
		case 1: //게임시작
			phase = phase1;
			return;
			//goto phase1;
			break;

		case 2: //불러오기
			loaddata();
			printf("불러왔습니다.\n");
			break;

		case 3: //종료
			printf("게임을 종료합니다. \n");
			phase = phase3;
			return;
			break;
		}

	}//while문 0번 끝
}

void phase1()
{
	while (true) {	//phase1:
		Sleep(500);

		system("cls");

		printf("PC's HP : %d \n", PC.iHP);
		printf("PC's AttackPoint : %d \n", PC.iAttack);
		printf("PC's BlockPoint : %d \n", PC.iBlock);
		printf("PC's HealPoint : %d \n", PC.iHeal);


		int input_1;
		printf("\n난이도를 선택하세요 : \n");
		printf("1. 쉬움 2. 보통 3. 어려움\n");
		printf("4. 저장하기 5. 불러오기 6. 뒤로가기\n");
		scanf_s("%d", &input_1);

		if (input_1 < 1 || input_1 > 6) {
			printf("잘못 입력하셨습니다. \n");
			_getch();
			continue;
		}
		switch (input_1) {
		case 4:
			savedata();
			printf("저장했습니다. \n");
			continue;
		case 5:
			loaddata();
			printf("불러왔습니다. \n");
			continue;
		case 6:
			phase = phase0;
			return;
			//goto phase0;
			break;
		}

		CreativeEnemy(input_1, PC, &Enemy);
		printf("적을 생성했습니다. \n");

		printf("Enemy's HP : %d \n", Enemy.iHP);
		printf("Enemy's AttackPoint : %d \n", Enemy.iAttack);
		printf("Enemy's BlockPoint : %d \n", Enemy.iBlock);
		printf("Enemy's HealPoint : %d \n", Enemy.iHeal);
		_getch();

		phase = phase2;
		return;
		// goto phase2;

	} // while문 1번 끝
}

void phase2() 
{
	while (true) {
	//phase2:	//전투 화면
		system("cls");

		printf("PC's HP : %d \n", PC.iHP);
		printf("PC's AttackPoint : %d \n", PC.iAttack);
		printf("PC's BlockPoint : %d \n", PC.iBlock);
		printf("PC's HealPoint : %d \n", PC.iHeal);

		printf("\n");

		printf("Enemy's HP : %d \n", Enemy.iHP);
		printf("Enemy's AttackPoint : %d \n", Enemy.iAttack);
		printf("Enemy's BlockPoint : %d \n", Enemy.iBlock);
		printf("Enemy's HealPoint : %d \n", Enemy.iHeal);

		int input_2;
		printf("\n행동을 선택하세요 : \n");
		printf("1. 공격, 2. 방어, 3. 회복  4.도망가기\n");
		scanf_s("%d", &input_2);

		if (input_2 < 1 || input_2 > 4) {
			printf("잘못 입력하셨습니다. \n");
			_getch();
			continue;
		}

		switch (input_2) {
		case 1:
			action(&PC, &Enemy, 1 + rand() % 3);
			break;

		case 2:
			action(&PC, &Enemy, 4 + rand() % 3);
			break;

		case 3:
			action(&PC, &Enemy, 7 + rand() % 3);
			break;

		case 4:
			phase = phase1;
			return;
			//goto phase1;
			break;
		}

		if (PC.iHP <= 0) {
			printf("졌습니다.\n");
			phase = phase0;
			//goto phase0;	//첫 화면으로 보냄
		}

		if (Enemy.iHP <= 0) {
			printf("이겼습니다. \n");
			Sleep(500);
			reward(&PC, &Enemy);
			phase = phase1;
			return;
			//goto phase1;	//전투 선택 화면으로 보냄
		}

		Sleep(500);
	}//while문 2번 끝
}

void phase3()
{
	Sleep(500);

	system("cls");

	return;
}