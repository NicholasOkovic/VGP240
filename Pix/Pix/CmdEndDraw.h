#pragma once

#include "Command.h"

class CmdEndDraw : public Command
{
public:
	const char* GetName() override
	{
		return "EndDraw";
	}

	const char* GetDescription() override
	{
		return
			
			"End draw()\n"
			"\n"
			"- send verts to rasterizer to render";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

