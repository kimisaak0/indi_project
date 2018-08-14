#include "05_InputMgrC.h"

InputMgrC::InputMgrC()
{

}

//private 함수

DWORD   InputMgrC::KeyCheck(DWORD dwKey)
{
	//typedef short SHORT;

	//GetKeyState()       - 동기적          호출된 시점에서 조사한 키상태를 메시지큐에 넣는다. 즉, 메시지 처리 루틴내에서 키입력을 처리해야한다.
	//GetAsyncKeyState()  - 비동기적        호출된 시점에서 키 상태를 조사하여, 메시지 큐를 거치지 않고 키입력을 리턴해준다.
	SHORT sKey = GetAsyncKeyState(dwKey);

	// 0x8000 : 이전X ~ 지금0
	// 0x8001 : 이전O ~ 지금O
	// 0x0000 : 이전X ~ 지금X
	// 0x0001 : 이전O ~ 지금X
	if (sKey & 0x8000) { // 지금 키를 눌렀는가?
		if (m_dwKeyState[dwKey] == KEY_FREE || //저장된 상태가 눌러져있지 않았거나,
			m_dwKeyState[dwKey] == KEY_UP) {   //키를 땠음.
			m_dwKeyState[dwKey] = KEY_DOWN;  //키를 눌렀다.
		}
		else {
			m_dwKeyState[dwKey] = KEY_HOLD; //키를 누르고 있다.
		}
	}
	else { //지금 키를 안 눌렀는가?
		if (m_dwKeyState[dwKey] == KEY_DOWN ||  //저장된 상태가 키를 눌렀거나.
			m_dwKeyState[dwKey] == KEY_HOLD) {  //키를 누르고 있음.
			m_dwKeyState[dwKey] = KEY_UP;   //키를 땠다.
		}
		else {
			m_dwKeyState[dwKey] = KEY_FREE; //키가 안 눌러져있다.
		}
	}
	return m_dwKeyState[dwKey];   //현재 키 상태 반환
}

//기본 함수

//키 입력 상태를 저장하는 버퍼들을 0으로 초기화해줌.
bool    InputMgrC::Init()
{
	ZeroMemory(m_dwKeyState, sizeof(DWORD) * 256);

	return true;
}

bool    InputMgrC::Frame()
{
	//스크린 좌표 : 전체 모니터 상을 기준으로 한 좌표
	//클라이언트 좌표 : 윈도우 객체를 기준으로 한 좌표

	GetCursorPos(&m_MousePos); // 마우스의 현재 스크린 좌표를 받아옴.
	ScreenToClient(g_hWnd, &m_MousePos); //스크린 좌표를 클라이언트 좌표로 변환

										 //루프를 돌며 키보드 입력 상태를 조사함.
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

//public 함수

// 지정한 키의 상태를 반환.
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