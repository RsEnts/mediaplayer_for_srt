#pragme once

#include "../media/mediaframe.h"
#include "../command/commandlist.h"

class Plugin {
protected:
	Plugin *next;
public:
	virtual void getNewMedia(MediaFrame data, int time) = 0;
	virtual void decorateMedia(int time, MediaFrame &data) = 0;
	virtual void onPlay(int time, CommandList &cmdList) = 0;
	virtual ~Plugin() = 0;
};

class PluginCreator {
public:
	static Plugin* GetInstance(char **pluginList);
}