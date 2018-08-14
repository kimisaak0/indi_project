#include "07_BmpMgrC.h"



BmpMgrC::BmpMgrC(int max) : MaxImage(max)
{
	m_iIndex = 0;

	m_vBmpList.reserve(MaxImage);

}

bool BmpMgrC::addList(T_STR szImageName)
{
	vector<BmpC>::iterator iter;
	
	for (iter = m_vBmpList.begin(); iter != m_vBmpList.end(); iter++) {
		
	}
}


//void       BmpMgrC::addCache(int iKey, T_STR szName, BmpC* pData)
//{
//	Cache cache;
//	cache.m_iKey = iKey;
//	cache.m_szName = szName;
//	cache.m_pBmp = pData;
//
//	if (m_listCache.size() >= 3) {
//		m_listCache.pop_front();
//	}
//
//	m_listCache.push_back(cache);
//}
//
//
//int        BmpMgrC::getCache(T_STR szName)
//{
//	std::list<Cache>::iterator iter;
//
//	for (iter = m_listCache.begin(); iter != m_listCache.end(); iter++) {
//		Cache& cache = *iter;
//		if (cache.m_szName == szName) {
//			return cache.m_iKey;
//		}
//	}
//	return -1;
//}
//
//BmpC*  BmpMgrC::getCache(int iKey)
//{
//	std::list<Cache>::iterator iter;
//
//	for (iter = m_listCache.begin(); iter != m_listCache.end(); iter++) {
//		Cache& cache = *iter;
//		if (cache.m_iKey == iKey) {
//			return cache.m_pBmp;
//		}
//	}
//	return nullptr;
//}
//
//BmpC*  BmpMgrC::getPtr(int iKey)
//{
//	BmpC* pBmp = getCache(iKey);
//
//	if (pBmp) {
//		return pBmp;
//	}
//
//	std::map<int, BmpC*>::iterator iter;
//	iter = m_mapList.find(iKey);
//	if (iter == m_mapList.end()) {
//		return nullptr;
//	}
//	return (*iter).second;
//}
//
//int        BmpMgrC::Load(T_STR szLoadFile)
//{
//	T_STR szName = szLoadFile;
//	int iKey = getCache(szName);
//
//	if (iKey > 0) {
//		return iKey;
//	}
//
//	std::map<int, BmpC*>::iterator iter;
//
//	for (iter = m_mapList.begin(); iter != m_mapList.end(); iter++) {
//		BmpC* pBmp = (BmpC*)(*iter).second;
//		if (pBmp->m_szName == szName) {
//			addCache((*iter).first, szName, pBmp);
//			return (*iter).first;
//		}
//	}
//
//	BmpC* pBmp = new BmpC;
//	if (pBmp->Load(szLoadFile)) {
//		m_mapList.insert(std::make_pair(++m_iIndex, pBmp));
//		addCache(m_iIndex, szName, pBmp);
//		return m_iIndex;
//	}
//
//	return -1;
//}


BmpMgrC::~BmpMgrC()
{
}
