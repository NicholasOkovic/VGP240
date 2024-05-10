#pragma once

#include "Command.h"

class CmdPushRotationY : public Command
{
public:
	const char* GetName() override
	{
		return "PushRotationY";
	}

	const char* GetDescription() override
	{
		return
			"CmdPushRotationZ(deg)\n"
			"\n"
			"- push rot into mat stack (x, y).";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
