#pragma once
#include "07_BmpMgrC.h"
#include "05_InputC.h"


#define LR_ROTATION 0x01
#define TB_ROTATION 0x02
#define LRTB_ROTATION 0x04

struct dPointC
{
	double x, y;
};

class ObjC
{
protected:
	BmpC*     m_pColorBmp;       //원본 bmp
	BmpC*     m_pMaskBmp;        //마스크 bmp

	dPointC   m_ptPosition;      //obj의 left,top.
	dPointC   m_ptDrawPosition;   //obj의 중점

	RECT      m_rtDraw;          //obj를 그리기 위한 정보

	bool      m_bExist;          //obj 존재 여부

public:
	//비트맵 이미지 세팅
	virtual bool Load(const TCHAR* pszColor, const TCHAR* pszMask = nullptr);


	//오브젝트 위치 설정
	virtual void Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom);

	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();

public:
	ObjC();
	virtual ~ObjC();
};