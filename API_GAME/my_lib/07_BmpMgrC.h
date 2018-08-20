#pragma once
#include "06_BmpC.h"

struct BmpNameTag
{
	int      iBmpKey;
	T_STR    szBmpName;
	BmpC*    pBmpData;
};

class BmpMgrC : public SingleMgr<BmpMgrC>
{
private:
	//int            m_iIndex;

	list<BmpNameTag> m_BmpList;

public:

	void     addBmp(int iKey, T_STR szName, BmpC* pData);
	
	BmpC*    getBmp(int iKey);
	BmpC*    getBmp(T_STR szName);

public:
	BmpMgrC();
	virtual ~BmpMgrC();

};