#pragma once
#include "13_1MouseObjC.h"

MouseObjC::MouseObjC()
{

}

void MouseObjC::Set(double x, double y, DWORD left, DWORD top, DWORD right, DWORD bottom)
{
	GetCursorPos(&m_MousePos); // ���콺�� ���� ��ũ�� ��ǥ�� �޾ƿ�.
	ScreenToClient(g_hWnd, &m_MousePos); //��ũ�� ��ǥ�� Ŭ���̾�Ʈ ��ǥ�� ��ȯ

	m_rtDraw.left = left;
	m_rtDraw.top = top;
	m_rtDraw.right = right;
	m_rtDraw.bottom = bottom;

	m_ptPosition.x = (double)m_MousePos.x;
	m_ptPosition.y = (double)m_MousePos.y;

	m_ptDrawPosition.x = m_ptPosition.x + (m_rtDraw.right / 2);
	m_ptDrawPosition.y = m_ptPosition.y + (m_rtDraw.bottom / 2);

}


bool MouseObjC::Frame()
{
	GetCursorPos(&m_MousePos); // ���콺�� ���� ��ũ�� ��ǥ�� �޾ƿ�.
	ScreenToClient(g_hWnd, &m_MousePos); //��ũ�� ��ǥ�� Ŭ���̾�Ʈ ��ǥ�� ��ȯ


	m_ptPosition.x = (double)m_MousePos.x;
	m_ptPosition.y = (double)m_MousePos.y;

	m_ptDrawPosition.x = m_ptPosition.x + (m_rtDraw.right / 2);
	m_ptDrawPosition.y = m_ptPosition.y + (m_rtDraw.bottom / 2);


	return true;

}

bool MouseObjC::Render()
{
	TransparentBlt(g_hOffScreenDC,
		m_ptPosition.x, m_ptPosition.y,
		50, 50,
		m_pColorBmp->m_hMemDC,
		m_rtDraw.left, m_rtDraw.top,
		m_rtDraw.right, m_rtDraw.bottom,
		RGB(255, 255, 255)
	);

	return true;
}

MouseObjC::~MouseObjC()
{

}