#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>

/* This program draws a cylinder and then rotates it by 90 degs.
Then it places a cuboid on top of the cylinder
*/


void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,2.0,2.0,0.0,0.0,0.0,0.0,1.0,0.0);


	GLUquadricObj *MyCylinder;
	MyCylinder = gluNewQuadric();
	gluQuadricDrawStyle(MyCylinder, GLU_LINE);
	
	glRotatef(-90.0,1.0,0.0,0.0);
	gluCylinder(MyCylinder,0.5,0.5,1.0,12,12);

    // undo the rotation on line 24
	glRotatef(90.0,1.0,0.0,0.0);
    // Shift the y axis
	glTranslatef(0.0,1.0,0.0);
    // Rotate -30 degrees about the z axis
	glRotatef(-30.0,0.0,0.0,1.0);
    // Shift the y axis 0.5
	glTranslatef(0.0,0.5,0.0);
    // Scale the x and z axis by 0.25
	glScalef(0.25,1.0,0.25);
    // display cube
	glutWireCube(1.0);
	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.5,6.0);


	glViewport(0,0,w,h);
	return;
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cylinder");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);


	glutMainLoop();
}