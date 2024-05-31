#include "ModelManager.h"

ModelManager* ModelManager::Get()
{
	static ModelManager sInstance;
	return &sInstance;
}

void ModelManager::Clear()
{
	mModels.clear();
}

const Model* ModelManager::GetModel(const std::string& fileName)
{

	auto iter = std::find_if(mmodels.begin(), mmodels.end(), [fileName](auto& model)
		{
			return model->GetFileName() == fileName;
		});
	if (iter != mmodels.end())
	{
		return iter->get();
	}
	auto& model = mmodel.emplace_back(std::make_unique<Model>());
	model->load
	return nullptr;
}
