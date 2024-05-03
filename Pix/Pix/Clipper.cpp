#include "Clipper.h"
#include "Viewport.h"

const short BIT_INSIDE	 = 0;		
const short BIT_LEFT	 = 1 << 1;	//0001
const short BIT_RIGHT	 = 1 << 2;
const short BIT_BOTTOM	 = 1 << 3;	//0100
const short BIT_TOP		 = 1 << 4;	


enum class ClipEdge : short
{
	Left,
	Top,
	Right,
	Bottom,
	Count
};

short GetOutputCode(float x, float y)
{
	Viewport* vp = Viewport::Get();

	short code = BIT_INSIDE;
	if (x < vp->GetMinX())
	{
		code |= BIT_LEFT;
	}
	else if (x > vp->GetMaxX())
	{
		code |= BIT_RIGHT;
	}

	if (y < vp->GetMinY())
	{
		code |= BIT_TOP;
	}
	else if (y > vp->GetMaxY())
	{
		code |= BIT_BOTTOM;
	}

	return code;
}

bool IsInFront(ClipEdge edge, const Vector3& pos)
{
	switch (edge)
	{
	case ClipEdge::Left: return pos.x > Viewport::Get()->GetMinX();
		break;
	case ClipEdge::Top:return pos.y > Viewport::Get()->GetMinY();
		break;
	case ClipEdge::Right: return pos.x < Viewport::Get()->GetMaxX();
		break;
	case ClipEdge::Bottom: return pos.y < Viewport::Get()->GetMaxY();
		break;
	default:
		break;
	}
}

Vertex ComputeIntersection(ClipEdge edge, const Vertex& v, const Vertex& vp1)
{
	float t = 0.0f;
	switch (edge)
	{
	case ClipEdge::Left:
	{
		t = (Viewport::Get()->GetMinX() - v.pos.x) / (vp1.pos.x - v.pos.x);
	}
		break;
	case ClipEdge::Top:
	{
		t = (Viewport::Get()->GetMinY() - v.pos.y) / (vp1.pos.y - v.pos.y);
	}
		break;
	case ClipEdge::Right:
	{
		t = (Viewport::Get()->GetMaxX() - v.pos.x) / (vp1.pos.x - v.pos.x);
	}
		break;
	case ClipEdge::Bottom:
	{
		t = (Viewport::Get()->GetMaxY() - v.pos.y) / (vp1.pos.y - v.pos.y);
	}
		break;
	default:
		break;
	}

	return LerpVertex(v, vp1, t);
}

Clipper* Clipper::Get()
{
	static Clipper sInstance;
	return &sInstance;
}


void Clipper::OnNewFrame()
{
	mClipping = false;
}

bool Clipper::ClipPoint(const Vertex& v)
{
	if (!mClipping)
	{
		return false;
	}

	Viewport* vp = Viewport::Get();
	float maxX = vp->GetMaxX();
	float minX = vp->GetMinX();
	float maxY = vp->GetMaxY();
	float minY = vp->GetMinY();

	return v.pos.x < minX || v.pos.x > maxX
		|| v.pos.y < minY || v.pos.y > maxY;

}

bool Clipper::ClipLine(Vertex& v0, Vertex& v1)
{
	if (!mClipping)
	{
		return false;
	}

	Viewport* vp = Viewport::Get();
	float maxX = vp->GetMaxX();
	float minX = vp->GetMinX();
	float maxY = vp->GetMaxY();
	float minY = vp->GetMinY();

	short codeV0 = GetOutputCode(v0.pos.x, v0.pos.y);
	short codeV1 = GetOutputCode(v1.pos.x, v1.pos.y);

	bool cullLine = true;
	while (true)
	{
		if (!(codeV0 | codeV1))
		{
			//if both are 0000
			cullLine = false;
			break;
		}
		else if (codeV0 & codeV1)
		{
			cullLine = true; break;
		}
		float t = 0.0f;
		short outcodeOut = codeV1 > codeV0 ? codeV1 : codeV0;

		if (outcodeOut & BIT_TOP)
		{
			t = (minY - v0.pos.y) / (v1.pos.y - v0.pos.y);
		}
		else if (outcodeOut & BIT_BOTTOM)
		{
			t = (maxY - v0.pos.y) / (v1.pos.y - v0.pos.y);
		}
		else if (outcodeOut & BIT_LEFT)
		{
			t = (minX - v0.pos.x) / (v1.pos.x - v0.pos.x);
		}
		else if (outcodeOut & BIT_RIGHT)
		{
			t = (maxX - v0.pos.x) / (v1.pos.x - v0.pos.x);
		}
		if (outcodeOut == codeV0)
		{
			v0 = LerpVertex(v0, v1, t); 
			codeV0 = GetOutputCode(v0.pos.x, v0.pos.y);
		}

		else 
		{
			v1 = LerpVertex(v0, v1, t);
			codeV1 = GetOutputCode(v1.pos.x, v1.pos.y);
		}
	}


	return cullLine;
}

bool Clipper::ClipTriangle(std::vector<Vertex>& vertices)
{
	if (!mClipping)
	{
		return false;
	}


	std::vector<Vertex> newVertices;
	for (int i = 0; i < (int)ClipEdge::Count; i++)
	{
		newVertices.clear();
		ClipEdge edge = (ClipEdge)i;

		for (size_t v = 0; v < vertices.size(); v++)
		{
			size_t vp1 = (v + 1) % vertices.size();
			const Vertex& vertex = vertices[v];
			const Vertex& vertexP1 = vertices[vp1];

			const bool vIsInFront = IsInFront(edge, vertex.pos);
			const bool vp1IsInFront = IsInFront(edge, vertexP1.pos);
			//case 1 both in front
			if (vIsInFront && vp1IsInFront)
			{
				newVertices.push_back(vertexP1);
			}
			//case 2 both behind
			else if (!vIsInFront && !vp1IsInFront)
			{
				//nothing saved
			}
			//case 3 v in front, vp1 is behind
			else if (vIsInFront && !vp1IsInFront)
			{
				newVertices.push_back(ComputeIntersection(edge, vertex, vertexP1));
			}
			//case 4 v behind, vp1 in front
			else if (!vIsInFront && vp1IsInFront)
			{
				newVertices.push_back(ComputeIntersection(edge, vertex, vertexP1));
				newVertices.push_back(vertexP1);
			}
		}
		
		vertices = newVertices;
	}
	return newVertices.empty();
}
