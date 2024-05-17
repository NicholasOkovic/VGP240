#pragma once

#include "Command.h"

class CmdSetCullMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetCullMode";
	}

	const char* GetDescription() override
	{
		return
			"CmdSetCullMode(cullmode)\n"
			"\n"
			"- Draws a single pixel at position (none back front).";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
