#include "entity.hh"

void Entity::mouseEvent(int button, int state, int x, int y) {
  lastMouseX = x;
  lastMouseY = y;
  lastMouseState = state;
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
  default:
    break;
  }  
}
