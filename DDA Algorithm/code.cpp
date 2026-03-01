#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
float x_start, y_start, x_end, y_end;
void display()
{
    float dx = x_end - x_start;
    float dy = y_end - y_start;
    int steps;

    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    float x_Inc = dx / steps;
    float y_Inc = dy / steps;
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    float x = x_start, y = y_start;
    for (int i = 0; i < steps; i++)
    {
        x += x_Inc;
        y += y_Inc;

        glVertex2f(round(x), round(y));
    }
    glEnd();

    glFlush();
}
void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -100, 100, -1, 1);
}

int main(int argc, char **argv)
{
    using namespace std;
    cout << "Enter x1 y1: ";
    cin >> x_start >> y_start;
    cout << "Enter x2 y2: ";
    cin >> x_end >> y_end;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Line Example");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

// g++ code.cpp -o code.exe -lopengl32 -lglu32 -lfreeglut
//.\code.exe