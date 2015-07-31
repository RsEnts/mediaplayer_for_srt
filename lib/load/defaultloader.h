#pragma once

#include "loader.h"
#include "../download/downloader.h"
#include "../download/blockingqueue.h"
#include "../decode/decoder.h"

/*
* 默认加载器
*/
class DefaultLoader: public Loader {
private:
	BlockingQueue *storage;
	Downloader *downloader;
	Decoder *decoder;
public:
	DefaultLoader(char *url);
	bool haveData() const;
	MediaFrame getData();
	void skip(int time);
	~DefaultLoader();
};