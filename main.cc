#include "a2Object.hh"
#include "delegator.hh"

#include <GL/glut.h>

Delegator delegator;

void draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  delegator.draw();

  glutSwapBuffers();
}

void init(void) 
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);

  A2Object* a2Object = new A2Object(-25, 25);
  delegator.add(a2Object);
}

void reshape(int w, int h)
{
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void idle() {
  delegator.idle();
  glutPostRedisplay();
}

void mouse(int button, int status, int x, int y) {
  delegator.mouse(button, status, x, y);
}

/* 
 *  Request double buffer delegator mode.
 *  Register mouse input callback functions
 */
int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (250, 250); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Martin Fracker - Assignment 2");
  init();
  glutDisplayFunc(draw); 
  glutReshapeFunc(reshape); 
  glutMouseFunc(mouse);
  glutIdleFunc(idle);
  glutMainLoop();
  return 0;   /* ANSI C requires main to return int. */
}
