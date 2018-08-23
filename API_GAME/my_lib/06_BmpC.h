#pragma once
#include "01_header.h"

class BmpC
{
public:
	T_STR   m_szName;      // bmp �̸�
	HBITMAP m_hBitmap;     // bmp �ڵ鰪
	BITMAP  m_bmpInfo;     // bmp ����
	HDC     m_hMemDC;      // bmp�� �׸��� ���� MemDC


public:
	//�̹��� �ҷ�����
	bool    Load(T_STR szLoadFile);

public:
	bool    Init();      // �ʱ�ȭ
	bool    Frame();	 // ���
	bool    Render();	 // ��ο�
	bool    Release();	 // �Ҹ�, ����

public:
	BmpC();
	virtual ~BmpC();
};