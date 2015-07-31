#pragma once

#include "load/loader.h"
#include "plugins/plugin.h"
#include "media/mediaframe.h"
#include "cache/cachepointer.h"
#include "cache/mediacache.h"

/*
* Buffer用于缓存流媒体数据并预先处理插件对每一帧信息的修改
* 独立于Player运行，由exec函数控制Buffer运行
* Buffer自主向Loader请求数据，并放入data
* CachePointer控制向插件传输数据的最后帧的位置以及接收插件反馈的最后帧的位置
*/
class Buffer {
protected:
	Loader *loader; // 加载器
	Plugin *plugins; // 插件
	MediaCache *data; // 已加载的流媒体数据
	CachePointer *cachePtr; // 流媒体处理指针
public:
	/* 创建Buffer，其中plugin_head已经由player部分创建 */
	Buffer(char *url, Plugin *plugin_head);
	/* 告知Buffer跳转播放 */
	virtual void skip(int time) = 0;
	/* 返回某一帧的信息 */
	virtual MediaFrame getMedia(int time) = 0;
	/* 供多线程运行 */
	virtual void exec() = 0;
	/* 终止exec运行 */
	virtual void exit() = 0;
	virtual ~Buffer();
};