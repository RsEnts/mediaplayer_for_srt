#pragma once

#include <vector>
#include <mutex>

class BlockingQueue {
private:
	std::list<MediaStream> data;
public:
	void push(MediaStream arg);
	MediaStream pop();
	bool hasData() const;
};

