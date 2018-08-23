#include "05_InputMgrC.h"

InputMgrC::InputMgrC()
{

}

//private �Լ�

DWORD   InputMgrC::KeyCheck(DWORD dwKey)
{
	//typedef short SHORT;

	//GetKeyState()       - ������          ȣ��� �������� ������ Ű���¸� �޽���ť�� �ִ´�. ��, �޽��� ó�� ��ƾ������ Ű�Է��� ó���ؾ��Ѵ�.
	//GetAsyncKeyState()  - �񵿱���        ȣ��� �������� Ű ���¸� �����Ͽ�, �޽��� ť�� ��ġ�� �ʰ� Ű�Է��� �������ش�.
	SHORT sKey = GetAsyncKeyState(dwKey);

	// 0x8000 : ����X ~ ����0
	// 0x8001 : ����O ~ ����O
	// 0x0000 : ����X ~ ����X
	// 0x0001 : ����O ~ ����X
	if (sKey & 0x8000) { // ���� Ű�� �����°�?
		if (m_dwKeyState[dwKey] == KEY_FREE || //����� ���°� ���������� �ʾҰų�,
			m_dwKeyState[dwKey] == KEY_UP) {   //Ű�� ����.
			m_dwKeyState[dwKey] = KEY_DOWN;  //Ű�� ������.
		}
		else {
			m_dwKeyState[dwKey] = KEY_HOLD; //Ű�� ������ �ִ�.
		}
	}
	else { //���� Ű�� �� �����°�?
		if (m_dwKeyState[dwKey] == KEY_DOWN ||  //����� ���°� Ű�� �����ų�.
			m_dwKeyState[dwKey] == KEY_HOLD) {  //Ű�� ������ ����.
			m_dwKeyState[dwKey] = KEY_UP;   //Ű�� ����.
		}
		else {
			m_dwKeyState[dwKey] = KEY_FREE; //Ű�� �� �������ִ�.
		}
	}
	return m_dwKeyState[dwKey];   //���� Ű ���� ��ȯ
}

//�⺻ �Լ�

//Ű �Է� ���¸� �����ϴ� ���۵��� 0���� �ʱ�ȭ����.
bool    InputMgrC::Init()
{
	ZeroMemory(m_dwKeyState, sizeof(DWORD) * 256);

	return true;
}

bool    InputMgrC::Frame()
{
	//��ũ�� ��ǥ : ��ü ����� ���� �������� �� ��ǥ
	//Ŭ���̾�Ʈ ��ǥ : ������ ��ü�� �������� �� ��ǥ

	GetCursorPos(&m_MousePos); // ���콺�� ���� ��ũ�� ��ǥ�� �޾ƿ�.
	ScreenToClient(g_hWnd, &m_MousePos); //��ũ�� ��ǥ�� Ŭ���̾�Ʈ ��ǥ�� ��ȯ

										 //������ ���� Ű���� �Է� ���¸� ������.
	for (int iKey = 0; iKey < 255; iKey++) {
		m_dwKeyState[iKey] = KeyCheck(iKey);
	}

	return true;
}

bool    InputMgrC::Render()
{
	return true;
}

bool    InputMgrC::Release()
{
	return true;
}

//public �Լ�

// ������ Ű�� ���¸� ��ȯ.
DWORD   InputMgrC::Key(DWORD dwKey)
{
	return m_dwKeyState[dwKey];
}

POINT   InputMgrC::getMousePos()
{
	return m_MousePos;
}

InputMgrC::~InputMgrC()
{

}