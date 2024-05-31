

#pragma once

#include "Command.h"

class CmdSetShadeMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetShadeMode";
	}

	const char* GetDescription() override
	{
		return
			"SetshadxemodeMode(<shademoed>)\n"

			"- Sets fill mode to read vertecies";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

