#include "15_2_ShotLaserC.h"


void ShotLaserC::setSpeed(double sx, double sy)
{
	m_dSpeedX = sx;
	m_dSpeedY = sy;

	m_bExist = true;

	m_dSpriteSpeed = 0;
	m_iSpriteDir = 1;

	m_dAngle = acos(sx / sqrt(sx*sx+sy*sy));
}

void ShotLaserC::setSpawn(double sx, double sy)
{
	m_ptSpawnPos.x = sx;
	m_ptSpawnPos.y = sy;
}



bool ShotLaserC::Frame()
{
	//m_dSpriteSpeed += g_dSecPerFrame * 0.1;

	//if (m_dSpriteSpeed > 0.01) {
	//	m_dSpriteSpeed = 0;

	//	m_rtDraw.left += m_iSpriteDir * 30;
	//	if (m_rtDraw.left > 50 || m_rtDraw.left <= 20) {
	//		m_rtDraw.left = 20;
	//		//m_iSpriteDir *= -1;
	//	}
	//}

	if (m_bExist) {
		m_ptPosition.x += m_dSpeedX * g_dSecPerFrame * 400;
		m_ptPosition.y += m_dSpeedY * g_dSecPerFrame * 400;

		CollisionObjC::Frame();

		if (m_rtCollision.right > g_rtClient.right ||
			m_rtCollision.bottom > g_rtClient.bottom ||
			m_rtCollision.left < g_rtClient.left ||
			m_rtCollision.top < g_rtClient.top) {
			m_bExist = false;
		}
	}
	return true;
}

bool ShotLaserC::Render()
{
	/*if (m_bExist) {*/

		double destWidth = 500;//m_rtDraw.right;
		double destHeight = 500;//m_rtDraw.bottom;

		HDC sourceDC = CreateCompatibleDC(g_hOnScreenDC);                                      // ȸ���� ��Ʈ�� ������ ������ DC 
		HDC destDC = CreateCompatibleDC(g_hOnScreenDC);                                        // ȸ���� ��Ʈ���� ��¹��� DC
		HBITMAP hbmResult = CreateCompatibleBitmap(g_hOnScreenDC, destWidth, destHeight);      // ȸ���� ��Ʈ���� ��¹��� �޸𸮺�Ʈ�� �ڵ�   
		HBITMAP hbmOldSource = (HBITMAP)SelectObject(sourceDC, m_pColorBmp);                   // ȸ���� ��Ʈ�� ������ DC�� ����   
		HBITMAP hbmOldDest = (HBITMAP)SelectObject(destDC, hbmResult);                         // ȸ���� ��Ʈ���� ��¹��� DC��, ȸ���� ��Ʈ���� ��¹��� �޸𸮺�Ʈ�� ����  
		HBRUSH hbrBack = CreateSolidBrush(RGB(0,0,0));                                         // ȸ������ ����, ���鿵���� ĥ�� �귯���ڵ� ����  
		HBRUSH hbrOld = (HBRUSH)SelectObject(destDC, hbrBack);                                 // �귯���ڵ� ����   

		PatBlt(destDC, 0, 0, destWidth, destHeight, PATCOPY);                 // ���õ� �귯�÷�, ȸ���� ��Ʈ���� ��¹��� DC��, �̸� ������ ä�� ����  

		DeleteObject(SelectObject(destDC, hbrOld));                             // �귯�� ����   

		double dRadian = /*m_dAngle*/ 90 * 3.141592f / 180.0f;  // ȸ���� ����(360�й�)��, ���ȴ����� ������ ����   
		double dCosine = cos(dRadian);// *0.5f + 0.5f;
		double dSine = sin(dRadian);

		int iOldGraphic = SetGraphicsMode(destDC, GM_ADVANCED);           // ������ ��ǥ���� ȸ���� ���Ͽ�, �׷��ȸ�带 Ȯ����� �����մϴ�.   

		//ȸ���� �ϸ� �ƹ��͵� �� ���. �̰� ������ �ִ�.
		XFORM xform;                                 // ȸ�� ����
		//xform.eM11 = dCosine; xform.eM12 = -dSine;   // 1�� 1��, 1�� 2��
		//xform.eM21 = dSine;   xform.eM22 = dCosine;  // 2�� 1��, 2�� 2��
		//xform.eDx = 0;              // 3�� 1�� (x�� �̵�)
		//xform.eDy = 0;              // 3�� 2�� (y�� �̵�)

		//// ������ ��ķ�, �μ�DC�� �������� ��ǥ�踦 ��ȯ.   
		//// �μ�DC�� ��´������ �޸𸮺�Ʈ���� �����Ƿ�,   
		//// �����ϰ� �ִ� �޸𸮺�Ʈ���� ��ǥü�谡 ȸ���ȴ�.   
		SetWorldTransform(destDC, &xform);

		// ȸ���� �޸�DC��, ȸ���� �̹����� ���   

		BitBlt(destDC,
			0,
			0,
			500,
			500,
			m_pColorBmp->m_hMemDC,
			0, 
			0, 
			SRCCOPY);

		////���� �ǵ�������
		//xform.eM11 = 1; xform.eM12 = 0;
		//xform.eM21 = 0; xform.eM22 = 1;
		//xform.eDx = 0; xform.eDy = 0;

		//SelectObject(sourceDC, hbmOldSource);
		//SelectObject(destDC, hbmOldDest);
		//SetWorldTransform(destDC, &xform);
		//SetGraphicsMode(destDC, iOldGraphic);

		//static HDC hTempMemDC;              // ȸ���� ��Ʈ���� ������ �޸�DC   
		//HBITMAP hTempBitmap, hOldBitmap;    // ȸ���� ��Ʈ���� ������, ��Ʈ�� �ڵ�   

		//// ���� �ѹ��� ��Ʈ��DC�� �����մϴ�.   
		//hTempMemDC = CreateCompatibleDC(g_hOnScreenDC);

		//// ��Ʈ���� ȸ���ϴ� �Լ��� ȣ���Ͽ�, ���ϵǴ� ȸ���� ��Ʈ�� �ڵ��� ����   
		//hTempBitmap = hbmResult;

		//// ȸ���� ��Ʈ�� �ڵ��� �����ϰ�,   
		//hOldBitmap = (HBITMAP)SelectObject(hTempMemDC, hTempBitmap);

		//// ������ũ��DC��, ȸ���� ��Ʈ�� �ڵ��� ������, �޸�DC�� �̹����� ����մϴ�.   
		//TransparentBlt(g_hOffScreenDC,
		//	m_rtDraw.right / 2, m_rtDraw.bottom / 2,
		//	destWidth, destHeight,
		//	hTempMemDC,
		//	m_rtDraw.left, m_rtDraw.top,
		//	m_rtDraw.right, m_rtDraw.bottom,
		//	RGB(0, 0, 0)
		//);

	//		BitBlt(g_hOffScreenDC,
	//			m_rtDraw.left / 2, m_rtDraw.top / 2,
	//			destWidth, destHeight,
	//			hTempMemDC,
	//			m_rtDraw.right, m_rtDraw.bottom,SRCCOPY);
	//	SelectObject(hTempMemDC, hOldBitmap);
	//	DeleteObject(hTempBitmap);
	//}

	///*
	//if (m_bExist) {
	//	HPEN myPen = (HPEN)GetStockObject(DC_BRUSH);
	//	HBRUSH oldPen = (HBRUSH)SelectObject(g_hOffScreenDC, mypen);

	//	SetDCBrushColor(g_hOffScreenDC, RGB(0, 200, 0));

	//	Ellipse(g_hOffScreenDC, );

	//	SelectObject(g_hOffScreenDC, oldBrush);
	//	DeleteObject(myBrush);
	//}*/

//TransparentBlt(g_hOffScreenDC,
//	m_ptPosition.x, m_ptPosition.y,
//	m_rtDraw.right, m_rtDraw.bottom,
//	m_pColorBmp->m_hMemDC,
//	m_rtDraw.left, m_rtDraw.top,
//	m_rtDraw.right, m_rtDraw.bottom,
//	RGB(255, 255, 255));

		TransparentBlt(g_hOffScreenDC,
			50, 50,
			50, 50,
			destDC,
			0, 0,
			50,50,
			RGB(255, 255, 255));


	return true;
}

dPointC ShotLaserC::getSpawn()
{
	return m_ptSpawnPos;
}