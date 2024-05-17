#pragma once

#include "Command.h"

class CmdEnableDepth: public Command
{
public:
	const char* GetName() override
	{
		return "EnableDepth";
	}

	const char* GetDescription() override
	{
		return
			"CmdEnabledDepth(bool)\n"
			"\n"
			"- shows or hids view port.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

