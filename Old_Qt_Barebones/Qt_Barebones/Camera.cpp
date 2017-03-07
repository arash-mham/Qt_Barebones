#include "Camera.h"
#include<gtx\transform.hpp>

Camera::Camera()
{
	viewDirection = glm::vec3(0.0f, 0.0f, -1.0f);
	Right = glm::cross(viewDirection, Up);
}


Camera::~Camera()
{
}

void Camera::mouseUpdate(const glm::vec2&newMousePosition)
{
	glm::vec2 mouseDelta = newMousePosition - oldMousePosition;
	if (glm::length(mouseDelta) > 50)
	{
		oldMousePosition = newMousePosition;
		return;
	}
	Right = glm::cross(viewDirection, Up);
	viewDirection = glm::mat3(glm::rotate(mouseDelta.x/80, Up))*viewDirection;
	viewDirection = glm::mat3(glm::rotate(mouseDelta.y / 80, Right))*viewDirection;
	oldMousePosition = newMousePosition;


}
glm::mat4 Camera::getWorldToViewMatrix() const
{
	return glm::lookAt(position, position + viewDirection, Up);
}
void Camera::moveForward()
{
	position += mouseStep*viewDirection;
}
void Camera::moveBackward()
{
	position += -mouseStep*viewDirection;

}
void Camera::moveLeft()
{
	position += mouseStep*Right;
}
void Camera::moveRight()
{
	
	position += -mouseStep*Right;
}
void Camera::moveDown()
{
	position += mouseStep*Up;

}
void Camera::moveUp()
{
	position += -mouseStep*Up;

}
void Camera::setPosition(const glm::vec3& _pos)
{
	position = _pos;
}
void Camera::setViewDirection(const glm::vec3& _viewDirection)
{
	viewDirection = _viewDirection;
	glm::vec3 newRight = glm::cross(viewDirection, Up);
	if (glm::length(newRight) == 0)
	{
		Up = glm::cross(Right, viewDirection);
		Right = glm::cross(viewDirection,Up);
	}
	else
	{
		Right = newRight;
		Up = glm::cross(Right, viewDirection);
	}
}
void Camera::setUp(const glm::vec3& _Up)
{
	Up = _Up;
	glm::vec3 newRight = glm::cross(viewDirection, Up);
	if (glm::length(newRight) == 0)
	{
		viewDirection = glm::cross(Up, Right);
		Right = glm::cross(viewDirection, Up);
	}
	else
	{
		Right = newRight;
		viewDirection = glm::cross(Up, Right);
	}
}
glm::vec3 Camera::getPosition(){ return position; }
glm::vec3 Camera::getViewDirection(){ return viewDirection; }
glm::vec3 Camera::getUp(){ return Up; }