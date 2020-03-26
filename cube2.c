#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>


void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,3.0,0.0,0.0,0.0,0.0,1.0,0.0);

    // First cube
	glutWireCube(0.5);

    // Shifts the orign 0.7 units up the y axis
	glTranslatef(0.0,0.7,0.0);
    // Saves the current state of the system. (can come back to it using glPopMatrix)
	glPushMatrix();
    //Draw second cube
	glutWireCube(0.5);

	//glTranslatef(0.0,0.7,0.0);
    // Rotate the axis of the coordinate system (45 degrees, about the z axis - changes directions of x and y axis)
	glRotatef(45.0,0.0,0.0,1.0);
	glTranslatef(0.0,0.7,0.0);
    // scale x axis by 0.5, leave the rest the same
	glScalef(0.5,1.0,1.0);
	
	glutWireCube(0.5);

    // return coordinate system state to the way it was on line 21
	glPopMatrix();
	glTranslatef(0.0,0.7,0.0);
	glutWireCube(0.5);
	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,0.3,5.0);
//	glFrustum(-1.0,1.0,-1.0,1.0,9.5,12.0);
	gluPerspective(60,1.0,0.3,10.0);
	glViewport(0,0,w,h);
	return;
}




int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);


	glutMainLoop();
}