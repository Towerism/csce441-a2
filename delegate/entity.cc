//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

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
