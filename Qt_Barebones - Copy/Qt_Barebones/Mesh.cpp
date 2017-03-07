#include "Mesh.h"
using namespace glm;
#define NUM_ARRAY_ELEMENTS(a) sizeof(a)/sizeof(*a)

Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}
Mesh Mesh::makeTriange()
{
	Mesh tri;
	Vertex myTri[3];
	myTri[0].setPosition(vec3(0, 1, 0));
	myTri[0].setColor(vec3(1, 0, 0));
	myTri[1].setPosition(vec3(-1, -1, 0));
	myTri[1].setColor(vec3(0, 1, 0));
	myTri[2].setPosition(vec3(1, -1, 0));
	myTri[2].setColor(vec3(0, 0, 1)); 
	tri.numVertices = NUM_ARRAY_ELEMENTS(myTri);
	tri.vertices = new Vertex[tri.numVertices];
	memcpy(tri.vertices, myTri, sizeof(myTri));

	GLushort indices[] = { 0, 1, 2 };
	tri.numIndices = NUM_ARRAY_ELEMENTS(indices);
	tri.indices = new GLushort[tri.numIndices];
	memcpy(tri.indices, indices, sizeof(indices));
	return tri;
	
}
Mesh Mesh::makeCube() {
	Mesh ret;

	Vertex stackVerts[24];
	stackVerts[0].setPosition(vec3(-1.0f, +1.0f, +1.0f));
	stackVerts[0].setColor(vec3(+1.0f, +0.0f, +0.0f));
//	vec3(+0.0f, +1.0f, +0.0f),  // Normal
	stackVerts[1].setPosition(vec3(+1.0f, +1.0f, +1.0f));
	stackVerts[1].setColor(vec3(+0.0f, +1.0f, +0.0f));
	//vec3(+0.0f, +1.0f, +0.0f),  // Normal
	stackVerts[2].setPosition(vec3(+1.0f, +1.0f, -1.0f));
	stackVerts[2].setColor(vec3(+0.0f, +0.0f, +1.0f));
//		vec3(+0.0f, +1.0f, +0.0f),  // Normal
	stackVerts[3].setPosition(vec3(-1.0f, +1.0f, -1.0f));
	stackVerts[3].setColor(vec3(+1.0f, +1.0f, +1.0f));
//		vec3(+0.0f, +1.0f, +0.0f),  // Normal
	stackVerts[4].setPosition(vec3(-1.0f, +1.0f, -1.0f));
	stackVerts[4].setColor(vec3(+1.0f, +0.0f, +1.0f));
//		vec3(+0.0f, +0.0f, -1.0f),  // Normal
	stackVerts[5].setPosition(vec3(+1.0f, +1.0f, -1.0f));
	stackVerts[5].setColor(vec3(+0.0f, +0.5f, +0.2f));
//		vec3(+0.0f, +0.0f, -1.0f),  // Normal
	stackVerts[6].setPosition(vec3(+1.0f, -1.0f, -1.0f));
	stackVerts[6].setColor(vec3(+0.8f, +0.6f, +0.4f));
//		vec3(+0.0f, +0.0f, -1.0f),  // Normal
	stackVerts[7].setPosition(vec3(-1.0f, -1.0f, -1.0f));
	stackVerts[7].setColor(vec3(+0.3f, +1.0f, +0.5f));
//		vec3(+0.0f, +0.0f, -1.0f),  // Normal
	stackVerts[8].setPosition(vec3(+1.0f, +1.0f, -1.0f));
	stackVerts[8].setColor(vec3(+0.2f, +0.5f, +0.2f));
//		vec3(+1.0f, +0.0f, +0.0f),  // Normal
	stackVerts[9].setPosition(vec3(+1.0f, +1.0f, +1.0f));
	stackVerts[9].setColor(vec3(+0.9f, +0.3f, +0.7f));
//		vec3(+1.0f, +0.0f, +0.0f),  // Normal
	stackVerts[10].setPosition(vec3(+1.0f, -1.0f, +1.0f));
	stackVerts[10].setColor(vec3(+0.3f, +0.7f, +0.5f));
//		vec3(+1.0f, +0.0f, +0.0f),  // Normal
	stackVerts[11].setPosition(vec3(+1.0f, -1.0f, -1.0f));
	stackVerts[11].setColor(vec3(+0.5f, +0.7f, +0.5f));
//		vec3(+1.0f, +0.0f, +0.0f),  // Normal
	stackVerts[12].setPosition(vec3(-1.0f, +1.0f, +1.0f));
	stackVerts[12].setColor(vec3(+0.7f, +0.8f, +0.2f));
//		vec3(-1.0f, +0.0f, +0.0f),  // Normal
	stackVerts[13].setPosition(vec3(-1.0f, +1.0f, -1.0f));
	stackVerts[13].setColor(vec3(+0.5f, +0.7f, +0.3f));
//		vec3(-1.0f, +0.0f, +0.0f),  // Normal
	stackVerts[14].setPosition(vec3(-1.0f, -1.0f, -1.0f));
	stackVerts[14].setColor(vec3(+0.4f, +0.7f, +0.7f));
//		vec3(-1.0f, +0.0f, +0.0f),  // Normal
	stackVerts[15].setPosition(vec3(-1.0f, -1.0f, +1.0f));
	stackVerts[15].setColor(vec3(+0.2f, +0.5f, +1.0f));
//		vec3(-1.0f, +0.0f, +0.0f),  // Normal
	stackVerts[16].setPosition(vec3(+1.0f, +1.0f, +1.0f));
	stackVerts[16].setColor(vec3(+0.6f, +1.0f, +0.7f));
//		vec3(+0.0f, +0.0f, +1.0f),  // Normal
	stackVerts[17].setPosition(vec3(-1.0f, +1.0f, +1.0f));
	stackVerts[17].setColor(vec3(+0.6f, +0.4f, +0.8f));
//		vec3(+0.0f, +0.0f, +1.0f),  // Normal
	stackVerts[18].setPosition(vec3(-1.0f, -1.0f, +1.0f));
	stackVerts[18].setColor(vec3(+0.2f, +0.8f, +0.7f));
//		vec3(+0.0f, +0.0f, +1.0f),  // Normal
	stackVerts[19].setPosition(vec3(+1.0f, -1.0f, +1.0f));
	stackVerts[19].setColor(vec3(+0.2f, +0.7f, +1.0f));
//		vec3(+0.0f, +0.0f, +1.0f),  // Normal
	stackVerts[20].setPosition(vec3(+1.0f, -1.0f, -1.0f));
	stackVerts[20].setColor(vec3(+0.8f, +0.3f, +0.7f));
//		vec3(+0.0f, -1.0f, +0.0f),  // Normal
	stackVerts[21].setPosition(vec3(-1.0f, -1.0f, -1.0f));
	stackVerts[21].setColor(vec3(+0.8f, +0.9f, +0.5f));
//		vec3(+0.0f, -1.0f, +0.0f),  // Normal
	stackVerts[22].setPosition(vec3(-1.0f, -1.0f, +1.0f));
	stackVerts[22].setColor(vec3(+0.5f, +0.8f, +0.5f));
//		vec3(+0.0f, -1.0f, +0.0f),  // Normal
	stackVerts[23].setPosition(vec3(+1.0f, -1.0f, +1.0f));
	stackVerts[23].setColor(vec3(+0.9f, +1.0f, +0.2f));
//		vec3(+0.0f, -1.0f, +0.0f),  // Normal
	

	ret.numVertices = NUM_ARRAY_ELEMENTS(stackVerts);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, stackVerts, sizeof(stackVerts));

	unsigned short stackIndices[] = {
		0, 1, 2, 0, 2, 3, // Top
		4, 5, 6, 4, 6, 7, // Front
		8, 9, 10, 8, 10, 11, // Right
		12, 13, 14, 12, 14, 15, // Left
		16, 17, 18, 16, 18, 19, // Back
		20, 22, 21, 20, 23, 22, // Bottom
	};
	ret.numIndices = NUM_ARRAY_ELEMENTS(stackIndices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, stackIndices, sizeof(stackIndices));

	return ret;
}





Vertex* Mesh::returnVertices()
{
	return vertices;
}
GLushort* Mesh::returnIndices()
{
	return indices;
}
