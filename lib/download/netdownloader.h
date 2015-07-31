#pragma once

#include "downloader.h"

class NetDownloader: public Downloader {
public:
	NetDownloader(char *url, BlockingQueue *arg);
	void addTask(int time);
	void delTask(int time);
	~NetDownloader();
	void exec();
	void exit();
};