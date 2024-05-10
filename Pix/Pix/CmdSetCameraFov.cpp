#include "CmdSetCameraFov.h"
#include "VariableCache.h"
#include "Camera.h"

bool CmdSetCameraFov::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
		return false;

	auto vc = VariableCache::Get();
	float fov = vc->GetFloat(params[0]) * 3.1459 / 180.0f;
	Camera::Get()->SetFOV(fov);

	return true;
}