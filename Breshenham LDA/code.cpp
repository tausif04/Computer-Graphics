#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

void BresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int x = x1;
    int y = y1;

    int xInc = (x2 >= x1) ? 1 : -1;
    int yInc = (y2 >= y1) ? 1 : -1;

    int p;

    // Case 1: |slope| <= 1
    if (dy <= dx)
    {
        p = 2 * dy - dx;

        for (int i = 0; i <= dx; i++)
        {
            glVertex2f(x, y);

            if (p >= 0)
            {
                y += yInc;
                p += 2 * (dy - dx);
            }
            else
            {
                p += 2 * dy;
            }

            x += xInc;
        }
    }
    // Case 2: |slope| > 1
    else
    {
        p = 2 * dx - dy;

        for (int i = 0; i <= dy; i++)
        {
            glVertex2f(x, y);

            if (p >= 0)
            {
                x += xInc;
                p += 2 * (dx - dy);
            }
            else
            {
                p += 2 * dx;
            }

            y += yInc;
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glPointSize(3);

    glBegin(GL_POINTS);
    BresenhamLine(-50, -20, 80, 60); // Example line
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -100, 100);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Bresenham Line Drawing Algorithm");

    init();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}