#include<gl\glew.h>
#include "GLWindow.h"
#include <iostream>
#include<fstream>
#include<glm.hpp>
#include"Vertex.h"
#include "Mesh.h"
#include"gtc\matrix_transform.hpp"
#include"gtx\transform.hpp"
#include"Light.h"
const GLuint NUM_VERTICES_PER_TRI = 3;
const GLuint NUM_FLOATS_PER_VERTICE = 6;
const GLuint VERTEX_BYTE_SIZE = NUM_FLOATS_PER_VERTICE * sizeof(float);
GLuint programID;
GLuint mvpUniformLocation;
GLint modeltoWorldTransformation;
GLuint BufferID;
vector<Mesh> mesh_list;
vector<GLuint>VertexArrayObjectID;
vector<GLuint>IndexBufferDataByteOffset;
Light L;
GLWindow::GLWindow()
{
}


GLWindow::~GLWindow()
{
	glDeleteBuffers(1, &BufferID);
	glUseProgram(0);
	glDeleteProgram(programID);

}
bool GLWindow::checkShaderCompileStatus(GLuint shader)
{
	GLint isCompiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		GLchar* errorLog = new GLchar[maxLength];
		glGetShaderInfoLog(shader, maxLength, &maxLength, errorLog);
		cout<< errorLog<<endl;

		// Provide the infolog in whatever manor you deem best.
		// Exit with failut a re.
		glDeleteShader(shader); // Don't leak the shader.
		delete errorLog;
		return false;
	}
	return true;
}
bool GLWindow::checkShaderLinkerStatus(GLuint PorgramID)
{
	GLint isLinked = 0;
	glGetProgramiv(PorgramID, GL_LINK_STATUS, &isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(PorgramID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		GLchar* errorLog = new GLchar[maxLength];
		glGetProgramInfoLog(PorgramID, maxLength, &maxLength, errorLog);
		cout << errorLog << endl;
		//The program is useless now. So delete it.
		glDeleteProgram(PorgramID);

		//Provide the infolog in whatever manner you deem best.
		//Exit with failure.
		return false;
	}
	return true;

}
void GLWindow::sendData()
{
	Mesh cube = cube.makeCube();
	Mesh plane = plane.makePlane();
	GLsizeiptr totalSize = 0;
	GLsizeiptr currenetOffset = 0;
	mesh_list.push_back(cube);
	mesh_list.push_back(plane);

	glGenBuffers(1, &BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, BufferID);

	for (int i = 0; i < mesh_list.size(); i++)
	{
		totalSize += mesh_list[i].vertexBufferSize() + mesh_list[i].indexBufferSize();
		VertexArrayObjectID.push_back(0);
		IndexBufferDataByteOffset.push_back(0);
	}
	glBufferData(GL_ARRAY_BUFFER, totalSize, 0, GL_STATIC_DRAW);
	for (int i = 0; i < mesh_list.size(); i++)
	{
		glBufferSubData(GL_ARRAY_BUFFER, currenetOffset, mesh_list[i].vertexBufferSize(), mesh_list[i].returnVertices());
		currenetOffset += mesh_list[i].vertexBufferSize();
		glBufferSubData(GL_ARRAY_BUFFER, currenetOffset, mesh_list[i].indexBufferSize(), mesh_list[i].returnIndices());
		currenetOffset += mesh_list[i].indexBufferSize();

	}
	GLuint ByteOffset = 0;
	for (int i = 0; i < mesh_list.size(); i++)
	{
		glGenVertexArrays(1, &VertexArrayObjectID[i]);
		glBindVertexArray(VertexArrayObjectID[i]);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, BufferID);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, mesh_list[i].getStride(), (void*)ByteOffset);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, mesh_list[i].getStride(), (void*)(ByteOffset + mesh_list[i].getOffsetColor()));
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, mesh_list[i].getStride(), (void*)(ByteOffset + mesh_list[i].getOffsetNormal()));
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, BufferID);
		ByteOffset = mesh_list[i].vertexBufferSize() + mesh_list[i].indexBufferSize();
	}
}


string readShaderCode(const char* fileName)
{
	ifstream input(fileName);
	if (!input.good())
	{
		cout << "Text file faild to load" << fileName;
		exit(1);
	}
	return string(
		istreambuf_iterator<char>(input),
		istreambuf_iterator<char>());
}
void GLWindow::installShaders()
{
	GLuint vertexShaderID= glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const char* adapter[1];
	string temp = readShaderCode("vertexShader.vs");
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);

	temp = readShaderCode("fragmentShader.fs");
	adapter[0] = temp.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);
	
	glCompileShader(fragmentShaderID);
	glCompileShader(vertexShaderID);

	if (!checkShaderCompileStatus(vertexShaderID) && !checkShaderCompileStatus(fragmentShaderID))
	{
		cout << "Shaders Comiplation faild\n";
		return;
	}
	
	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	

	glBindAttribLocation(programID, 0, "position");
	glBindAttribLocation(programID, 1, "color");
	glBindAttribLocation(programID, 2, "normal");
	glLinkProgramARB(programID);
	if (!checkShaderLinkerStatus(programID))
	{
		cout << "Link faild!\n";
		return;
	}
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	glUseProgram(programID);

}
void GLWindow::initializeGL()//only runs once
{
	setMouseTracking(true);
	glewExperimental = GL_TRUE;
	glewInit();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	sendData();
	installShaders();
	setUpUniforms();
	
	
}
void GLWindow::setUpUniforms()//only runs once
{

	GLint ambientLightUniformLocation = glGetUniformLocation(programID, "ambientLight");
	glUniform3f(ambientLightUniformLocation, L.getAmbient().r, L.getAmbient().g, L.getAmbient().b);
	GLint lightPositionUniformLocation = glGetUniformLocation(programID, "worldLightPosition");
	glUniform3f(lightPositionUniformLocation, L.getPosition().x, L.getPosition().y, L.getPosition().z);
	mvpUniformLocation = glGetUniformLocation(programID, "mvpMatrix");
	modeltoWorldTransformation = glGetUniformLocation(programID, "modelToWorldTransformationMatrix");

	

}
void GLWindow::paintGL()//runs repetitively
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, width(), height());

	mat4 mvpMatrix;//(view-->projection)*(world-->View)*(Model-->view)
	mat4 viewToProjectionMatrix = glm::perspective(glm::radians(60.0f), ((float)width()) / height(), 0.001f, 20.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	


	// Cube
	glBindVertexArray(VertexArrayObjectID[0]);
	mat4 cube1ModelToWorldMatrix =
		glm::translate(vec3(-1.0f, 0.0f, -3.0f)) *
		glm::rotate(glm::radians(65.0f), vec3(1.0f, 0.0f, 0.0f));
	mvpMatrix = worldToProjectionMatrix * cube1ModelToWorldMatrix;
	glUniformMatrix4fv(mvpUniformLocation, 1, GL_FALSE, &mvpMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, mesh_list[0].get_numIndices(), GL_UNSIGNED_SHORT, (void*)mesh_list[0].vertexBufferSize());
	glUniformMatrix4fv(modeltoWorldTransformation, 1, GL_FALSE, &cube1ModelToWorldMatrix[0][0]);

	mat4 cube2ModelToWorldMatrix =
		glm::translate(vec3(3.0f, 0.0f, -1.75f)) *
		glm::rotate(glm::radians(45.0f), vec3(0.0f, 1.0f, 0.0f));
	mvpMatrix = worldToProjectionMatrix * cube2ModelToWorldMatrix;
	glUniformMatrix4fv(mvpUniformLocation, 1, GL_FALSE, &mvpMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, mesh_list[0].get_numIndices(), GL_UNSIGNED_SHORT, (void*)mesh_list[0].vertexBufferSize());
	glUniformMatrix4fv(modeltoWorldTransformation, 1, GL_FALSE, &cube2ModelToWorldMatrix[0][0]);
	// Arrow
	glBindVertexArray(VertexArrayObjectID[1]);
	mat4 arrowModelToWorldMatrix = glm::translate(vec3(0.0f, -2.0f, 0.0f));
	mvpMatrix = worldToProjectionMatrix * arrowModelToWorldMatrix;
	glUniformMatrix4fv(mvpUniformLocation, 1, GL_FALSE, &mvpMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, mesh_list[1].get_numIndices(), GL_UNSIGNED_SHORT, (void*)(mesh_list[0].vertexBufferSize() + mesh_list[0].indexBufferSize() + mesh_list[1].vertexBufferSize()));
	glUniformMatrix4fv(modeltoWorldTransformation, 1, GL_FALSE, &arrowModelToWorldMatrix[0][0]);
}
void GLWindow::mouseMoveEvent(QMouseEvent* e)
{

	if (e->buttons() == Qt::LeftButton)
	{
		camera.mouseUpdate(glm::vec2(e->x(), e->y()));
		repaint();
	}
}
void GLWindow::keyPressEvent(QKeyEvent* e)
{
	switch (e->key())
	{
	case Qt::Key::Key_Up:
		camera.moveUp();
		break;
	case Qt::Key::Key_Down:
		camera.moveDown();
		break;
	case Qt::Key::Key_Left:
		camera.moveLeft();
		break;
	case Qt::Key::Key_Right:
		camera.moveRight();
		break;
	case Qt::Key::Key_PageUp:
		camera.moveForward();
		break;
	case Qt::Key::Key_PageDown:
		camera.moveBackward();
		break;
	}
	repaint();

}

