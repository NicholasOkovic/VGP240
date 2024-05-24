#pragma once

#include "Vertex.h"
#include <XEngine.h>

enum class FillMode 
{
	Solid,
	WireFrame

};

class Rasterizer
{
public:
	static Rasterizer* Get();


	void SetColor(X::Color color);
	void SetFillMode(FillMode fillMode);
	void DrawPoint(int x, int y);


	void DrawPoint(const Vertex& v);
	void DrawLine(const Vertex& v0, const Vertex& v1);
	void DrawTriangle(const Vertex& v, const Vertex& v1, const Vertex& v2);
private:
	void DrawFilledTriangle(const Vertex& v0, const Vertex& v1, const Vertex& v2);

	X::Color mColor = X::Colors::White;
	FillMode mFillMode = FillMode::Solid;

};