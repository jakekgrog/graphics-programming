#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/freeglut.h>
#include <math.h>


/*
This program illustrates some 3D operations.
It draws a wire cube with sides of length 0.5 in World Coordinates.
You can uses the glOrtho or glFrustum functions
to choose either orthographic or perspective projection.
You can use the gluLookAt function to choose the viewpoint, 
view direction and the up vector.
*/

float theta = M_PI/4;

void display(void)
{
	GLfloat  ambient[4] = {0.3, 0.0, 0.0, 1.0};
	GLfloat  diffuse[4] = {0.6, 0.0, 0.0, 1.0};
	GLfloat specular[4] = {0.8, 0.6, 0.6, 1.0};
	GLfloat shininess = 32.0; // brightness of light spot on object when light source shining directly on it
	GLfloat normal[3] = {0.0,0.0,1.0}; //
	GLfloat position[4] = {1.0,1.0,1.0,1.0}; // x, y, z, located at infinity (e.g. light bulb in room or sun)
    // If 1.0 - light emits in all direction from 1, 1, 1. If 0.0, emits from infinity and rays are parallel to 1, 1, 1

	glClearColor(0.0,0.0,1.0,1.0);

	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	position[0]=0.3*cos(theta); position[1]=0.3*sin(theta); // Rotates in x, y plane

	glLightfv(GL_LIGHT0, GL_POSITION, position); // Change light source. 2nd arg = property of light source to change, 3rd arg = its position

	
	// glNormal3fv(normal);
	// glBegin(GL_POLYGON);
    //     glNormal3f(0.0f, 0.0f, 1.0);
	// 	glVertex3f(0.5,-0.5,0.0);
	// 	glVertex3f(0.5,0.5,0.0);
	// 	glVertex3f(-0.5,0.5,0.0);
	// 	glVertex3f(-0.5,-0.5,0.0);
	// glEnd();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);


	glutSolidCube(0.5);
    //glutSolidTorus(0.5, 1.0, 12, 12);
	glutSwapBuffers();
	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
	glFrustum(-1.0,1.0,-1.0,1.0,0.5,3.0);
	glViewport(0,0,w,h);
	return;
}

void MyIdle()
{

	theta += 0.1;
	if (theta > 2*M_PI) theta -= 2*M_PI;
	glutPostRedisplay();

	return;
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);
	glutIdleFunc(MyIdle);


	glutMainLoop();
}