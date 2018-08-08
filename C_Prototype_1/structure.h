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
	case 1: //����
		BasePercent = 70;
		break;

	case 2:	//����
		BasePercent = 80;
		break;

	case 3:	//�����
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

			printf("�� �ൿ: ����, �� �ൿ : ���� \n");
			int damage_PtoE = PC->iAttack - Enemy->iBlock;
			if (damage_PtoE < 0) {	// �� ���ݺ��� ������ 0���� ó��.
				damage_PtoE = 0;
			}
			Enemy->iHP = Enemy->iHP - damage_PtoE;
		}

		{
			int damage_EtoP = Enemy->iAttack - PC->iBlock;
			if (damage_EtoP < 0) {  // �� ���ݺ��� ������ 0���� ó��.
				damage_EtoP = 0;
			}
			PC->iHP = PC->iHP - damage_EtoP;
		}
		break;
	}

	case 2:	// attack/block
	{
		printf("�� �ൿ: ����, �� �ൿ : ��� \n");
		{
			int damage_PtoE = PC->iAttack - Enemy->iBlock * 2;
			if (damage_PtoE < 0) {  // �� ���ݺ��� ������ 0���� ó��.
				damage_PtoE = 0;
			}
			Enemy->iHP = Enemy->iHP - damage_PtoE;
		}
		break;
	}

	case 3:	// attack/heal
	{

		printf("�� �ൿ: ����, �� �ൿ : ȸ�� \n");
		{
			int damage_PtoE = PC->iAttack;
			Enemy->iHP = Enemy->iHP - damage_PtoE;

			Enemy->iHP = Enemy->iHP + Enemy->iHeal;
		}
		break;
	}

	case 4: // block/attack
	{

		printf("�� �ൿ: ���, �� �ൿ : ���� \n");
		{
			int damage_EtoP = Enemy->iAttack - PC->iBlock*2;
			if (damage_EtoP < 0) {  // �� ���ݺ��� ������ 0���� ó��.
				damage_EtoP = 0;
			}
			PC->iHP = PC->iHP - damage_EtoP;
		}
		break;
	}

	case 5: // block/block
	{
		printf("�� �ൿ: ���, �� �ൿ : ��� \n");
		break;
	}

	case 6: //block/heal
	{
		printf("�� �ൿ: ���, �� �ൿ : ȸ�� \n");
		Enemy->iHP = Enemy->iHP + Enemy->iHeal;
		break;
	}

	case 7: //heal/attack
	{
		printf("�� �ൿ: ȸ��, �� �ൿ : ���� \n");
		int damage_EtoP = Enemy->iAttack;
		PC->iHP = PC->iHP - damage_EtoP;

		PC->iHP = PC->iHP + PC->iHeal;
		break;
	}

	case 8: //heal/block
	{
		printf("�� �ൿ: ȸ��, �� �ൿ : ��� \n");
		PC->iHP = PC->iHP + PC->iHeal;
		break;
	}

	case 9: //heal/heal
	{
		printf("�� �ൿ: ȸ��, �� �ൿ : ȸ�� \n");
		PC->iHP = PC->iHP + PC->iHeal;

		Enemy->iHP = Enemy->iHP + Enemy->iHeal;
		break;
	}

	}//���̽��� ��
}

void reward(character* PC, character* Enemy)
{

	system("cls");


	int iRewardSelect;

	for (int iCnt = 3; iCnt > 0; iCnt--) {
		printf("�ø��� ���� �ɷ�ġ�� �����ϼ���.\n");
		
		printf("1. ���ݷ� (���� : %d) \n",PC->iAttack);
		printf("2. ���� (���� : %d) \n",PC->iBlock);
		printf("3. ȸ���� (���� : %d) \n",PC->iHeal);

		printf("���� ���� ��ȸ�� %d�� ���ҽ��ϴ�. \n", iCnt);

		scanf_s("%d", &iRewardSelect);

		switch (iRewardSelect)
		{
		case 1: //���ݷ�
			PC->iAttack += rand() % 3 + 1;
			break;

		case 2: //����
			PC->iBlock += rand() % 3 + 1;
			break;

		case 3:	//ȸ����
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

		printf("�޴��� �����ϼ��� : \n");
		printf("1. ���� ���� \n");
		printf("2. �ҷ����� \n");
		printf("3. ���� \n");

		scanf_s("%d", &input_0);

		if (input_0 < 1 || input_0 > 3) {
			printf("�߸� �Է��ϼ̽��ϴ�. \n");
			_getch();
			continue;
		}

		switch (input_0) {
		case 1: //���ӽ���
			phase = phase1;
			return;
			//goto phase1;
			break;

		case 2: //�ҷ�����
			loaddata();
			printf("�ҷ��Խ��ϴ�.\n");
			break;

		case 3: //����
			printf("������ �����մϴ�. \n");
			phase = phase3;
			return;
			break;
		}

	}//while�� 0�� ��
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
		printf("\n���̵��� �����ϼ��� : \n");
		printf("1. ���� 2. ���� 3. �����\n");
		printf("4. �����ϱ� 5. �ҷ����� 6. �ڷΰ���\n");
		scanf_s("%d", &input_1);

		if (input_1 < 1 || input_1 > 6) {
			printf("�߸� �Է��ϼ̽��ϴ�. \n");
			_getch();
			continue;
		}
		switch (input_1) {
		case 4:
			savedata();
			printf("�����߽��ϴ�. \n");
			continue;
		case 5:
			loaddata();
			printf("�ҷ��Խ��ϴ�. \n");
			continue;
		case 6:
			phase = phase0;
			return;
			//goto phase0;
			break;
		}

		CreativeEnemy(input_1, PC, &Enemy);
		printf("���� �����߽��ϴ�. \n");

		printf("Enemy's HP : %d \n", Enemy.iHP);
		printf("Enemy's AttackPoint : %d \n", Enemy.iAttack);
		printf("Enemy's BlockPoint : %d \n", Enemy.iBlock);
		printf("Enemy's HealPoint : %d \n", Enemy.iHeal);
		_getch();

		phase = phase2;
		return;
		// goto phase2;

	} // while�� 1�� ��
}

void phase2() 
{
	while (true) {
	//phase2:	//���� ȭ��
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
		printf("\n�ൿ�� �����ϼ��� : \n");
		printf("1. ����, 2. ���, 3. ȸ��  4.��������\n");
		scanf_s("%d", &input_2);

		if (input_2 < 1 || input_2 > 4) {
			printf("�߸� �Է��ϼ̽��ϴ�. \n");
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
			printf("�����ϴ�.\n");
			phase = phase0;
			//goto phase0;	//ù ȭ������ ����
		}

		if (Enemy.iHP <= 0) {
			printf("�̰���ϴ�. \n");
			Sleep(500);
			reward(&PC, &Enemy);
			phase = phase1;
			return;
			//goto phase1;	//���� ���� ȭ������ ����
		}

		Sleep(500);
	}//while�� 2�� ��
}

void phase3()
{
	Sleep(500);

	system("cls");

	return;
}