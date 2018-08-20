#include "07_BmpMgrC.h"

BmpMgrC::BmpMgrC()
{
	
}


void     BmpMgrC::addBmp(T_STR szName, BmpC* pData)
{
	BmpNameTag Tag;
	//Tag.iBmpKey = iKey;
	Tag.szBmpName = szName;
	Tag.pBmpData = pData;

	m_BmpList.push_back(Tag);
}

//BmpC*    BmpMgrC::getBmp(int iKey)
//{
//	list<BmpNameTag>::iterator iter;
//
//	for (iter = m_BmpList.begin(); iter != m_BmpList.end(); iter++) {
//		BmpNameTag& Tag = *iter;
//		if (Tag.iBmpKey == iKey) {
//			return Tag.pBmpData;
//		}
//	}
//	return nullptr;
//}

BmpC*    BmpMgrC::getBmp(T_STR szName)
{
	list<BmpNameTag>::iterator iter;

	for (iter = m_BmpList.begin(); iter != m_BmpList.end(); iter++) {
		BmpNameTag& Tag = *iter;
		if (Tag.szBmpName == szName) {
			return Tag.pBmpData;
		}
	}
	return nullptr;
}

BmpMgrC::~BmpMgrC()
{
	list<BmpNameTag>::iterator iter;

	for (iter = m_BmpList.begin(); iter != m_BmpList.end(); iter++) {
		iter->pBmpData->Release();
	}
}