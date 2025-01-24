#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>


void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
  glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
  glLoadIdentity();
  glOrtho(0.0, 100, 0.0, 100.0, -1.0, 1.0);
  ///ekhane x y axis thik kore disi, (0,100), (0,100) baki tuk
  ///same thakbe eta asole 3d system er jonne kaj kore but 2d korsi
  //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void Draw()
{
 glClear(GL_COLOR_BUFFER_BIT);
   glColor3f( 1 ,0, 1);

   ///ekta kore process start hoy then end hoy

   //ghor
   glBegin(GL_POLYGON);
   glVertex2i(25,25);
   glVertex2i(75,25);
   glVertex2i(75,75);
   glVertex2i(25,75);

   glEnd();

   //ghor er chaal
   glColor3f( 1 ,1, 1);
   glBegin(GL_POLYGON);
   glVertex2i(25,75);
   glVertex2i(75,75);
   glVertex2i(50,90);

   glEnd();

   //dorja
   glColor3f( 0 ,0, 2);
   glBegin(GL_POLYGON);
   glVertex2i(40,25);
   glVertex2i(60,25);
   glVertex2i(60,40);
   glVertex2i(40,40);

    glEnd();



   //janala
   glColor3f( 0 ,2, 3);
   glBegin(GL_POLYGON);
   glVertex2i(60,50);
   glVertex2i(70,50);
   glVertex2i(70,60);
   glVertex2i(60,60);

    glEnd();
// Write your Code/////@############



glutSwapBuffers();
}

int main(int argc,char **argv){


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
