#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(5);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.5, 1.0);
    glVertex2f(-8, 3);
    glVertex2f(0, 8);
    glVertex2f(8, 3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-5, 3);
    glVertex2f(5, 3);
    glVertex2f(5, -7);
    glVertex2f(-5, -7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.4, 1.0);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -7);
    glVertex2f(-1, -7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1, 1);
    glVertex2f(-4, -0.2);
    glVertex2f(-1.5, -0.2);
    glVertex2f(-1.5, -4);
    glVertex2f(-4, -4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1, 1);
    glVertex2f(1.5, -0.2);
    glVertex2f(4, -0.2);
    glVertex2f(4, -4);
    glVertex2f(1.5, -4);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); // Set up a 2D orthographic projection
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Line Example");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
