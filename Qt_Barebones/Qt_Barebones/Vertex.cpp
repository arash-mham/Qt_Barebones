#include "Vertex.h"


Vertex::Vertex()
{
	normal = vec3(1, 0, 0);
}


Vertex::~Vertex()
{

}
void Vertex::setPosition(vec3 pos)
{
	position = pos;
}
void Vertex::setColor(vec3 col)
{
	color = col;
}
void Vertex::setNormal(vec3 nor)
{
	normal = nor;
}
Vertex Vertex::operator +(const Vertex& v)
{
	Vertex v_;
	v_.position = this->position + v.position;
	v_.color = vec3((this->color.r + v.color.r)/2.0, (this->color.g + v.color.g)/2.0, (this->color.b + v.color.b)/2.0);
	return v_;
}
Vertex Vertex::operator -(const Vertex& v)
{
	Vertex v_;
	v_.position = this->position - v.position;
	v_.color = vec3(0,0,0);
	return v_;
}
Vertex Vertex::operator *(const double d)
{
	Vertex v_;
	v_.position = vec3(this->position.x*d, this->position.y*d, this->position.z*d);
	return v_;
}
Vertex Vertex::operator /(const double d)
{
	Vertex v_;
	v_.position = vec3(this->position.x/d, this->position.y/d, this->position.z/d);
	return v_;
}