#include "19_0_EffectC.h"

void EffectC::PlayPos(double x, double y)
{
	m_ptPosition.x = x;
	m_ptPosition.y = y;

	m_ptDrawPosition.x = m_ptPosition.x + (m_rtDraw.right / 2);
	m_ptDrawPosition.y = m_ptPosition.y + (m_rtDraw.bottom / 2);
}

bool EffectC::Init()
{
	return true;
}

bool EffectC::Frame()
{
	return true;
}

bool EffectC::Render()
{
	return true;
}

bool EffectC::Release()
{
	return true;
}

bool EffectC::getExist()
{
	return m_bExist;
}

