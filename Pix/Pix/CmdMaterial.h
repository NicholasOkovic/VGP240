#pragma once
#include "Command.h"

class CmdSetMaterialAmbient : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialAmbient";
	}

	const char* GetDescription() override
	{
		return
			"ambient(r,g,b)\n";

	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialDiffuse : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialDiffuse";
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

class CmdSetMaterialSpecular : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialSpecular";
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

class CmdSetMaterialEmissive : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialEmissive";
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

class CmdSetMaterialShininess : public Command
{
public:
	const char* GetName() override
	{
		return "SetMaterialShininess";
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

