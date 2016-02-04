#include "a2Object.hh"

#include "colorSetter.hh"
#include "hexagon.hh"

#include <functional>

void A2Object::update() {
  if (spinning)
    spinLayer();
}

void A2Object::draw() {
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
    } else {
      spinning = false;
      spinSpeed = 0.0;
    }
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
    } else {
      spinning = false;
      spinSpeed = 0.0;
    }
    break;
  default:
    break;
  }  
  updateSpinVelocity(y);
}

void A2Object::spinLayer() {
  spin = spin + spinSpeed * (reverse ? -1 : 1);
  if (spin > 360.0)
    spin = spin - 360.0;
}

void A2Object::updateSpinVelocity(int y) {
  GLfloat spinSpeedChange = (y - yHome) / spinSpeedBias;
  spinSpeed = spinSpeedBase + spinSpeedChange;
  if (spinSpeed < 0.0)
    spinSpeed = 0.0;
}
