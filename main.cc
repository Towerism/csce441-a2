#include "entity/a2Object.hh"
#include "entity/background.hh"
#include "delegate/eventDelegator.hh"

#include <GL/glut.h>

EventDelegator eventDelegator;

void initGlut() {
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (250, 250);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Martin Fracker - Assignment 2");
}

void initDisplay() {
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
}

void initEntities() {
  Background* background = new Background(-50, -50, 100, 100);
  A2Object* a2Object = new A2Object(-25, 25);
  eventDelegator.add(background);
  eventDelegator.add(a2Object);
}

void init(void) {
  initGlut();
  initDisplay();
  initEntities();
}

void reshape(int w, int h) {
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void draw(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  eventDelegator.draw();

  glutSwapBuffers();
}

void idle() {
  eventDelegator.idle();
  glutPostRedisplay();
}

void mouse(int button, int status, int x, int y) {
  eventDelegator.mouse(button, status, x, y);
}

void keyboard(unsigned char key, int x, int y) {
  eventDelegator.keyboard(key,  x, y);
}

void attachCallbacks() {
  glutDisplayFunc(draw); 
  glutReshapeFunc(reshape); 
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle);
}

/* 
 *  Request double buffer mode.
 *  Register mouse input callback functions
 */
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  init();
  attachCallbacks();
  glutMainLoop();
  return 0;   /* ANSI C requires main to return int. */
}
