#include "entity.hh"

void Entity::mouseEvent(int button, int state, Vector2 mousePosition) {
  saveMouseState(state, mousePosition);
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

void Entity::saveMouseState(int state, Vector2 mousePosition) {
  lastMouseState = state;
  lastMouseX = mousePosition.x;
  lastMouseY = mousePosition.y;
}
