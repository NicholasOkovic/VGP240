
#pragma once

#include "Command.h"

class CmdSetLightAmbient : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightAmbient";
	}

	const char* GetDescription() override
	{
		return
			"ambient(r,g,b)\n";

	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetLightDiffuse : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightDiffuse";
	}

	const char* GetDescription() override
	{
		return
			"AddVertex(x,y)\n"
			"AddVertex(x,y,z)\n"
			"AddVertex(x,y,r,g,b)\n"
			"AddVertex(x,y,z,r,g,b)\n"
			"\n"
			"- adds vertex to the primitives manager before render";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetLightSpecular : public Command
{
public:
	const char* GetName() override
	{
		return "SetLightSpecular";
	}

	const char* GetDescription() override
	{
		return
			"AddVertex(x,y)\n"
			"AddVertex(x,y,z)\n"
			"AddVertex(x,y,r,g,b)\n"
			"AddVertex(x,y,z,r,g,b)\n"
			"\n"
			"- adds vertex to the primitives manager before render";
	}

	bool Execute(const std::vector<std::string>& params) override;
};


class CmdAddDirectionalLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddDirectionalLight";
	}

	const char* GetDescription() override
	{
		return
			"Add dir light(x,y, z)\n"
			"AddVertex(x,y,z)\n"
			"AddVertex(x,y,r,g,b)\n"
			"AddVertex(x,y,z,r,g,b)\n"
			"\n"
			"- adds vertex to the primitives manager before render";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdAddPointLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddPointLight";
	}

	const char* GetDescription() override
	{
		return
			"Add point light(x,y, z <const> <linear> <quadratic>)\n"
			"AddVertex(x,y,z)\n"
			"AddVertex(x,y,r,g,b)\n"
			"AddVertex(x,y,z,r,g,b)\n"
			"\n"
			"- adds vertex to the primitives manager before render";
	}

	bool Execute(const std::vector<std::string>& params) override;
};


class CmdAddSpotLight : public Command
{
public:
	const char* GetName() override
	{
		return "AddSpotLight";
	}

	const char* GetDescription() override
	{
		return
			"Add spot light(x,y, z, x, y, z <const> <linear> <quadratic>)\n"
			"AddVertex(x,y,z)\n"
			"AddVertex(x,y,r,g,b)\n"
			"AddVertex(x,y,z,r,g,b)\n"
			"\n"
			"- adds vertex to the primitives manager before render";
	}

	bool Execute(const std::vector<std::string>& params) override;
};