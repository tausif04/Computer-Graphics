#include <GL/glut.h>
#include <iostream>
using namespace std;

float X1, Y1, Z1;
float X2, Y2, Z2;

// Translation
float transx = 0, transy = 0, transz = 0;
float tx, ty, tz;

// Rotation
float angleX = 0, angleY = 0, angleZ = 0;
float rotSpeed = 0;

void drawCubeFromPoints(float x1, float y1, float z1, float x2, float y2, float z2)
{
    glBegin(GL_QUADS);

    glColor3f(1, 0.7, 0.2);
    glVertex3f(x1, y1, z2);
    glVertex3f(x2, y1, z2);
    glVertex3f(x2, y2, z2);
    glVertex3f(x1, y2, z2);

    glColor3f(0.2, 1, 0.3);
    glVertex3f(x1, y1, z1);
    glVertex3f(x1, y2, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x2, y1, z1);

    glColor3f(0.2, 0.7, 1);
    glVertex3f(x1, y1, z1);
    glVertex3f(x1, y1, z2);
    glVertex3f(x1, y2, z2);
    glVertex3f(x1, y2, z1);

    glColor3f(1, 1, 0.5);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x2, y1, z2);

    glColor3f(1, 0.5, 1);
    glVertex3f(x1, y2, z1);
    glVertex3f(x1, y2, z2);
    glVertex3f(x2, y2, z2);
    glVertex3f(x2, y2, z1);

    glColor3f(0.5, 1, 1);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y1, z2);
    glVertex3f(x1, y1, z2);

    glEnd();
}

void keyboard(unsigned char key, int, int)
{
    switch (key)
    {
    // Translation
    case 's':
        transx += tx;
        break;
    case 'a':
        transx -= tx;
        break;

    case 'w':
        transy += ty;
        break;
    case 'd':
        transy -= ty;
        break;

    case 'x':
        transz += tz;
        break;
    case 'c':
        transz -= tz;
        break;

    // Rotation
    case 'j':
        angleX += rotSpeed;
        break;
    case 'k':
        angleY += rotSpeed;
        break;
    case 'l':
        angleZ += rotSpeed;
        break;

    case 'u':
        angleX -= rotSpeed;
        break;
    case 'i':
        angleY -= rotSpeed;
        break;
    case 'o':
        angleZ -= rotSpeed;
        break;
    }

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(10, 20, 30,
              0, 1, 0,
              0, 0, 1);

    // Apply transformations
    glTranslated(transx, transy, transz);

    glRotatef(angleX, 1, 0, 0); // X-axis
    glRotatef(angleY, 0, 1, 0); // Y-axis
    glRotatef(angleZ, 0, 0, 1); // Z-axis

    drawCubeFromPoints(X1, Y1, Z1, X2, Y2, Z2);

    glutSwapBuffers();
}

void init()
{
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);

    glutKeyboardFunc(keyboard);
}

int main(int argc, char **argv)
{
    cout << "Enter first point (x1 y1 z1): ";
    cin >> X1 >> Y1 >> Z1;

    cout << "Enter second point (x2 y2 z2): ";
    cin >> X2 >> Y2 >> Z2;

    cout << "Enter tx, ty, tz translation step values: ";
    cin >> tx >> ty >> tz;

    cout << "Enter rotation speed (degrees per key press): ";
    cin >> rotSpeed;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Cube with Rotation & Translation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
