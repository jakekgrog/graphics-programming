#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/freeglut.h>
#include <math.h>

void display(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // BUFFER BIT FOR DEPTH TEST - Z BUFFER

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat pos[4] = {0.0, 0.0, 1.0, 0.0}; // LIGHT SOURCE AT INFINITY (PARALLEL RAYS)
    glLightfv(GL_LIGHT0, GL_POSITION, pos);

	glMatrixMode(GL_MODELVIEW); // Controls relationship with viewer to object
	glLoadIdentity();   // Sets the matrix to the identity matrix (removes any previous values that might be in the matrix (fresh slate))
	gluLookAt(0.0,0.0,2.0,0.0,0.0,0.0,0.0,1.0,0.0); // args 1-3 (locations of eye point), args 4-6 (direction of eye point), args 7-9 (up-vector (direction reguarded as up in this world))
    // The above code establishes relationship between eye and the rest of the world

    float theta = M_PI / 4;
    GLfloat x, y, z, x1, z1;
    y = -1.0;
    
    GLfloat radius;
    radius = 0.6;
	// SPIRAL
    glBegin(GL_QUAD_STRIP);
        for (int j = 0; j < 60; j++) {
            if (radius < 0.05) {
                break;
            }
            for(int i = 0; i < 21; i++) {
                theta += 2 * M_PI / 20;
                x = radius * cos(theta);
                z = radius * sin(theta);
                
                x1 = (radius - 0.1) * cos(theta);
                z1 = (radius - 0.1) * sin(theta);

                

                glNormal3f(x / radius , 0, z / radius); // DIVIDE BY 0.6 TO MAKE MAGNITUDE = 1 - Needed for lighting to know where the normals of the objects are so it can reflect
                glVertex3f(x, y, z);
                glVertex3f(x1, y+0.1, z1);
            }
            y += 0.06;
            radius -= 0.05;
            
        }
    glEnd();
	
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




int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(500,200);

    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH); // Tells systems we're going to work out depth of objects

	glutCreateWindow("cube");
	glutDisplayFunc(display);
	glutReshapeFunc(MyReshape);

    glEnable(GL_DEPTH_TEST); // For testing depth of objects

	glutMainLoop();
}