#pragma once
#include<QtOpenGL\QGLWidget>
#include"Camera.h"
#include<Qt\qevent.h>
class GLWindow:public QGLWidget
{
	Camera camera;
protected:
	void paintGL();
	void initializeGL();
	void mouseMoveEvent(QMouseEvent*);
	void keyPressEvent(QKeyEvent*);
public:
	GLWindow();
	~GLWindow();
	bool checkShaderCompileStatus(GLuint shader);
	bool checkShaderLinkerStatus(GLuint ProgramID);
	void sendData();
	void installShaders();
	
};

