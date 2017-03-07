#include<Qt\qapplication.h>
#include"GLWindow.h"
int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	GLWindow glWindow;
	glWindow.show();
	return app.exec();
}