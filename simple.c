#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/freeglut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(0.5,-0.5);
	glEnd();

	glFlush();
	return;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("simple");
	glutDisplayFunc(display);
	glutMainLoop();
}
