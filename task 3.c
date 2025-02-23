#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-25.0, 25.0, -25.0, 25.0, -2.5, 2.5);
}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++) {
        float angle = 2*3.14 * i / 50;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);
    circle(4.5, 4.5, 16, 10);
    circle(4.5, 4.5, 10, 12.5);
    circle(4.5, 4.5, 10, 6);
    circle(4.5, 4.5, 5, 11.5);
    circle(4.5, 4.5, 1.5, 9.5);
    circle(4, 4, -2.5, 6);
    circle(4.5, 4.5, 2.5, 5);

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cloud Shape");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
