#include <GL/glut.h>
#include <iostream>
using namespace std;

void plotCirclePoints(int xc, int yc, int x, int y) {
  glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);

        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

    glEnd();

}
void BresenhamLine(int x1, int y1, int x2, int y2)
{
    glBegin(GL_POINTS);
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int x = x1;
    int y = y1;

    int xInc = (x2 >= x1) ? 1 : -1;
    int yInc = (y2 >= y1) ? 1 : -1;

    int p;

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

    glEnd();
}


void circleMidPoint(int centerX, int centerY, int r) {
      int x = 0;
    int y = r;
    int p = 1 - r;

    plotCirclePoints(centerX, centerY , x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        plotCirclePoints(centerX, centerY, x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    int centerX=150,centerY=150,r=100;
    circleMidPoint(centerX, centerY, r);
    glColor3f(0.0, 1.0, 0.0);
    BresenhamLine(10,10,370,10);
    BresenhamLine(10,10,10,300);
    BresenhamLine(10,300,370,300);
    BresenhamLine(370,300,370,10);
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

int main(int argc, char** argv) {
   // int centerX,centerY,r;
    //cin >> centerX >> centerY >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

