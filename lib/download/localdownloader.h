#pragma once

#include "downloader.h"

class LocalDownloader: public Downloader {
public:
	LocalDownloader(char *url, BlockingQueue *arg);
	void addTask(int time);
	void delTask(int time);
	~LocalDownloader();
	void exec();
	void exit();
};