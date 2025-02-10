#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

int x1, y1, x2, y2, dy, dx, pk, step;
int x, y;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Background color is black
    glMatrixMode(GL_PROJECTION);  // Set projection matrix mode
    glLoadIdentity();
    glOrtho(0.0, 1000, 0.0, 1000.0, -1.0, 1.0);  // Set orthographic projection
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    dy = y2 - y1;
    dx = x2 - x1;
    pk = 2 * dy - dx;

    if (dy > dx)
    {
        step = dy;
    }
    else
    {
        step = dx;
    }


    x = x1;
    y = y1;
 glBegin(GL_POINTS);
    glColor3f(1, 1, 0);
    for (int i = 0; i < step; i++)
    {
        if (pk < 0)
        {
            x = x + 1;
            y = y;
            pk = pk + 2 * dy;
        }
        else
        {
            x = x + 1;
            y = y + 1;
            pk = pk + 2 * dy - 2 * dx;
        }



        glVertex2i(x, y);

    }
  glEnd();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    printf("Enter x1, y1, x2, y2: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Drawing - Bresenham");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
