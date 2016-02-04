#include "a2Object.hh"

#include "colorSetter.hh"
#include "hexagon.hh"

#include <functional>

void A2Object::update() {
  if (spinning) {
    spinLayer();
  }
}

void A2Object::draw() {
  glRotatef(spin, 0.0, 0.0, 1.0);
  ColorSetter color(1.0, 1.0, 1.0);
  drawHexagon(x, y, 50, 50, 12, color);
}

void A2Object::keyboardEvent(char key, int x, int y) {
  
}

void A2Object::mouseEvent(int button, int state, int x, int y) {
  switch (button) {
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN) {
      if (firstClick)
        yHome = y;
      firstClick = false;
      reverse = false;
      spinning = true;
    }
    else
      spinning = false;
    break;
  case GLUT_MIDDLE_BUTTON:
    break;
  case GLUT_RIGHT_BUTTON:
    if (state == GLUT_DOWN) {
      if (firstClick)
        yHome = y;
      firstClick = false;
      reverse = true;
      spinning = true;
    }
    else
    break;
  default:
    break;
  }  
  updateSpinVelocity(y);
}

void A2Object::spinLayer() {
  spin = spin + spinVelocity * (reverse ? -1 : 1);
  if (spin > 360.0)
    spin = spin - 360.0;
}

void A2Object::updateSpinVelocity(int y) {
  GLfloat spinVelocityChange = (y - yHome) / spinVelocityBias;
  spinVelocity = spinVelocityBase + spinVelocityChange;
  if ((reverse && spinVelocity > 0.0) || spinVelocity < 0.0)
    spinVelocity = 0.0;
}
