#include <GL/glut.h>	
void init(void)
{
    glClearColor(0.2, 0.2, 0.2, 0.2);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-5, 5, -5, 5, 5, 15);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 10, 0, 2, 0, 0, 2, 5);

    return;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 4, 9);
       glBegin(GL_TRIANGLES);
			 glColor3f(1,1,1);
			 glVertex2f(-0.5,-0.5);
			 glVertex2f(-0.5,0.5);
			 glColor3f(1,0,0);
			 glVertex2f(0.5,0.5);
			glEnd();

    //glutWireTeapot(1); //绘制茶壶
    glFlush();

    return;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL 3D View");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}




