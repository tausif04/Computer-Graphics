#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

float tx = 0, ty = 0;
float spinf = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 1);
    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glRotatef(spinf, 0, 0, 1);
    glRectf(-25, -25, 25, 25); // Square
    glPopMatrix();
    glFlush();
}

void spinLeft()
{
    spinf = spinf + 5; // Rotate
    if (spinf >= 360)
        spinf = 0;
    glutPostRedisplay();
}

void spinRight()
{
    spinf = spinf - 5; // Rotate right
    if (spinf <= -360)
        spinf = 0;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'l':
        spinLeft();
        break; //
    case 'r':
        spinRight();
        break;
    case 'd':
        tx = tx + 5; // Right shift
        glutPostRedisplay();
        break;

    case 'a':
        tx = tx - 5; // Left shift
        glutPostRedisplay();
        break;

    case 'z':
        ty = ty - 5; // Down shift
        glutPostRedisplay();
        break;

    case 'w':
        ty = ty + 5; // Up shift
        glutPostRedisplay();
        break;
    }
}

void MyMouseFunc(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        spinLeft();
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        spinRight();
}

void init()
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -1, 1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("2D Transformations");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(MyMouseFunc);

    glutMainLoop();
    return 0;
}
