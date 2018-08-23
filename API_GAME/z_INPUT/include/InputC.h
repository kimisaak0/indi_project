#pragma once
#include "header.h"

enum KeyState
{
	KEY_FREE = 0,
	KEY_DOWN,
	KEY_UP,
	KEY_HOLD,
};

//�̱��������� ��ӹ���.
class InputC : public SingleMgr<InputC>
{
	//�θ� Ŭ������ Friend����
//	friend class SingleMgr<inputClass>;

private:
	DWORD   m_dwKeyState[256];        //Ű������ ��ư ������ ���� ���¸� �����ϱ� ���� ����
	DWORD   m_dwBeforeMouseState[3];  //���콺�� ��ư ������ ���� ���¸� �����ϱ� ���� ���� (���� �Է�)
private:
	DWORD   KeyCheck(DWORD dwKey);    //Ű �Է� üũ �Լ�


public:
	DWORD m_dwMouseState[3];          //���콺�� ��ư ������ ���� ���¸� �����ϱ� ���� ���� (���� �Է�)
	POINT m_MousePos;                 //���콺 ��ġ��. 

									  //POINT ȭ����� �� ���� ������ �� �ִ� ����ü

public:
	bool    Init();      // �ʱ�ȭ
	bool    Frame();	 // ���
	bool    Render();	 // ��ο�
	bool    Release();	 // �Ҹ�, ����
public:
	DWORD  Key(DWORD dwKey);   // ���ڷ� �Ѿ�� Ű�� ���¸� ��ȯ�ϴ� �Լ�.
	void   MsgEvent(MSG msg);  // ���콺 ��ư �Է¿� ���� ���ۿ� ���¸� �����ϴ� �Լ�

public:
	InputC() {}
	virtual ~InputC() {}
};

#define I_Input InputC::GetInstance()