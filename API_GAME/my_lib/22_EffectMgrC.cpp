#include "22_EffectMgrC.h"

bool EffectMgrC::Load(EffectC* ef)
{
	m_Effect_vector.push_back(ef);
	return true;
}

bool EffectMgrC::Play(int iIndex, double x, double y)
{

	//한번에 하나의 이미지만 출력가능
	//즉, 처음 위치와 두번째 위치에 대한 출력이 겹치면 두번째에서만 출력됨.

	//깜빡임은 사용이 잘못되어서로 보임.
	//하지만 이곳에서의 문제일 가능성도 있음.

	m_Effect_vector[iIndex]->PlayPos(x, y);

	//m_Effect_vector[iIndex]->Frame();
	m_Effect_vector[iIndex]->Render();
	
	return true;
}