#include "MaterialManager.h"
#include "LightTypes.h"
#include "LightManager.h"


LightManager* LightManager::Get()
{
	static LightManager sInstance;
	return &sInstance;
}

void LightManager::OnNewFrame()
{
	mLights.clear();
	mAmbient = X::Colors::White;
	mDiffuse = X::Colors::White;
	mSpecular = X::Colors::White;
}

void LightManager::SetLightAmbient(const X::Color& color)
{
	mAmbient = color;
}

void LightManager::SetLightDiffuse(const X::Color& color)
{
	mDiffuse = color;
}

void LightManager::SetLightSpecular(const X::Color& color)
{
	mSpecular = color;
}

void LightManager::AddDirectionalLight(const Vector3& direction)
{
	auto light = std::make_unique<DirectionalLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);

	light->SetDirection(direction);
	mLights.emplace_back(std::move(light));


}
void LightManager::AddPointLight(const Vector3& position, float constant, float linear, float quadratic)
{
	auto light = std::make_unique<PointLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);

	light->SetPosition(position);
	light->SetAttenuation(constant, linear, quadratic);
	mLights.emplace_back(std::move(light));


}

void LightManager::AddSpotLight(const Vector3& position, const Vector3& direction, float constant, float linear, float quadratic, float angle, float decay)
{
	auto light = std::make_unique<SpotLight>();
	light->SetAmbient(mAmbient);
	light->SetDiffuse(mDiffuse);
	light->SetSpecular(mSpecular);

	light->SetDirection(direction);
	light->SetAngle(angle);
	light->SetDecay(decay);
	light->SetPosition(position);
	light->SetAttenuation(constant, linear, quadratic);
	


	mLights.emplace_back(std::move(light));
}

X::Color LightManager::ComputeLightColor(const Vector3& position, const Vector3& normal) const
{

	X::Color color = MaterialManager::Get()->GetMaterialEmissive();

	for (auto& Material : mLights)
	{
		color += Material->ComputeLightColor(position, normal);
	}
	return color;

}
