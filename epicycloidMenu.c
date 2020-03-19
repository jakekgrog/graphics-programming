#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/freeglut.h>
#include <math.h>

float theta1 = M_PI/4;
float theta2 = M_PI/4;

float t1RotateSpeed = 0.001;
float t2RotateSpeed = 0.0001;

GLfloat r1 = 0.2;
GLfloat r2 = 0.5;

GLfloat x, y;

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);

	x=r1*cos(theta1) + r2*cos(theta2);
	y=r1*sin(theta1) + r2*sin(theta2);

	glPointSize(10.0);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
    
	glFlush();
	return;
}

void MyIdle()
{	
	theta1 += t1RotateSpeed;
	theta2 += t2RotateSpeed;
	glutPostRedisplay();

	return;
}

void MyMenu(int choice) {
    switch (choice) {
        case 1:
            r1 += 0.1;
            break;
        case 2:
            r1 += -0.1;
            break;
        case 3:
            r2 += 0.1;
            break;
        case 4:
            r2 += -0.1;
            break;
        case 5:
            t1RotateSpeed += 0.01;
            break;
        case 6:
            t1RotateSpeed += -0.01;
            break;
        case 7:
            t2RotateSpeed += 0.001;
            break;
        case 8:
            t2RotateSpeed += -0.001;
            break;
        case 9:
            exit(0);
            break;
    }
}
	
int main(int argc, char **argv)
{
    GLint subMenu;
	glutInit(&argc, argv);
	glutCreateWindow("Epicycloid");
	glutDisplayFunc(display);
	glutIdleFunc(MyIdle);

    glutCreateMenu(MyMenu);
    glutAddMenuEntry("Increase R1", 1);
    glutAddMenuEntry("Decrease R1", 2);

    glutAddMenuEntry("Increase R2", 3);
    glutAddMenuEntry("Decrease R2", 4);

    glutAddMenuEntry("Increase Theta 1", 5);
    glutAddMenuEntry("Decrease Theta 1", 6);

    glutAddMenuEntry("Increase Theta 2", 7);
    glutAddMenuEntry("Decrease Theta 2", 8);

    glutAddMenuEntry("Exit", 9);
    
    glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
}