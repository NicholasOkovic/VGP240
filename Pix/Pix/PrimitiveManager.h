#pragma once

#include "Vertex.h"


enum class Topology
{
	Point,
	Line,
	Triangle

};
enum class CullMode
{
	None,
	Back,
	Front
};


class PrimitiveManager
{
public:
	static PrimitiveManager* Get();
	~PrimitiveManager();

	void OnNewFrame();
	void SetCullMode(CullMode mode);

	bool BeginDraw(Topology topology, bool applyTransform = false);
	void AddVertex(const Vertex& vertex);
	bool EndDraw();



private:
	PrimitiveManager();

	std::vector<Vertex> mVertexBuffer;
	Topology mtopology = Topology::Triangle;
	CullMode mCullMode = CullMode::None;
	bool mDrawBegin = false;
	bool mApplyTransform = false;

};

