//#pragma once
//#include "07_BmpMgrC.h"
//#include "05_InputC.h"
//
//
//#define LR_ROTATION 0x01
//#define TB_ROTATION 0x02
//#define LRTB_ROTATION 0x04
//
//struct dPointC
//{
//	double x, y;
//};
//
//class ObjC
//{
//public:
//	BmpC*     m_pColorBmp;
//	BmpC*     m_pMaskBmp;
//	dPointC   m_pos;
//	RECT      m_rtDraw;
//
//public:
//	virtual void Set(dPointC pos);
//	virtual void Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom);
//
//	virtual bool Load(const TCHAR* pszColor, const TCHAR* pszMask = nullptr);
//
//	virtual bool Draw(short sType, RECT* pRt = nullptr);
//	virtual bool DrawColorKey(DWORD maskColor);
//
//	virtual bool Init();
//	virtual bool Frame();
//	virtual bool Render();
//	virtual bool Release();
//
//public:
//	ObjC();
//	virtual ~ObjC();
//};