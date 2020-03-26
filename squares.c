#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/freeglut.h>

/* 
 * 2017R Q7
 * --------
 * Create three squares each of side of length 0.2 and whose centres are 0.3 units apart.
 *
 * If you right click with the mouse in square 1, then the background colour should turn red.
 * If you right click with the mouse in square 2, then the background colour should turn blue.
 * If you right click with the mouse in square 3, then the background colour should turn green.
*/

float sideLength = 0.2;
float centreDistance = 0.3;

void reshape(GLsizei w, GLsizei h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glViewport(0, 0, w/2, h/2);
    return;
}

void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);

    GLfloat x = -0.1;
    GLfloat y = -0.1;

    // glBegin(GL_POLYGON);
    //     glVertex2f(-0.5, -0.5);
    //     glVertex2f(-0.5, 0.5);
    //     glVertex2f(0.5, 0.5);
    //     glVertex2f(0.5, -0.5);
    // glEnd();
	
    for (int i = 0; i < 4; i++) {
        glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x - (x - sideLength), y);
            glVertex2f(x - (x - sideLength), y - (y - sideLength));
            glVertex2f(x, y - (y - sideLength));
    	glEnd();
        x += centreDistance;
    }
    
	glFlush();
	return;
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
	glutCreateWindow("Squares");
	glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutMainLoop();
}


