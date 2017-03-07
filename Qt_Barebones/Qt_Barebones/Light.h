#pragma once
#include<glm.hpp>
using namespace std;
using namespace glm;

class Light
{
private:
	vec3 position;
	vec3 ambient;

public:
	Light();
	~Light();
	void setPosition(vec3 pos){ position = pos; }
	vec3 getPosition(){ return position; }
	void setAmbient(vec3 amb){ ambient = amb; }
	vec3 getAmbient(){ return ambient; }
};

