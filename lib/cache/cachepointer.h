#pragma once

#include "mediacache.h"

/*
* loadPtr: 从当前帧开始，Buffer向Plugins传输的最后一帧位置
* cachePtr: 从当前帧开始，Buffer从Plugins接收的最后一帧位置
*/
class CachePointer {
private:
	MediaCache *mediacache;
public:
	CachePointer(MediaCache *arg);
	virtual int loadPtr() const;
	virtual int cachePtr() const;
	virtual bool canLoadNext() const;
	virtual bool canCacheNext() const;
	virtual void loadNext();
	virtual void cacheNext();
	virtual ~CachePointer();
};

class CachePointerCreator {
public:
	static CachePointer* GetInstance(MediaCache *arg);
};