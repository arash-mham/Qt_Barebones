#pragma once
#include<QtOpenGL\QGLWidget>
class GLWindow:public QGLWidget
{
protected:
	void paintGL();
	void initializeGL();
public:
	GLWindow();
	~GLWindow();
	bool checkShaderCompileStatus(GLuint shader);
	bool checkShaderLinkerStatus(GLuint ProgramID);
	void sendData();
	void installShaders();
};

