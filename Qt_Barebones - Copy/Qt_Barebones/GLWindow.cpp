#include<gl\glew.h>
#include "GLWindow.h"
#include <iostream>
#include<fstream>
#include<glm.hpp>
#include"Vertex.h"
#include "Mesh.h"
#include"gtc\matrix_transform.hpp"
using namespace std;
GLuint programID;
GLuint numIndices;
GLWindow::GLWindow()
{
}


GLWindow::~GLWindow()
{
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
	glm::vec3 position;
	
	Mesh m;
	m = m.makeCube();
	GLuint Buffer;
	glGenBuffers(1, &Buffer);//create a buffer object
	glBindBuffer(GL_ARRAY_BUFFER, Buffer);
	glBufferData(GL_ARRAY_BUFFER,m.vertexBufferSize(), m.returnVertices(), GL_STATIC_DRAW);
	/*
	enables the generic vertex attribute array specified by index
	*/
	glEnableVertexAttribArray(0);//

	/*
	define an array of generic vertex attribute
	data every 3 float is one vertex
	stride is the byte differenc btw the begining of a the geometry
	of one vertex to the begining of the geometry of the other (5*sizeof(float))
	Note that if we did not have any color and geometries were compact, it was zero
	It is strange as it could be 2*sizeof(float) as we start from the begining of geometry
	to the begining of the geometry
	*/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
	glEnableVertexAttribArray(1);
	/*
	every 3 float is a color
	(char*) (sizeof(float)*3) says how much is the distance btw first color
	and the bgeining of the verts
	starts from 1 because it is the first attribute (0 attribute is the geometry)
	*/
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (char*)(sizeof(float) * 3));
	/*
	GLUSHORT: U since it does not have negative, and short is shorter than int
	*/
	GLuint indexBuffer;
	numIndices = m.get_numIndices();
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m.indexBufferSize(), m.returnIndices(), GL_STATIC_DRAW);
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
	glLinkProgramARB(programID);
	if (!checkShaderLinkerStatus(programID))
	{
		cout << "Link faild!\n";
		return;
	}
	glUseProgram(programID);

}
void GLWindow::initializeGL()//only runs once
{
	glewInit();
	glEnable(GL_DEPTH_TEST);
	sendData();
	installShaders();
	
}
void GLWindow::paintGL()//runs repetitively
{
	//glClear(GL_COLOR_BUFFER_BIT);
	//glClear(GL_DEPTH_BUFFER_BIT);// these two are equaivalent to the following (gclear is expensive to be called twice)
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, width(), height()); //to dynamically change what we draw when the widnow is resized
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	/*
		glDrawArrays(GL_TRIANGLES, 0, 6);//(triangles,i,j)j vertices starts from index i, you
		need to pass three vertices for each triangles with redundancy
	*/
	/*
		This is when we use indices of vertices,
		GL_UNSIGNED refers to the type of indices
	*/
	
	//Projection*transltae*rotate
	mat4 projectionMatrix = glm::perspective(glm::radians(60.0f), ((float)width()) / height(), 0.1f, 10.0f);
	mat4 projectionTranslateMatrix = glm::translate(projectionMatrix, vec3(0.0f, 0.0f, -3.0f));
	mat4 fullTransformMatrix = glm::rotate(projectionTranslateMatrix, glm::radians(54.0f), vec3(1.0f, 0.0f, 0.0f));
	GLint fullTransfromMatrixUniformLocation = glGetUniformLocation(programID, "fullTransformMatrix");
	GLint ProjectionMatrixUniformLocation = glGetUniformLocation(programID, "projectionMatrix");
	glUniformMatrix4fv(fullTransfromMatrixUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);

	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, NULL);
}

