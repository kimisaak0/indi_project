#pragma once
#pragma once
#include "01_header.h"



//�̱��������� ��ӹ���.
class InputMgrC : public SingleMgr<InputMgrC>
{
	//�θ� Ŭ������ Friend����
	//friend class SingleMgr<inputClass>;

private:
	DWORD   m_dwKeyState[256];        //Ű������ ��ư ������ ���� ���¸� �����ϱ� ���� ����
	POINT   m_MousePos;               //���콺 ��ġ��. 

private:
	DWORD   KeyCheck(DWORD dwKey);    //Ű �Է� üũ �Լ�


public:
	bool    Init();      // �ʱ�ȭ
	bool    Frame();	 // ���
	bool    Render();	 // ��ο�
	bool    Release();	 // �Ҹ�, ����


public:
	DWORD   Key(DWORD dwKey);   // ���ڷ� �Ѿ�� Ű�� ���¸� ��ȯ�ϴ� �Լ�.
	POINT   getMousePos();      // ���콺 ��ġ�� ��ȯ�ϴ� �Լ�.

protected:
	InputMgrC();

public:
	virtual ~InputMgrC();
};

#define I_Input InputC::GetInstance()