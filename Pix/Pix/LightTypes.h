#pragma once
#include "Light.h"

class DirectionalLight : public Light	
{
public:
	virtual X::Color ComputeLightColor(const Vector3& position, const Vector3& normal) override;

	void SetDirection(const Vector3& direction);

private:
	Vector3 mDirection;
};

class PointLight : public Light	
{
public:
	virtual X::Color ComputeLightColor(const Vector3& position, const Vector3& normal) override;

	void SetPosition(const Vector3& direction);
	void SetAttenuation(float constant, float linear, float quadratic);

private:
	Vector3 mPosition;
	float mAttenConst = -1.0;
	float mAttenLinear = 0.0f;
	float mAttenQuad = 0.0f;
};
