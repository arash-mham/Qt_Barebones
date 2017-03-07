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
	Mesh makeTriange();
	Mesh makeCube();
	Vertex* returnVertices();
	GLushort* returnIndices();
	
private:
	Vertex* vertices=0;
	GLuint numVertices=0;
	GLushort* indices=0;
	GLuint numIndices=0;
	
};

