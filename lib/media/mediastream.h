#pragma once

#include "mediaframe.h"
#include <vector>

/* MediaStream保存一个流媒体文件 */
class MediaStream {
private:
	std::vector<MediaFrame> data;
public:
	MediaStream();
	MediaStream(MediaStream &arg);
	MediaStream& operator =(const MediaStream &arg);
	MediaStream& operator += (const MediaStream &arg);
	MediaStream& append(const MediaFrame &arg);
	MediaStream& append(const MediaStream &arg);
	MediaFrame& operator [](int num);
	~MediaStream();
};