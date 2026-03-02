#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2i(0, 0);
    glVertex2i(0, 20);
    glVertex2i(4, 5);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.9, 1.0);
    glVertex2i(0, 0);
    glVertex2i(0, 20);
    glVertex2i(-4, 5);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.9, 1.0);
    glVertex2i(0, 0);
    glVertex2i(-4, 5);
    glVertex2i(-16, 7);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2i(0, 0);
    glVertex2i(-16, 7);
    glVertex2i(-5, -2);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.9, 1.0);
    glVertex2i(0, 0);
    glVertex2i(-5, 2);
    glVertex2i(-7, -16);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.753f, 0.796f);
    glVertex2i(0, 0);
    glVertex2i(-7, -16);
    glVertex2i(0, -5);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.9, 1.0);
    glVertex2i(0, 0);
    glVertex2i(0, -5);
    glVertex2i(7, -16);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2i(0, 0);
    glVertex2i(7, -16);
    glVertex2i(6, -1);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.9, 1.0);
    glVertex2i(0, 0);
    glVertex2i(6, -1);
    glVertex2i(16, 7);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2i(0, 0);
    glVertex2i(16, 7);
    glVertex2i(4, 5);
    glEnd();

    glFlush();
}
void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20, 20, -20, 20, -20, 20);
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
