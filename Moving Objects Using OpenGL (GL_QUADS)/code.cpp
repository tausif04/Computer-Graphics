#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float p = -10.0;
float speed = 0.005;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    p = p + speed;

    if (p + 3 >= 10)
    {
        speed = -speed;
    }
    if (p <= -10)
    {
        speed = -speed;
    }

    glutPostRedisplay();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(p, 2);
    glVertex2f(p + 3, 2);
    glVertex2f(p + 3, -2);
    glVertex2f(p, -2);

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-2, p);
    glVertex2f(2, p);
    glVertex2f(2, p + 3);
    glVertex2f(-2, p + 3);

    glEnd();
    glFlush();
}

void init(void)
{
    glClearColor(0.0, 1.0, 0.450, 0.0);
    glOrtho(-10, 10, -10, 10, -10, 10);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("moving_object");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}