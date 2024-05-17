#include "CmdSetCullMode.h"

#include "PrimitiveManager.h"
#include "Camera.h"

bool CmdSetCullMode::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
		return false;

	CullMode cullmode = CullMode::None;

	if (params[0] == "none")
	{
		cullmode = CullMode::None;
	}
	if (params[0] == "back")
	{
		cullmode = CullMode::Back;
	}
	if (params[0] == "front")
	{
		cullmode = CullMode::Front;
	}
	else
	{
		return false;
	}

	PrimitiveManager::Get()->SetCullMode(cullmode);

	return true;
}