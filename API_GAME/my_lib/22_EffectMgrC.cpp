#include "22_EffectMgrC.h"

bool EffectMgrC::Load(EffectC* ef)
{
	m_Effect_vector.push_back(ef);
	return true;
}

bool EffectMgrC::Play(int iIndex, double x, double y)
{

	//�ѹ��� �ϳ��� �̹����� ��°���
	//��, ó�� ��ġ�� �ι�° ��ġ�� ���� ����� ��ġ�� �ι�°������ ��µ�.

	//�������� ����� �߸��Ǿ�� ����.
	//������ �̰������� ������ ���ɼ��� ����.

	m_Effect_vector[iIndex]->PlayPos(x, y);

	//m_Effect_vector[iIndex]->Frame();
	m_Effect_vector[iIndex]->Render();
	
	return true;
}