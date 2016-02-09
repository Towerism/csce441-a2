//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "entity/a2Object.hh"
#include "entity/background.hh"
#include "delegate/eventDelegator.hh"

#include <GL/glut.h>

// Captures events and delegates them to entities
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
  Background* background = new Background(0, 0, 250, 250);
  A2Object* a2Object = new A2Object(100, 150);
  // Order is important
  // background is added first, so will get drawn before a2Object
  eventDelegator.add(background); // delegate events to background
  eventDelegator.add(a2Object); // delegate events to a2Object
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
  gluOrtho2D(0.0, 250.0, 0.0, 250.0);
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
  eventDelegator.mouse(button, status, {x, y});
}

void keyboard(unsigned char key, int x, int y) {
  eventDelegator.keyboard(key, {x, y});
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
