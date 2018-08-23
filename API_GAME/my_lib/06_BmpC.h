#pragma once
#include "01_header.h"

class BmpC
{
public:
	T_STR   m_szName;      // bmp 이름
	HBITMAP m_hBitmap;     // bmp 핸들값
	HBITMAP m_hOldBmp;     // 이전 핸들값
	HDC		m_hDC;         // 실제 DC
	HDC     m_hMemDC;      // bmp를 그리기 위한 메모리DC
	BITMAP  m_bmpInfo;     // bmp 정보

public:
	//이미지 불러오기
	bool    Load(T_STR szLoadFile);

public:
	bool    Init();      // 초기화
	bool    Frame();	 // 계산
	bool    Render();    // 드로우
	bool    Release();	 // 소멸, 삭제

public:
	BmpC();
	virtual ~BmpC();
};