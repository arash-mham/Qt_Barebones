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




Vertex* Mesh::returnVertices()
{
	return vertices;
}
GLushort* Mesh::returnIndices()
{
	return indices;
}
