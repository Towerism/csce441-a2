#include <GL/glut.h>

#include "colorSetter.hh"
#include "hexagon.hh"

static GLfloat spin = 0.0; // how much the polygon on screen should spin
static bool reverse = false; // whether spin velocity should be reversed
static bool firstClick = true; // whether the next click is the first click
static int yHome = 0; // the x position of the first mouse click
static const GLfloat spinVelocityBase = 5.0;
static GLfloat spinVelocity = spinVelocityBase;
static GLfloat spinVelocityBias = 30.0; // spin velocity's resistance to change

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glRotatef(spin, 0.0, 0.0, 1.0);
  ColorSetter color(1.0, 1.0, 1.0);
  drawHexagon(-25, 25, 50, 50, 12, color);
  glPopMatrix();

  glutSwapBuffers();
}

void spinDisplay(void)
{
  spin = spin + spinVelocity * (reverse ? -1 : 1);
  if (spin > 360.0)
    spin = spin - 360.0;
  glutPostRedisplay();
}

void updateSpinVelocity(int y) {
  GLfloat spinVelocityChange = (y - yHome) / spinVelocityBias;
  spinVelocity = spinVelocityBase + spinVelocityChange;
  if ((reverse && spinVelocity > 0.0) || spinVelocity < 0.0)
    spinVelocity = 0.0;
}

void init(void) 
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
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

void mouse(int button, int state, int x, int y) 
{
  switch (button) {
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN) {
      if (firstClick)
        yHome = y;
      firstClick = false;
      reverse = false;
      glutIdleFunc(spinDisplay);
    }
    else
      glutIdleFunc(NULL);
    break;
  case GLUT_MIDDLE_BUTTON:
    break;
  case GLUT_RIGHT_BUTTON:
    if (state == GLUT_DOWN) {
      if (firstClick)
        yHome = y;
      firstClick = false;
      reverse = true;
      glutIdleFunc(spinDisplay);
    }
    else
      glutIdleFunc(NULL);
    break;
  default:
    break;
   }
  updateSpinVelocity(y);
}
   
/* 
 *  Request double buffer display mode.
 *  Register mouse input callback functions
 */
int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (250, 250); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Martin Fracker - Assignment 2");
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape); 
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;   /* ANSI C requires main to return int. */
}
