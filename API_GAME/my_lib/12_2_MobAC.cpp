#pragma once
#include "12_2_MobAC.h"

int MobAC::g_maxId = 0;

MobAC::MobAC()
{
	m_rtDraw.left = 0;
	m_dSpriteSpeed = 0;
//	m_iSpriteIndex = 0;
	
	m_dDirChg = 0;
	m_dMoveCycleSpeed = 0;

	m_dDirX = (rand() % 2) ? +1 : -1;
	m_dDirY = (rand() % 2) ? +1 : -1;

	m_dSpeedX = rand() % 30 + 15;
	m_dSpeedY = rand() % 30 + 15;

	m_iId = g_maxId++;

	m_iMaxHp = 10;
	m_iCurrentHP = m_iMaxHp;

	m_iFSMid = 0;
}

int MobAC::Hit()
{
	if (m_iCurrentHP > 0) {
		return --m_iCurrentHP;
	}
	else {
		return 0;
	}
}

bool MobAC::Init()
{
	CollisionObjC::Init();
	m_rtDraw.left = 0;
	m_dSpriteSpeed = 0;
//	m_iSpriteIndex = 0;

	m_dDirChg = 0;
	m_dMoveCycleSpeed = 0;

	m_dDirX = (rand() % 2) ? +1 : -1;
	m_dDirY = (rand() % 2) ? +1 : -1;

	m_dSpeedX = rand() % 30 + 15;
	m_dSpeedY = rand() % 30 + 15;

	m_iId = g_maxId++;

	return true;
}

bool MobAC::Frame()
{
	if (m_bExist) {

		if (m_iCurrentHP <= 0) {
			m_bExist = false;
		}

		//������ �Ĵ��Ĵ�
		m_dSpriteSpeed += g_dSecPerFrame * 0.1;

		if (m_dSpriteSpeed > 0.01) {
			m_dSpriteSpeed = 0;

			m_rtDraw.left += 32;
			if (m_rtDraw.left >= 65) {
				m_rtDraw.left = 0;
			}
		}

		switch (m_iFSMid) {
			case 0: { //���� 0 (�����̵�)
				//���� ��ȯ 8����!
				m_dDirChg += g_dSecPerFrame * 0.1;
				if (m_dDirChg > 0.5) {
					m_dDirChg = 0;

					m_dDirX = (rand() % 2) ? +1 : -1;
					m_dDirY = (rand() % 2) ? +1 : -1;

					m_dSpeedX = rand() % 30 + 15;
					m_dSpeedY = rand() % 30 + 15;
				}

			}; break; 

			case 1: { //���� 1 (����)
				double dx = m_ptDest.x - m_ptPosition.x;
				double dy = m_ptDest.y - m_ptPosition.y;
				double distance = sqrt(pow(dx, 2) + pow(dy, 2));

				m_dSpeedX = (abs(dx) / distance) * 100;
				m_dSpeedY = (abs(dy) / distance) * 100;

				m_dDirX = (dx > 0) ? +1 : -1;
				m_dDirY = (dy > 0) ? +1 : -1;
				
				if (abs(dx) < 0.1 && abs(dy) < 0.1) {
					m_iFSMid = 0;
				}

			} break;
		}

		//�̵�
		m_ptPosition.x += m_dDirX * m_dSpeedX * g_dSecPerFrame;
		m_ptPosition.y += m_dDirY * m_dSpeedY * g_dSecPerFrame;

		if (m_dDirX == 1) {
			if (m_dDirY == 1) {
				m_dSpeedX <= m_dSpeedY ? m_rtDraw.top = 64 : m_rtDraw.top = 0;
			}
			else {
				m_dSpeedX <= m_dSpeedY ? m_rtDraw.top = 64 : m_rtDraw.top = 96;
			}
		}
		else {
			if (m_dDirY == 1) {
				m_dSpeedX <= m_dSpeedY ? m_rtDraw.top = 32 : m_rtDraw.top = 0;
			}
			else {
				m_dSpeedX <= m_dSpeedY ? m_rtDraw.top = 32 : m_rtDraw.top = 96;
			}
		}



		//ȭ�� ������ ��������!
		if (m_rtCollision.right > g_rtClient.right)
		{
			m_dDirX *= -1.0f;
			m_ptPosition.x = g_rtClient.right - m_rtDraw.right;
		}
		if (m_rtCollision.bottom > g_rtClient.bottom)
		{
			m_dDirY *= -1.0f;
			m_ptPosition.y = g_rtClient.bottom - m_rtDraw.bottom;
		}
		if (m_rtCollision.left < g_rtClient.left)
		{
			m_dDirX *= -1.0f;
			m_ptPosition.x = g_rtClient.left;
		}
		if (m_rtCollision.top < g_rtClient.top)
		{
			m_dDirY *= -1.0f;
			m_ptPosition.y = g_rtClient.top;
		}

		//�� ������Ʈ�� �ε�����! �о�� 
		if (m_bMapCls) {
			int iOverW = m_rtOverlap.right - m_rtOverlap.left; //�浹�� ����
			int iOverH = m_rtOverlap.bottom - m_rtOverlap.top; //�浹�� ����
			//OK

			dPointC ptObjM;
			ptObjM.x = (m_rtMapObj.right + m_rtMapObj.left) / 2;
			ptObjM.y = (m_rtMapObj.bottom + m_rtMapObj.top) / 2;

			dPointC CollDir;
			CollDir.x = m_ptDrawPosition.x - ptObjM.x;
			CollDir.y = m_ptDrawPosition.y - ptObjM.y;

			dPointC delta;
			delta.x = m_rtMapObj.right - m_rtMapObj.left;
			delta.y = m_rtMapObj.bottom - m_rtMapObj.top;

			if (CollDir.x * delta.y < CollDir.y * delta.x) {
				if (-(CollDir.x) * delta.y < CollDir.y * delta.x) {
					//�Ʒ����� ���� �浹
					m_ptPosition.y += iOverH;
				}
				else {
					//���ʿ��� ���������� �浹
					m_ptPosition.x -= iOverW;
				}
			}
			else {
				if (-(CollDir.x)*delta.y < CollDir.y * delta.x) {
					//�����ʿ��� ��������
					m_ptPosition.x += iOverW;
				}
				else {
					//������ �Ʒ���
					m_ptPosition.y -= iOverH;
				}
			}

  			m_dDirX *= -1.0f;
			m_dDirY *= -1.0f;


			m_bMapCls = false;
		}

		Set(m_ptPosition.x, m_ptPosition.y, m_rtDraw.left, m_rtDraw.top, 32, 32);

		CollisionObjC::Frame();

	}

	return true;
}

bool MobAC::Render()
{
	if (m_bExist) {
		//HP�� �׸���
		HBRUSH myBrush = (HBRUSH)GetStockObject(DC_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(g_hOffScreenDC, myBrush);

		SetDCBrushColor(g_hOffScreenDC, RGB(0, 0, 0));
		Rectangle(g_hOffScreenDC, m_ptPosition.x, m_ptPosition.y - 7, m_ptPosition.x + 100 * 0.3, m_ptPosition.y - 2);

		SetDCBrushColor(g_hOffScreenDC, RGB(255, 0, 0));
		Rectangle(g_hOffScreenDC, m_ptPosition.x, m_ptPosition.y - 7, m_ptPosition.x + (m_iCurrentHP * 100 / m_iMaxHp) * 0.3, m_ptPosition.y - 2);

		SelectObject(g_hOffScreenDC, oldBrush);
		DeleteObject(myBrush);


		//��ü �׸���
		TransparentBlt(g_hOffScreenDC,
			m_ptPosition.x, m_ptPosition.y,
			m_rtDraw.right, m_rtDraw.bottom,
			m_pColorBmp->m_hMemDC,
			m_rtDraw.left, m_rtDraw.top,
			m_rtDraw.right, m_rtDraw.bottom,
			RGB(255, 255, 255)
		);

		CollisionObjC::Render();
	}

	return true;
}


dPointC MobAC::getPt()
{
	return m_ptPosition;
}

void MobAC::setFSM(int id)
{
	m_iFSMid = id;
}

void MobAC::setDest(dPointC pt)
{
	m_ptDest = pt;
}



MobAC::~MobAC()
{

}