#pragma once

#include "command.h"
#include <vector>

class CommandList {
private:
	std::vector<command> data;
public:
	void push(const Command &arg);
	Command get() const;
	void pop();
};