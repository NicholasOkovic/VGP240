#include "CmdPopMatrix.h"

#include "VariableCache.h"
#include "MatrixStack.h"

bool CmdPopMatrix::Execute(const std::vector<std::string>& params)	//////
{
	MatrixStack::Get()->PopMatrix();
	return true;
}