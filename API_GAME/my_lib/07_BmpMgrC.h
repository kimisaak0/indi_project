#pragma once
#include "06_BmpC.h"

//struct Cache
//{
//	int        m_iKey;
//	T_STR      m_szName;
//	BmpC*      m_pBmp;
//};
//
//class BmpMgrC : public SingleMgr<BmpMgrC>
//{
//	friend class SingleMgr<bmpMgrClass>;
//
//	std::map<int, BmpC*> m_mapList;
//	std::list<Cache> m_listCache;
//	int m_iIndex;
//
//public:
//
//	void       addCache(int iKey, T_STR szName, BmpC* pData);
//
//	BmpC*      getCache(int iKey);
//	int        getCache(T_STR szName);
//
//	BmpC*      getPtr(int iKey);
//
//	int        Load(T_STR szLoadFile);
//
//protected:
//	BmpMgrC();
//
//public:
//	virtual ~BmpMgrC();
//};

class BmpMgrC : public SingleMgr<BmpMgrC>
{
private:
	int            m_iIndex;
	vector<BmpC>   m_vBmpList;

	const int MaxImage;

public:
	bool addList(T_STR szImageName);
	

protected:
	BmpMgrC(int max);
public:
	~BmpMgrC();
};

#define I_bmpMgr BmpMgrC::GetInstance()