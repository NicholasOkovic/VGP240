#pragma once

#include "Command.h"

class CmdPopMatrix : public Command
{
public:
	const char* GetName() override
	{
		return "PopMatrix";
	}

	const char* GetDescription() override
	{
		return
			"CmdPushRotationX(deg)\n"
			"\n"
			"- push rot into mat stack (x, y).";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
