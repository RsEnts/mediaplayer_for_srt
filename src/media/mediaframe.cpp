#include "../lib/mediaframe.h"

MediaData::MediaData()
	: data(NULL), use_cot(0) {
}

MediaData::MediaData(char *arg)
	: data(arg), use_cot(1) {
}

MediaData::~MediaData() {
	delete data;
}

MediaFrame::MediaFrame() {
	data = new MediaData();
}

MediaFrame::MediaFrame(const MediaFrame &arg) {
	++arg.data->use_cot;
	data = arg.data;
}

MediaFrame& MediaFrame::operator = (const MediaFrame &arg) {
	if (&arg == this)
		return *this; // self-assign
	if (--data->use_cot == 0)
		delete data;
	++arg.data->use_cot;
	data = arg.data;
	return *this;
}

MediaFrame::~MediaFrame() {
	if (--data->use_cot == 0)
		delete data;
}