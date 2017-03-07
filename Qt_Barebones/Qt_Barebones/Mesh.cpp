#include "Mesh.h"
using namespace glm;
#define NUM_ARRAY_ELEMENTS(a) sizeof(a)/sizeof(*a)


glm::vec3 randomColor()
{
	glm::vec3 ret;
	ret.x = rand() / (float)RAND_MAX;
	ret.y = rand() / (float)RAND_MAX;
	ret.z = rand() / (float)RAND_MAX;
	return ret;
}
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
	stackVerts[0].setNormal(vec3(+0.0f, +1.0f, +0.0f));  // Normal
	stackVerts[1].setPosition(vec3(+1.0f, +1.0f, +1.0f));
	stackVerts[1].setColor(vec3(+0.0f, +1.0f, +0.0f));
	stackVerts[1].setNormal(vec3(+0.0f, +1.0f, +0.0f));  // Normal
	stackVerts[2].setPosition(vec3(+1.0f, +1.0f, -1.0f));
	stackVerts[2].setColor(vec3(+0.0f, +0.0f, +1.0f));
	stackVerts[2].setNormal(vec3(+0.0f, +1.0f, +0.0f));  // Normal
	stackVerts[3].setPosition(vec3(-1.0f, +1.0f, -1.0f));
	stackVerts[3].setColor(vec3(+1.0f, +1.0f, +1.0f));
	stackVerts[3].setNormal(vec3(+0.0f, +1.0f, +0.0f));  // Normal
	stackVerts[4].setPosition(vec3(-1.0f, +1.0f, -1.0f));
	stackVerts[4].setColor(vec3(+1.0f, +0.0f, +1.0f));
	stackVerts[4].setNormal(vec3(+0.0f, +0.0f, -1.0f));  // Normal
	stackVerts[5].setPosition(vec3(+1.0f, +1.0f, -1.0f));
	stackVerts[5].setColor(vec3(+0.0f, +0.5f, +0.2f));
	stackVerts[5].setNormal(vec3(+0.0f, +0.0f, -1.0f));  // Normal
	stackVerts[6].setPosition(vec3(+1.0f, -1.0f, -1.0f));
	stackVerts[6].setColor(vec3(+0.8f, +0.6f, +0.4f));
	stackVerts[6].setNormal(vec3(+0.0f, +0.0f, -1.0f));  // Normal
	stackVerts[7].setPosition(vec3(-1.0f, -1.0f, -1.0f));
	stackVerts[7].setColor(vec3(+0.3f, +1.0f, +0.5f));
	stackVerts[7].setNormal(vec3(+0.0f, +0.0f, -1.0f));  // Normal
	stackVerts[8].setPosition(vec3(+1.0f, +1.0f, -1.0f));
	stackVerts[8].setColor(vec3(+0.2f, +0.5f, +0.2f));
	stackVerts[8].setNormal(vec3(+1.0f, +0.0f, +0.0f));  // Normal
	stackVerts[9].setPosition(vec3(+1.0f, +1.0f, +1.0f));
	stackVerts[9].setColor(vec3(+0.9f, +0.3f, +0.7f));
	stackVerts[9].setNormal(vec3(+1.0f, +0.0f, +0.0f));  // Normal
	stackVerts[10].setPosition(vec3(+1.0f, -1.0f, +1.0f));
	stackVerts[10].setColor(vec3(+0.3f, +0.7f, +0.5f));
	stackVerts[10].setNormal(vec3(+1.0f, +0.0f, +0.0f));  // Normal
	stackVerts[11].setPosition(vec3(+1.0f, -1.0f, -1.0f));
	stackVerts[11].setColor(vec3(+0.5f, +0.7f, +0.5f));
	stackVerts[11].setNormal(vec3(+1.0f, +0.0f, +0.0f));  // Normal
	stackVerts[12].setPosition(vec3(-1.0f, +1.0f, +1.0f));
	stackVerts[12].setColor(vec3(+0.7f, +0.8f, +0.2f));
	stackVerts[12].setNormal(vec3(-1.0f, +0.0f, +0.0f));  // Normal
	stackVerts[13].setPosition(vec3(-1.0f, +1.0f, -1.0f));
	stackVerts[13].setColor(vec3(+0.5f, +0.7f, +0.3f));
	stackVerts[13].setNormal(vec3(-1.0f, +0.0f, +0.0f));  // Normal
	stackVerts[14].setPosition(vec3(-1.0f, -1.0f, -1.0f));
	stackVerts[14].setColor(vec3(+0.4f, +0.7f, +0.7f));
	stackVerts[14].setNormal(vec3(-1.0f, +0.0f, +0.0f)); // Normal
	stackVerts[15].setPosition(vec3(-1.0f, -1.0f, +1.0f));
	stackVerts[15].setColor(vec3(+0.2f, +0.5f, +1.0f));
	stackVerts[15].setNormal(vec3(-1.0f, +0.0f, +0.0f));  // Normal
	stackVerts[16].setPosition(vec3(+1.0f, +1.0f, +1.0f));
	stackVerts[16].setColor(vec3(+0.6f, +1.0f, +0.7f));
	stackVerts[16].setNormal(vec3(+0.0f, +0.0f, +1.0f));  // Normal
	stackVerts[17].setPosition(vec3(-1.0f, +1.0f, +1.0f));
	stackVerts[17].setColor(vec3(+0.6f, +0.4f, +0.8f));
	stackVerts[17].setNormal(vec3(+0.0f, +0.0f, +1.0f));// Normal
	stackVerts[18].setPosition(vec3(-1.0f, -1.0f, +1.0f));
	stackVerts[18].setColor(vec3(+0.2f, +0.8f, +0.7f));
	stackVerts[18].setNormal(vec3(+0.0f, +0.0f, +1.0f)); // Normal
	stackVerts[19].setPosition(vec3(+1.0f, -1.0f, +1.0f));
	stackVerts[19].setColor(vec3(+0.2f, +0.7f, +1.0f));
	stackVerts[19].setNormal(vec3(+0.0f, +0.0f, +1.0f));  // Normal
	stackVerts[20].setPosition(vec3(+1.0f, -1.0f, -1.0f));
	stackVerts[20].setColor(vec3(+0.8f, +0.3f, +0.7f));
	stackVerts[20].setNormal(vec3(+0.0f, -1.0f, +0.0f));  // Normal
	stackVerts[21].setPosition(vec3(-1.0f, -1.0f, -1.0f));
	stackVerts[21].setColor(vec3(+0.8f, +0.9f, +0.5f));
	stackVerts[21].setNormal(vec3(+0.0f, -1.0f, +0.0f)); // Normal
	stackVerts[22].setPosition(vec3(-1.0f, -1.0f, +1.0f));
	stackVerts[22].setColor(vec3(+0.5f, +0.8f, +0.5f));
	stackVerts[22].setNormal(vec3(+0.0f, -1.0f, +0.0f)); // Normal
	stackVerts[23].setPosition(vec3(+1.0f, -1.0f, +1.0f));
	stackVerts[23].setColor(vec3(+0.9f, +1.0f, +0.2f));
	stackVerts[23].setNormal(vec3(+0.0f, -1.0f, +0.0f)); // Normal
	

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
Mesh Mesh::makeArrow()
{
	Mesh ret;
	Vertex stackVerts[40];
	stackVerts[0].setPosition(vec3(-1.0f, +1.0f, +1.0f));
	stackVerts[0].setColor(vec3(+1.0f, +0.0f, +0.0f));
	// Top side of arrow head
	stackVerts[0].setPosition(vec3(+0.00f, +0.25f, -0.25f));     // 0
	stackVerts[0].setColor(vec3(+1.00f, +0.00f, +0.00f));		  // Color
	//	vec3(+0.00f, +1.00f, +0.00f),         // Normal
	stackVerts[1].setPosition(vec3(+0.50f, +0.25f, -0.25f));         // 1
	stackVerts[1].setColor(vec3(+1.00f, +0.00f, +0.00f));		  // Color
	//	vec3(+0.00f, +1.00f, +0.00f),         // Normal
	stackVerts[2].setPosition(vec3(+0.00f, +0.25f, -1.00f));         // 2
	stackVerts[2].setColor(vec3(+1.00f, +0.00f, +0.00f));		  // Color
	//vec3(+0.00f, +1.00f, +0.00f),         // Normal
	stackVerts[3].setPosition(vec3(-0.50f, +0.25f, -0.25f));    // 3
	stackVerts[3].setColor(vec3(+1.00f, +0.00f, +0.00f));		  // Color
	//		vec3(+0.00f, +1.00f, +0.00f),         // Normal
	// Bottom side of arrow head
	stackVerts[4].setPosition(vec3(+0.00f, -0.25f, -0.25f));       // 4
	stackVerts[4].setColor(vec3(+0.00f, +0.00f, +1.00f));		  // Color
	//	vec3(+0.00f, -1.00f, +0.00f),         // Normal
	stackVerts[5].setPosition(vec3(+0.50f, -0.25f, -0.25f));         // 5
	stackVerts[5].setColor(vec3(+0.00f, +0.00f, +1.00f));		  // Color
	//vec3(+0.00f, -1.00f, +0.00f),         // Normal
	stackVerts[6].setPosition(vec3(+0.00f, -0.25f, -1.00f));         // 6
	stackVerts[6].setColor(vec3(+0.00f, +0.00f, +1.00f));		  // Color
	//vec3(+0.00f, -1.00f, +0.00f),         // Normal
	stackVerts[7].setPosition(vec3(-0.50f, -0.25f, -0.25f));         // 7
	stackVerts[7].setColor(vec3(+0.00f, +0.00f, +1.00f));	  // Color
	//vec3(+0.00f, -1.00f, +0.00f),         // Normal
	// Right side of arrow tip
	stackVerts[8].setPosition(vec3(+0.50f, +0.25f, -0.25f));         // 8
	stackVerts[8].setColor(vec3(+0.60f, +1.00f, +0.00f));		  // Color
	//vec3(0.83205032f, 0.00f, -0.55470026f), // Normal
	stackVerts[9].setPosition(vec3(+0.00f, +0.25f, -1.00f));    // 9
	stackVerts[9].setColor(vec3(+0.60f, +1.00f, +0.00f));		  // Color
	//vec3(0.83205032f, 0.00f, -0.55470026f), // Normal
	stackVerts[10].setPosition(vec3(+0.00f, -0.25f, -1.00f));         // 10
	stackVerts[10].setColor(vec3(+0.60f, +1.00f, +0.00f));		  // Color
	//vec3(0.83205032f, 0.00f, -0.55470026f), // Normal
	stackVerts[11].setPosition(vec3(+0.50f, -0.25f, -0.25f));       // 11
	stackVerts[11].setColor(vec3(+0.60f, +1.00f, +0.00f));	  // Color
	//vec3(0.83205032f, 0.00f, -0.55470026f), // Normal
	// Left side of arrow tip
	stackVerts[12].setPosition(vec3(+0.00f, +0.25f, -1.00f));       // 12
	stackVerts[12].setColor(vec3(+0.00f, +1.00f, +0.00f));		  // Color
	//vec3(-0.55708605f, 0.00f, -0.37139067f), // Normal
	stackVerts[13].setPosition(vec3(-0.50f, +0.25f, -0.25f));       // 13
	stackVerts[13].setColor(vec3(+0.00f, +1.00f, +0.00f));		  // Color
	//vec3(-0.55708605f, 0.00f, -0.37139067f), // Normal
	stackVerts[14].setPosition(vec3(+0.00f, -0.25f, -1.00f));      // 14
	stackVerts[14].setColor(vec3(+0.00f, +1.00f, +0.00f));		  // Color
	//vec3(-0.55708605f, 0.00f, -0.37139067f), // Normal
	stackVerts[15].setPosition(vec3(-0.50f, -0.25f, -0.25f));        // 15
	stackVerts[15].setColor(vec3(+0.00f, +1.00f, +0.00f));  // Color
	//vec3(-0.55708605f, 0.00f, -0.37139067f), // Normal
	// Back side of arrow tip
	stackVerts[16].setPosition(vec3(-0.50f, +0.25f, -0.25f));         // 16
	stackVerts[16].setColor(vec3(+0.50f, +0.50f, +0.50f));	  // Color
	//vec3(+0.00f, +0.00f, +1.00f),         // Normal
	stackVerts[17].setPosition(vec3(+0.50f, +0.25f, -0.25f));        // 17
	stackVerts[17].setColor(vec3(+0.50f, +0.50f, +0.50f));		  // Color
	//vec3(+0.00f, +0.00f, +1.00f),         // Normal
	stackVerts[18].setPosition(vec3(-0.50f, -0.25f, -0.25f));      // 18
	stackVerts[18].setColor(vec3(+0.50f, +0.50f, +0.50f));	  // Color
	//vec3(+0.00f, +0.00f, +1.00f),         // Normal
	stackVerts[19].setPosition(vec3(+0.50f, -0.25f, -0.25f));         // 19
	stackVerts[19].setColor(vec3(+0.50f, +0.50f, +0.50f));  // Color
	//vec3(+0.00f, +0.00f, +1.00f),         // Normal
	// Top side of back of arrow
	stackVerts[20].setPosition(vec3(+0.25f, +0.25f, -0.25f));       // 20
	stackVerts[20].setColor(vec3(+1.00f, +0.00f, +0.00f));		  // Color
	//vec3(+0.00f, +1.00f, +0.00f),         // Normal
	stackVerts[21].setPosition(vec3(+0.25f, +0.25f, +1.00f));      // 21
	stackVerts[21].setColor(vec3(+1.00f, +0.00f, +0.00f));		  // Color
	//vec3(+0.00f, +1.00f, +0.00f),         // Normal
	stackVerts[22].setPosition(vec3(-0.25f, +0.25f, +1.00f));         // 22
	stackVerts[22].setColor(vec3(+1.00f, +0.00f, +0.00f));	  // Color
	//vec3(+0.00f, +1.00f, +0.00f),         // Normal
	stackVerts[23].setPosition(vec3(-0.25f, +0.25f, -0.25f));        // 23
	stackVerts[23].setColor(vec3(+1.00f, +0.00f, +0.00f));		  // Color
	//vec3(+0.00f, +1.00f, +0.00f),         // Normal
	// Bottom side of back of arrow
	stackVerts[24].setPosition(vec3(+0.25f, -0.25f, -0.25f));         // 24
	stackVerts[24].setColor(vec3(+0.00f, +0.00f, +1.00f));	  // Color
	//vec3(+0.00f, -1.00f, +0.00f),         // Normal
	stackVerts[25].setPosition(vec3(+0.25f, -0.25f, +1.00f));       // 25
	stackVerts[25].setColor(vec3(+0.00f, +0.00f, +1.00f));	  // Color
	//vec3(+0.00f, -1.00f, +0.00f),         // Normal
	stackVerts[26].setPosition(vec3(-0.25f, -0.25f, +1.00f));         // 26
	stackVerts[26].setColor(vec3(+0.00f, +0.00f, +1.00f));		  // Color
	//vec3(+0.00f, -1.00f, +0.00f),         // Normal
	stackVerts[27].setPosition(vec3(-0.25f, -0.25f, -0.25f));        // 27
	stackVerts[27].setColor(vec3(+0.00f, +0.00f, +1.00f));		  // Color
	//vec3(+0.00f, -1.00f, +0.00f),         // Normal
	// Right side of back of arrow
	stackVerts[28].setPosition(vec3(+0.25f, +0.25f, -0.25f));         // 28
	stackVerts[28].setColor(vec3(+0.60f, +1.00f, +0.00f));	  // Color
	//vec3(+1.00f, +0.00f, +0.00f),         // Normal
	stackVerts[29].setPosition(vec3(+0.25f, -0.25f, -0.25f));      // 29
	stackVerts[29].setColor(vec3(+0.60f, +1.00f, +0.00f));		  // Color
	//vec3(+1.00f, +0.00f, +0.00f),         // Normal
	stackVerts[30].setPosition(vec3(+0.25f, -0.25f, +1.00f));         // 30
	stackVerts[30].setColor(vec3(+0.60f, +1.00f, +0.00f));	  // Color
	//vec3(+1.00f, +0.00f, +0.00f),         // Normal
	stackVerts[31].setPosition(vec3(+0.25f, +0.25f, +1.00f));      // 31
	stackVerts[31].setColor(vec3(+0.60f, +1.00f, +0.00f));	  // Color
	//vec3(+1.00f, +0.00f, +0.00f),         // Normal
	// Left side of back of arrow
	stackVerts[32].setPosition(vec3(-0.25f, +0.25f, -0.25f));        // 32
	stackVerts[32].setColor(vec3(+0.00f, +1.00f, +0.00f));		  // Color
	//vec3(-1.00f, +0.00f, +0.00f),         // Normal
	stackVerts[33].setPosition(vec3(-0.25f, -0.25f, -0.25f));     // 33
	stackVerts[33].setColor(vec3(+0.00f, +1.00f, +0.00f));		  // Color
	//vec3(-1.00f, +0.00f, +0.00f),         // Normal
	stackVerts[34].setPosition(vec3(-0.25f, -0.25f, +1.00f));      // 34
	stackVerts[34].setColor(vec3(+0.00f, +1.00f, +0.00f));	  // Color
	//vec3(-1.00f, +0.00f, +0.00f),         // Normal
	stackVerts[35].setPosition(vec3(-0.25f, +0.25f, +1.00f));    // 35
	stackVerts[35].setColor(vec3(+0.00f, +1.00f, +0.00f));		  // Color
	//vec3(-1.00f, +0.00f, +0.00f),         // Normal
	// Back side of back of arrow
	stackVerts[36].setPosition(vec3(-0.25f, +0.25f, +1.00f));       // 36
	stackVerts[36].setColor(vec3(+0.50f, +0.50f, +0.50f));	  // Color
	//vec3(+0.00f, +0.00f, +1.00f),         // Normal
	stackVerts[37].setPosition(vec3(+0.25f, +0.25f, +1.00f));        // 37
	stackVerts[37].setColor(vec3(+0.50f, +0.50f, +0.50f));		  // Color
	//vec3(+0.00f, +0.00f, +1.00f),         // Normal
	stackVerts[38].setPosition(vec3(-0.25f, -0.25f, +1.00f));        // 38
	stackVerts[38].setColor(vec3(+0.50f, +0.50f, +0.50f));		  // Color
	//vec3(+0.00f, +0.00f, +1.00f),         // Normal
	stackVerts[39].setPosition(vec3(+0.25f, -0.25f, +1.00f));         // 39
	stackVerts[39].setColor(vec3(+0.50f, +0.50f, +0.50f));	  // Color
	//vec3(+0.00f, +0.00f, +1.00f),         // Normal
	GLushort stackIndices[] = {
		0, 1, 2, // Top
		0, 2, 3,
		4, 6, 5, // Bottom
		4, 7, 6,
		8, 10, 9, // Right side of arrow tip
		8, 11, 10,
		12, 15, 13, // Left side of arrow tip
		12, 14, 15,
		16, 19, 17, // Back side of arrow tip
		16, 18, 19,
		20, 22, 21, // Top side of back of arrow
		20, 23, 22,
		24, 25, 26, // Bottom side of back of arrow
		24, 26, 27,
		28, 30, 29, // Right side of back of arrow
		28, 31, 30,
		32, 33, 34, // Left side of back of arrow
		32, 34, 35,
		36, 39, 37, // Back side of back of arrow
		36, 38, 39,
	};
	ret.numVertices = NUM_ARRAY_ELEMENTS(stackVerts);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, stackVerts, sizeof(stackVerts));


	ret.numIndices = NUM_ARRAY_ELEMENTS(stackIndices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, stackIndices, sizeof(stackIndices));

	return ret;
}
void Mesh::deleteMemory()
{
	delete[] vertices;
	delete[] indices;
	numVertices = numIndices = 0;

}



Vertex* Mesh::returnVertices()
{
	return vertices;
}
GLushort* Mesh::returnIndices()
{
	return indices;
}
Mesh Mesh::makePlaneVerts(uint dimensions)
{
	Mesh ret;
	ret.numVertices = dimensions * dimensions;
	int half = dimensions / 2;
	ret.vertices = new Vertex[ret.numVertices];
	for (int i = 0; i < dimensions; i++)
	{
		for (int j = 0; j < dimensions; j++)
		{
			Vertex& thisVert = ret.vertices[i * dimensions + j];
			thisVert.setPosition(vec3(j - half, 0, i - half));
			thisVert.setColor(randomColor());
			thisVert.setNormal(vec3(0,1,0));
		}
	}
	return ret;
}

Mesh Mesh::makePlaneIndices(uint dimensions)
{
	Mesh ret;
	ret.numIndices = (dimensions - 1) * (dimensions - 1) * 2 * 3; // 2 triangles per square, 3 indices per triangle
	ret.indices = new unsigned short[ret.numIndices];
	int runner = 0;
	for (int row = 0; row < dimensions - 1; row++)
	{
		for (int col = 0; col < dimensions - 1; col++)
		{
			ret.indices[runner++] = dimensions * row + col;
			ret.indices[runner++] = dimensions * row + col + dimensions;
			ret.indices[runner++] = dimensions * row + col + dimensions + 1;

			ret.indices[runner++] = dimensions * row + col;
			ret.indices[runner++] = dimensions * row + col + dimensions + 1;
			ret.indices[runner++] = dimensions * row + col + 1;
		}
	}
	assert(runner = ret.numIndices);
	return ret;
}

Mesh Mesh::makePlaneUnseamedIndices(uint tesselation)
{
	Mesh ret;
	uint dimensions = tesselation * tesselation;
	ret.numIndices = dimensions * 2 * 3; // 2 triangles per square, 3 indices per triangle
	ret.indices = new unsigned short[ret.numIndices];
	int runner = 0;
	for (int row = 0; row < tesselation; row++)
	{
		// This code is crap but works, and I'm not in the mood right now to clean it up
		for (int col = 0; col < tesselation; col++)
		{
			// Bottom left triangle
			ret.indices[runner++] = tesselation * row + col;
			// One row down unless it's the bottom row, 
			ret.indices[runner++] = (row + 1 == tesselation ? 0 : tesselation * row + tesselation) + col;
			// Move to vert right of this one unless it's the last vert,
			// which we connect to the first vert in the row
			// the % dimensions at the end accounts for the last row hooking to the first row
			ret.indices[runner++] = (tesselation * row + col + tesselation + (col + 1 == tesselation ? -tesselation + 1 : 1)) % dimensions;

			// Upper right triangle
			ret.indices[runner++] = tesselation * row + col;
			if (col + 1 == tesselation && row + 1 == tesselation)
			{
				// Very last vert
				ret.indices[runner++] = 0;
			}
			else if (col + 1 == tesselation)
			{
				// Last vert on this row
				// Check if we need to connect it to zeroeth row or the next row
				if (row + 1 == tesselation)
				{
					// Tie to zeroeth row
					ret.indices[runner++] = col + 1;
				}
				else
				{
					// Tie to next row
					ret.indices[runner++] = tesselation * row + col + 1;
				}
			}
			else
			{
				// Regular interior vert
				// the % dimensions at the end accounts for the last row hooking to the first row
				ret.indices[runner++] = (tesselation * row + col + tesselation + 1) % dimensions;
			}
			ret.indices[runner++] = tesselation * row + col + (col + 1 == tesselation ? -col : 1);
		}
	}
	return ret;
}

Mesh Mesh::makePlane(uint dimensions)
{
	Mesh ret = makePlaneVerts(dimensions);
	Mesh ret2 = makePlaneIndices(dimensions);
	ret.numIndices = ret2.numIndices;
	ret.indices = ret2.indices;
	return ret;
}
