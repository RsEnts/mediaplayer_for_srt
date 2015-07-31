#pragma once

#include "blockingqueue.h"

/*
* 下载器
*/
class Downloader {
protected:
	BlockingQueue *storage;
public:
	virtual void addTask(int time) = 0;
	virtual void delTask(int time) = 0;
	virtual ~Downloader() = 0;
	virtual void exec() = 0;
	virtual void exit() = 0;
};

class DownloaderCreator {
public:
	static Downloader* GetInstance(char *url, BlockingQueue *arg);
};
