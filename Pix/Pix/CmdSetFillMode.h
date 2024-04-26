
#pragma once

#include "Command.h"

class CmdSetFillMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetFillMode";
	}

	const char* GetDescription() override
	{
		return
			"SetFillMode(<fillMode>)\n"
			
			"- Sets fill mode to read vertecies";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

