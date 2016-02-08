#include "entity.hh"

void Entity::mouseEvent(int button, int state, int x, int y) {
  saveMouseState(state, x, y);
  switch (button) {
  case GLUT_LEFT_BUTTON:
    leftMouse();
    break;
  case GLUT_MIDDLE_BUTTON:
    middleMouse();
    break;
  case GLUT_RIGHT_BUTTON:
    rightMouse();
    break;
  }  
}

void Entity::saveMouseState(int state, int x, int y) {
  lastMouseState = state;
  lastMouseX = x;
  lastMouseY = y;
}
