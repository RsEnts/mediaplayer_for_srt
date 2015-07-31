#pragma once

#include "../media/mediaframe.h"

class Loader {
public:
	Loader(char *url);
	virtual bool haveData() const = 0;
	virtual MediaFrame getData() = 0;
	virtual void skip(int time) = 0;
	virtual ~Loader() = 0;
};

class LoaderCreator {
public:
	static Loader* GetInstance(char *url);
};