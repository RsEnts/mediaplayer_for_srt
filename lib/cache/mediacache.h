#pragma once

#include "../media/mediaframe.h"

class CachePointer;

class MediaCache {
public:
	friend class CachePointer;
	
	virtual void insert(MediaFrame data, int time);
	virtual MediaFrame operator [](int num) const;
	virtual void reserve(int _size);
	virtual int size() const;
	virtual ~MediaCache();
};

class MediaCacheCreator {
public:
	static MediaCacha* GetInstance();
}