#pragma once
#include "01_header.h"

class BmpC
{
public:
	T_STR   m_szName;      // bmp �̸�
	HBITMAP m_hBitmap;     // bmp �ڵ鰪
	HBITMAP m_hOldBmp;     // ���� �ڵ鰪
	HDC		m_hDC;         // ���� DC
	HDC     m_hMemDC;      // bmp�� �׸��� ���� �޸�DC
	BITMAP  m_bmpInfo;     // bmp ����

public:
	//�̹��� �ҷ�����
	bool    Load(T_STR szLoadFile);

public:
	bool    Init();      // �ʱ�ȭ
	bool    Frame();	 // ���
	bool    Render();    // ��ο�
	bool    Release();	 // �Ҹ�, ����

public:
	BmpC();
	virtual ~BmpC();
};