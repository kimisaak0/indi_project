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
	BmpC*     m_pColorBmp;       //���� bmp
	BmpC*     m_pMaskBmp;        //����ũ bmp

	dPointC   m_ptPosition;      //obj�� left,top.
	dPointC   m_ptDrawPosition;   //obj�� ����

	RECT      m_rtDraw;          //obj�� �׸��� ���� ����

	bool      m_bExist;          //obj ���� ����

public:
	//��Ʈ�� �̹��� ����
	virtual bool Load(const TCHAR* pszColor, const TCHAR* pszMask = nullptr);


	//������Ʈ ��ġ ����
	virtual void Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom);

	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();

public:
	ObjC();
	virtual ~ObjC();
};