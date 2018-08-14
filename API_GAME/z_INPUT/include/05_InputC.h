#pragma once
#pragma once
#include "01_header.h"



//싱글톤패턴을 상속받음.
class InputC : public SingleMgr<InputC>
{
	//부모 클래스를 Friend지정
	//friend class SingleMgr<inputClass>;

private:
	DWORD   m_dwKeyState[256];        //키보드의 버튼 각각에 대한 상태를 저장하기 위한 버퍼
	POINT   m_MousePos;               //마우스 위치값. 

private:
	DWORD   KeyCheck(DWORD dwKey);    //키 입력 체크 함수


public:
	bool    Init();      // 초기화
	bool    Frame();	 // 계산
	bool    Render();	 // 드로우
	bool    Release();	 // 소멸, 삭제
public:
	DWORD   Key(DWORD dwKey);   // 인자로 넘어온 키의 상태를 반환하는 함수.
	POINT   getMousePos();      // 마우스 위치를 반환하는 함수.

public:
	InputC();
	virtual ~InputC();
};

#define I_Input InputC::GetInstance()