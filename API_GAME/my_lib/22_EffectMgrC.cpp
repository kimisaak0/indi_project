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

	//�ѹ��� �ϳ��� �̹����� ��°���
	//��, ó�� ��ġ�� �ι�° ��ġ�� ���� ����� ��ġ�� �ι�°������ ��µ�.

	//�������� ����� �߸��Ǿ�� ����.
	//������ �̰������� ������ ���ɼ��� ����.

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