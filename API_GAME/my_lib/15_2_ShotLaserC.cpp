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

		HDC sourceDC = CreateCompatibleDC(g_hOnScreenDC);                                      // 회전할 비트맵 원본을 선택할 DC 
		HDC destDC = CreateCompatibleDC(g_hOnScreenDC);                                        // 회전할 비트맵을 출력받을 DC
		HBITMAP hbmResult = CreateCompatibleBitmap(g_hOnScreenDC, destWidth, destHeight);      // 회전할 비트맵을 출력받을 메모리비트맵 핸들   
		HBITMAP hbmOldSource = (HBITMAP)SelectObject(sourceDC, m_pColorBmp);                   // 회전할 비트맵 원본을 DC에 선택   
		HBITMAP hbmOldDest = (HBITMAP)SelectObject(destDC, hbmResult);                         // 회전할 비트맵을 출력받을 DC에, 회전할 비트맵을 출력받을 메모리비트맵 선택  
		HBRUSH hbrBack = CreateSolidBrush(RGB(0,0,0));                                         // 회전으로 인한, 공백영역을 칠할 브러시핸들 생성  
		HBRUSH hbrOld = (HBRUSH)SelectObject(destDC, hbrBack);                                 // 브러시핸들 선택   

		PatBlt(destDC, 0, 0, destWidth, destHeight, PATCOPY);                 // 선택된 브러시로, 회전할 비트맵을 출력받을 DC에, 미리 색상을 채워 지움  

		DeleteObject(SelectObject(destDC, hbrOld));                             // 브러시 해제   

		double dRadian = /*m_dAngle*/ 90 * 3.141592f / 180.0f;  // 회전할 각도(360분법)를, 라디안단위의 각도로 변경   
		double dCosine = cos(dRadian);// *0.5f + 0.5f;
		double dSine = sin(dRadian);

		int iOldGraphic = SetGraphicsMode(destDC, GM_ADVANCED);           // 윈도우 좌표계의 회전을 위하여, 그래픽모드를 확장모드로 변경합니다.   

		//회전을 하면 아무것도 안 뜬다. 이건 문제가 있다.
		XFORM xform;                                 // 회전 성분
		//xform.eM11 = dCosine; xform.eM12 = -dSine;   // 1행 1열, 1행 2열
		//xform.eM21 = dSine;   xform.eM22 = dCosine;  // 2행 1열, 2행 2열
		//xform.eDx = 0;              // 3행 1열 (x축 이동)
		//xform.eDy = 0;              // 3행 2열 (y축 이동)

		//// 설정한 행렬로, 인수DC의 윈도우즈 좌표계를 변환.   
		//// 인수DC는 출력대상으로 메모리비트맵을 가지므로,   
		//// 선택하고 있는 메모리비트맵의 좌표체계가 회전된다.   
		SetWorldTransform(destDC, &xform);

		// 회전된 메모리DC에, 회전할 이미지를 출력   

		BitBlt(destDC,
			0,
			0,
			500,
			500,
			m_pColorBmp->m_hMemDC,
			0, 
			0, 
			SRCCOPY);

		////쓴거 되돌려놓기
		//xform.eM11 = 1; xform.eM12 = 0;
		//xform.eM21 = 0; xform.eM22 = 1;
		//xform.eDx = 0; xform.eDy = 0;

		//SelectObject(sourceDC, hbmOldSource);
		//SelectObject(destDC, hbmOldDest);
		//SetWorldTransform(destDC, &xform);
		//SetGraphicsMode(destDC, iOldGraphic);

		//static HDC hTempMemDC;              // 회전한 비트맵을 선택할 메모리DC   
		//HBITMAP hTempBitmap, hOldBitmap;    // 회전한 비트맵을 저장할, 비트맵 핸들   

		//// 최초 한번만 비트맵DC를 생성합니다.   
		//hTempMemDC = CreateCompatibleDC(g_hOnScreenDC);

		//// 비트맵을 회전하는 함수를 호출하여, 리턴되는 회전된 비트맵 핸들을 저장   
		//hTempBitmap = hbmResult;

		//// 회전된 비트맵 핸들을 선택하고,   
		//hOldBitmap = (HBITMAP)SelectObject(hTempMemDC, hTempBitmap);

		//// 오프스크린DC에, 회전된 비트맵 핸들을 선택한, 메모리DC의 이미지를 출력합니다.   
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