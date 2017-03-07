#pragma once
#include"glm.hpp"
class Camera
{
	glm::vec3 position;
	glm::vec3 viewDirection;
	glm::vec3 Right;
	glm::vec3 Up=glm::vec3(0.0f,1.0f, 0.0f);
	const float mouseStep = 0.1f;
	glm::vec2 oldMousePosition;
public:
	Camera();
	~Camera();
	void mouseUpdate(const glm::vec2&newMousePosition);
	glm::mat4 getWorldToViewMatrix() const;
	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();
	void moveDown();
	void moveUp();
	void setPosition(const glm::vec3& _pos);
	void setViewDirection(const glm::vec3& _view);
	void setUp(const glm::vec3& _Up);
	glm::vec3 getPosition();
	glm::vec3 getViewDirection();
	glm::vec3 getUp();


};

