#include "CmdSetFillMode.h"
#include "Rasterizer.h"




bool CmdSetFillMode::Execute(const std::vector<std::string>& params)
{
	if (params.size() > 1)
	{
		return false;
	}
	FillMode fillmode = FillMode::WireFrame;
	if (params[0] == "wireframe")
	{
		fillmode = FillMode::WireFrame;
	}
	else if (params[0] == "solid")
	{
		fillmode = FillMode::Solid;
	}
	else
	{
		return false;
	}
	Rasterizer::Get()->SetFillMode(fillmode);
	return true;

}
