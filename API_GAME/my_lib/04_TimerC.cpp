#include "04_TimerC.h"

//timeGetTime() : winmm.lib �߰��ؾ���
//#pragma comment(lib, "winmm.lib")

// 1Tick == 1/1000��
//timeGetTime() : �����찡 ���۵Ǿ� ���ݱ��� �帥 �ð��� 1Tick������ �������ִ� �Լ�.

// ���α׷� ���� �ð�(Tick����)
double g_dSecPerFrame;
double g_dGameTimer;

TimerC::TimerC()
{
	m_dwFrameCounter = (DWORD)0.0;
	m_dwFPS = (DWORD)0.0;
	m_dwBeforeTick = (DWORD)0.0;
	m_dSecPerFrame = 0.0;
	m_dGameTimer = 0.0;
	m_dTimer = 0.0;

	g_dSecPerFrame = m_dSecPerFrame;
}



bool    TimerC::Init()
{

	m_dwBeforeTick = timeGetTime();

	return true;
}

bool    TimerC::Frame()
{
	DWORD dwCurrentTick = timeGetTime();                   	// ���� �ð�(Tick����)

	DWORD dwElapseTick = dwCurrentTick - m_dwBeforeTick;    //�� ����� �ϱ���� ����� �ð�. (tick����)

	m_dSecPerFrame = dwElapseTick / 1000.0;                 // dwElapseTick�� �ʴ����� ��ȯ
	g_dSecPerFrame = m_dSecPerFrame;

	m_dGameTimer += m_dSecPerFrame;                        	//�ʴ��� ����
	g_dGameTimer = m_dGameTimer;

	m_dTimer += m_dSecPerFrame;                            	//�ʴ��� ����

	if (m_dTimer >= 1.0) {               //1�� �̻� ��������
		m_dwFPS = m_dwFrameCounter;      //1�� ���� ������ Frame�� ����
		m_dwFrameCounter = 0;            //������ Frame�� 0���� �ʱ�ȭ
		m_dTimer -= 1.0;                 //dTimer���� 1�� ����

		_stprintf_s(m_csBuffer,          //���ۿ� ���
			L"FPS:%d TIME:%10.4f SPF:%10.4f",
			m_dwFPS, m_dGameTimer, m_dSecPerFrame);

		//OutputDebugString(m_csBuffer);
	}

	m_dwFrameCounter++; //Frame ����

						//���� Tick ����
	m_dwBeforeTick = dwCurrentTick;
	return true;
}

// DC :
// API������ ȭ�� ��¿� �ʿ��� ��� ������ ������ ������ ����ü
// GDI�� ���ؼ� ������
// ��Ʈ, ����, ����, ��� ��� � ���� ������ ��� ����.

// HDC      : DC�� �ڵ�
// GetDC()  : ���� ���α׷��� HDC�� �޾ƿ��� �Լ�. 

// TextOut(hdc, nXStart, nYStart, lpString, cchString)  : 
// api���� �ܼ��ϰ� �ؽ��� ����ϴ� �Լ�. 
// hdc : ����� �������� �ڵ�
// nXStart, nYStart : ����� ��ġ
// lpString : ����� ���ڿ�
// cchString : ���ڿ��� ����

bool    TimerC::Render()
{
	HDC t_hdc = GetDC(g_hWnd);

	TextOut(t_hdc, 0, 0, m_csBuffer, (int)wcslen(m_csBuffer));	//������ ���ڿ� �Ѹ���

	ReleaseDC(g_hWnd,t_hdc);

	//SetBkColor(g_hOffScreenDC, RGB(255, 255, 255));
	//SetTextColor(g_hOffScreenDC, RGB(0, 0, 255));
	//TextOut(g_hOffScreenDC, 0, 0, m_csBuffer, (int)wcslen(m_csBuffer));	//MemDC�� ���ڿ� �׸���
	

	return true;
}

bool    TimerC::Release()
{
	return true;
}


//double  TimerC::getSPF()
//{
//	return m_dSecPerFrame;
//}
//
//TCHAR*   TimerC::outTimer()
//{
//	return m_csBuffer;
//}



TimerC::~TimerC()
{
}
