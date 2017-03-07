#pragma once
#include<GL\glew.h>
#include"Vertex.h"
#include<glm.hpp>
class Mesh
{
public:
	Mesh();
	~Mesh();
	GLsizeiptr vertexBufferSize() const
	{
		return numVertices*sizeof(Vertex);

	}
	GLsizeiptr indexBufferSize() const
	{
		return numIndices*sizeof(GLuint);
	}
	GLuint get_numIndices()
	{
		return numIndices;
	}
	GLsizeiptr getOffsetColor()
	{
		//3 Floats before color for position
		return sizeof(float) * 3;
	}
	GLsizeiptr getOffsetNormal()
	{
		//3 Floats before Normal for position
		//3 Float for Color
		return sizeof(float) * 6;
	}
	GLsizeiptr getStride()
	{
		//How much jump is needed
		//3 for position
		//3 for color
		//3 for normal
		return sizeof(float) * 9;
	}
	Mesh makeTriange();
	Mesh makeCube();
	Vertex* returnVertices();
	GLushort* returnIndices();
	Mesh makeArrow();
	void deleteMemory();
	Mesh makePlane(GLuint dimensions=10);
	Mesh makePlaneUnseamedIndices(GLuint tesselation);
	Mesh makePlaneIndices(GLuint dimensions);
	Mesh makePlaneVerts(GLuint dimensions);
	
private:
	Vertex* vertices=0;
	GLuint numVertices=0;
	GLushort* indices=0;
	GLuint numIndices=0;
	
};

