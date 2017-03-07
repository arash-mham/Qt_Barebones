#pragma once
#include<glm.hpp>
using namespace std;
using namespace glm;
class Vertex
{
public:
	Vertex();
	~Vertex();
	void setPosition(vec3 pos);
	void setColor(vec3 col);
	void setNormal(vec3 nor);
	Vertex operator +(const Vertex& v);
	Vertex operator -(const Vertex& v);
	Vertex operator *(const double d);
	Vertex operator /(const double d);
private:
	vec3 position;
	vec3  color;
	vec3 normal;
	
};

