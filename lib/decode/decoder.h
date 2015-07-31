#pragma once

#include "../mediastream.h"

/*
* 解码器基类
*/
class Decoder {
public:
	virtual MediaStream decode(MediaStream buf) = 0;
	virtual ~Decoder() = 0;
};

class DecoderCreator {
public:
	static Decoder* GetInstance(char *type);
}