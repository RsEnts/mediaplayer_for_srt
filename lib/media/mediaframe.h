#pragma once

/* MediaData保存每一帧的流媒体文件 */
class MediaData {
private:
	friend class MediaFrame;
	int use_cot;
	char *data;
public:
	MediaData();
	MediaData(char *arg);
	~MediaData();
};

/* MediaFrame实现对MediaData的引用计数 */
class MediaFrame {
private:
	MediaData *data;
public:
	MediaFrame();
	MediaFrame(const MediaFrame &arg);
	MediaFrame& operator =(const MediaFrame &arg);
	~MediaFrame();
};