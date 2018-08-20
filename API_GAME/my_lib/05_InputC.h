#pragma once
#pragma once
#include "01_header.h"



//싱글톤패턴을 상속받음.
class InputC : public SingleMgr<InputC>
{
	//부모 클래스를 Friend지정
	friend class SingleMgr<InputC>;

private:
	DWORD   m_dwKeyState[256];        //키보드의 버튼 각각에 대한 상태를 저장하기 위한 버퍼
	DWORD   m_dwBeforeMouseState[3];  //마우스의 버튼 각각에 대한 상태를 저장하기 위한 버퍼 (이전 입력)
private:
	DWORD   KeyCheck(DWORD dwKey);    //키 입력 체크 함수


public:
	DWORD m_dwMouseState[3];          //마우스의 버튼 각각에 대한 상태를 저장하기 위한 버퍼 (현재 입력)
	POINT m_MousePos;                 //마우스 위치값. 

	//POINT 화면상의 한 점을 저장할 수 있는 구조체

public:
	bool    Init();      // 초기화
	bool    Frame();	 // 계산
	bool    Render();	 // 드로우
	bool    Release();	 // 소멸, 삭제
public:
	DWORD  Key(DWORD dwKey);   // 인자로 넘어온 키의 상태를 반환하는 함수.
	void   MsgEvent(MSG msg);  // 마우스 버튼 입력에 따라 버퍼에 상태를 저장하는 함수

protected:
	InputC();

public:
	~InputC();

};

#define I_Input InputC::GetInstance()