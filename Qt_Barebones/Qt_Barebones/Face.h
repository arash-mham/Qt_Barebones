#pragma once
#include"Vertex.h"
#include<vector>
using namespace std;
class Face
{
public:
	Face();
	~Face();
	void addVertex(Vertex v);
	Vertex returnVertex(int i);
private:
	vector<Vertex> vertices;
	
	
};

