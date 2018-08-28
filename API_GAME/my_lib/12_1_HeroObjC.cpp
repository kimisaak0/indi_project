#pragma once
#include "12_1_HeroObjC.h"

HeroObjC::HeroObjC()
{
	m_rtDraw.left = 0;
	m_dSpriteSpeed = 0;

	m_dSpeedX = 0;
	m_dSpeedY = 0;
}

//�Ѿ� ����
void HeroObjC::addShort1(POINT mousePos)
{
	shot1C shot;
	shot.Init();
	shot.Load(L"../z_INPUT/data/50x50/shot1.bmp");
	shot.Set(m_ptPosition.x, m_ptPosition.y, 20, 85, 30, 30);

	double dx = mousePos.x - m_ptPosition.x;
	double dy = mousePos.y - m_ptPosition.y;
	int distance = sqrt(pow(dx, 2) + pow(dy, 2));

	shot.setSpeed(dx/distance, dy/distance);

	I_SoundMgr.PlayEffect(1);

	shot1_list.push_back(shot);
}

//void HeroObjC::makeSona()
//{
//	sonaC sona;
//
//
//
//}

bool HeroObjC::Init()
{
	CollisionObjC::Init();
	m_rtDraw.left = 0;
	m_dSpriteSpeed = 0;

	m_dSpeedX = 0;
	m_dSpeedY = 0;

	m_bSonaSw = false;

	m_sona.Init();
	m_sona.Load(L"../z_INPUT/data/50x50/sona.bmp");
	m_sona.Set(m_ptDrawPosition.x, m_ptDrawPosition.y, 0, 0, 250, 250);

	return true;
}

bool HeroObjC::Frame()
{
	if (m_bExist) {
		//���� ���ϴ�!
		if (I_Input.Key(VK_LBUTTON)) {
			m_dShotDelay += g_dSecPerFrame;
			if (m_dShotDelay >= 0.1) {
				addShort1(I_Input.m_MousePos);
				m_dShotDelay -= 0.1;
			}
		}

		//�ҳ��� ŵ�ϴ�.
		if (I_Input.Key('R') == KEY_DOWN) {
			//makeSona();
			m_bSonaSw = !m_bSonaSw;
		}

		m_sona.setPos(m_ptDrawPosition);
		m_sona.Frame();
		

		list<shot1C>::iterator shot1It;

		for (shot1It = shot1_list.begin(); shot1It != shot1_list.end(); shot1It++) {
			shot1It->Frame();
		}


		//�� ���� ��������Ʈ
		m_dSpriteSpeed += g_dSecPerFrame * 0.1;

		if (m_dSpriteSpeed > 0.01) {
			m_dSpriteSpeed = 0;

			m_rtDraw.left += 32;
			if (m_rtDraw.left >= 65) {
				m_rtDraw.left = 0;
			}
		}
		//------

		//���� ��������Ʈ ��ȯ
		if (abs(m_dSpeedX) >= abs(m_dSpeedY)) {
			if (m_dSpeedX > 0) {
				m_rtDraw.top = 69; //������
			}
			else {
				m_rtDraw.top = 36; //����
			}
		}
		else {
			if (m_dSpeedY > 0) {
				m_rtDraw.top = 0;  //�Ʒ���
			}
			else {
				m_rtDraw.top = 102; //����
			}
		}

		//���ӵ� ����
		if (I_Input.Key('W'))
		{
			if (m_dSpeedY >= -500) {
				m_dSpeedY += -1 * g_dSecPerFrame * 100.0;
			}
		}
		if (I_Input.Key('S'))
		{
			if (m_dSpeedY <= +500) {
				m_dSpeedY += +1 * g_dSecPerFrame * 100.0;
			}
		}
		if (I_Input.Key('A'))
		{
			if (m_dSpeedX >= -500) {
				m_dSpeedX += -1 * g_dSecPerFrame * 100.0;
			}
		}
		if (I_Input.Key('D'))
		{
			if (m_dSpeedX <= +500) {
				m_dSpeedX += +1 * g_dSecPerFrame * 100.0;
			}
		}

		//ȭ�� ������ ��������!
		if (m_rtCollision.right > g_rtClient.right)
		{
			m_ptPosition.x = g_rtClient.right - m_rtDraw.right;
		}
		if (m_rtCollision.bottom > g_rtClient.bottom)
		{
			m_ptPosition.y = g_rtClient.bottom - m_rtDraw.bottom;
		}
		if (m_rtCollision.left < g_rtClient.left)
		{
			m_ptPosition.x = g_rtClient.left;
		}
		if (m_rtCollision.top < g_rtClient.top)
		{
			m_ptPosition.y = g_rtClient.top;
		}

		//�� ������Ʈ�� �ε�����! �о�� (��¦ ���� ����)
		if (m_bMapCls) {
			int iOverW = m_rtOverlap.right - m_rtOverlap.left; //�浹�� ����
			int iOverH = m_rtOverlap.bottom - m_rtOverlap.top; //�浹�� ����

			if (m_rtCollision.right >= m_rtMapObj.left && m_rtCollision.left <= m_rtMapObj.right) {
				if (m_dDirY > 0) { //������ �ε���

					m_ptPosition.y -= iOverH;
				}
				else {             //�Ʒ����� �ε���.
					m_ptPosition.y += iOverH;
				}
			}

			if (m_rtCollision.bottom >= m_rtMapObj.top && m_rtCollision.top <= m_rtMapObj.bottom) {
				if (m_dDirX > 0) { //���ʿ��� �ε���
					m_ptPosition.x -= iOverW;
				}
				else {             //�����ʿ��� �ε���
					m_ptPosition.x += iOverW;
				}
			}

			m_dDirX *= -1.0f;
			m_dDirY *= -1.0f;


			m_bMapCls = false;
		}

		//�� �����Ӵ� �̵�
		m_ptPosition.y += m_dSpeedY * g_dSecPerFrame;
		m_ptPosition.x += m_dSpeedX * g_dSecPerFrame;

		Set(m_ptPosition.x, m_ptPosition.y, m_rtDraw.left, m_rtDraw.top, 32, 30);

		CollisionObjC::Frame();
	}
	return true;
}

bool HeroObjC::Render()
{
	if (m_bExist) {
		//���ΰ� �׸���
		TransparentBlt(g_hOffScreenDC,
			m_ptPosition.x, m_ptPosition.y,
			m_rtDraw.right, m_rtDraw.bottom,
			m_pColorBmp->m_hMemDC,
			m_rtDraw.left, m_rtDraw.top,
			m_rtDraw.right, m_rtDraw.bottom,
			RGB(255, 255, 255)
		);

		//�Ѿ� �׸���
		list<shot1C>::iterator shot1It;

		for (shot1It = shot1_list.begin(); shot1It != shot1_list.end(); shot1It++) {
			shot1It->Render();
		}

		//�ҳ� �׸���
		if (m_bSonaSw) {
			m_sona.Render();
		}

		//����� ��Ʈ �׸����
		//CollisionObjC::Render();
	}
	return true;
}

bool HeroObjC::Release()
{
	//�Ѿ� ������
	list<shot1C>::iterator shot1It;

	for (shot1It = shot1_list.begin(); shot1It != shot1_list.end(); ) {
		if (!shot1It->getExist()) {
			shot1It = shot1_list.erase(shot1It);
		}
		else {
			shot1It++;
		}
	}

	CollisionObjC::Release();

	return true;
}

HeroObjC::~HeroObjC()
{

}