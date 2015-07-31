#include "../lib/mediastream.h"

MediaStream::MediaStream() {
}

MediaStream::MediaStream(MediaStream &arg) {
	data = arg.data;
}

MediaStream& MediaStream::operator =(const MediaStream &arg) {
	data = arg.data;
}

MediaStream& MediaStream::operator += (const MediaStream &arg) {
	data.insert(data.begin(), arg.data.begin(), arg.data.end());
	return *this;
}

MediaStream& MediaStream::append(const MediaFrame &arg) {
	data.push_back(arg);
	return *this;
}

MediaStream& MediaStream::append(const MediaStream &arg) {
	data.insert(data.begin(), arg.data.begin(), arg.data.end());
	return *this;
}

MediaFrame& MediaStream::operator [](int num) {
	return (num < data.size())? data[num]: MediaFrame();
}

MediaStream::~MediaStream() {
}