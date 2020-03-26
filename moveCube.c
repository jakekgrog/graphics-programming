#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/freeglut.h>
#include <stdio.h> 

double xshift = 0.0;
double yshift = 0.0;

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); // Controls relationship with viewer to object
	glLoadIdentity();   // Sets the matrix to the identity matrix (removes any previous values that might be in the matrix (fresh slate))
	gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0); // args 1-3 (locations of eye point), args 4-6 (direction of eye point), args 7-9 (up-vector (direction reguarded as up in this world))
    // The above code establishes relationship between eye and the rest of the world
    glTranslatef(xshift, yshift, 0.0);
	glutWireCube(0.5);
	
	glFlush();
	return;
}


void MyReshape(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION); //
	glLoadIdentity();

    // orthographic projection left, right, bottom, top, near, and far clipping planes (look at notes on loop for pic)
    //glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0); 
	
    // Frustum projection (left, right, bottom, top, near, and far clipping planes) (last two are distances from near and far clipping planes)
    glFrustum(-1.0,1.0,-1.0,1.0,0.5,3.0);

    // arg1 = view angle (FOV), arg2 = aspect ratio (width to height), arg3, arg4, distance to near and far clipping planes 
    //gluPerspective(60, 1.0, 0.3, 5.0); 

	glViewport(0,0,w,h);
	return;
}

void keyboardInput(GLint key, GLint x, GLint y) {
    if (key == GLUT_KEY_LEFT) xshift += 0.01;
    if (key == GLUT_KEY_RIGHT) xshift += -0.01;
    if (key == GLUT_KEY_UP) yshift += 0.01;
    if (key == GLUT_KEY_DOWN) yshift += -0.01;
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("Move Cube");
	glutDisplayFunc(display);
	
    glutReshapeFunc(MyReshape);
    glutSpecialFunc(keyboardInput);

	glutMainLoop();
}