#include "22_EffectMgrC.h"

bool EffectMgrC::RegisterEffect(EffectC* ef, int index, int i)
{
	m_Effect_amount.push_back(i);
	m_Effect_current_Number.push_back(0);

	m_Effect_vector.resize(index+1);
	for (int ix = 0; ix < i; ix++) {
		m_Effect_vector[index].push_back(ef);
	}
	return true;
}

bool EffectMgrC::Play(int index, double x, double y)
{
	m_Effect_current_Number[index];

	//한번에 하나의 이미지만 출력가능
	//즉, 처음 위치와 두번째 위치에 대한 출력이 겹치면 두번째에서만 출력됨.

	//깜빡임은 사용이 잘못되어서로 보임.
	//하지만 이곳에서의 문제일 가능성도 있음.

	m_Effect_vector[index][m_Effect_current_Number[index]]->PlayPos(x, y);

	//m_Effect_vector[iIndex]->Frame();
	m_Effect_vector[index][m_Effect_current_Number[index]]->Render();

	if (m_Effect_current_Number[index] < m_Effect_amount[index]) {
		m_Effect_current_Number[index]++;
	}
	else {
		m_Effect_current_Number[index] = 0;
	}
	
	return true;
}