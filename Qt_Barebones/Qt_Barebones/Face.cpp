#include "Face.h"


Face::Face()
{
}


Face::~Face()
{
}
void Face::addVertex(Vertex v)
{
	vertices.push_back(v);
}
Vertex Face::returnVertex(int i)
{
	if (i > -1 && i < vertices.size())
	{
		return vertices[i];
	}
}