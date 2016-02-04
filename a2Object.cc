#include "a2Object.hh"

#include "colorSetter.hh"
#include "hexagon.hh"

A2Object::A2Object(int x, int y)
  : Entity(x, y),
    spinning(false),
    reverse(false),
    firstClick(true),
    lastMouseY(0.0),
    yHome(0),
    spinSpeedBase(5.0),
    spinSpeed(spinSpeedBase),
    spinSpeedBias(30.0)
{}

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
  lastMouseY = y;
  lastMouseState = state;
  switch (button) {
  case GLUT_LEFT_BUTTON:
    mouseDown(false);
    break;
  case GLUT_MIDDLE_BUTTON:
    break;
  case GLUT_RIGHT_BUTTON:
    mouseDown(true);
    break;
  default:
    break;
  }  
}

void A2Object::mouseDown(bool reverse) {
    spinSpeed = spinSpeedBase;
    if (lastMouseState == GLUT_DOWN) {
      if (firstClick)
        yHome = lastMouseY;
      firstClick = false;
      this->reverse = reverse;
      spinning = true;
    } else {
      spinning = false;
    }
}

void A2Object::spinLayer() {
  updateSpinSpeed();
  spin = (reverse ? spin - spinSpeed : spin + spinSpeed);
  if (spin > 360.0)
    spin -= 360.0;
  if (spin < 360.0)
    spin += 360.0;
}

void A2Object::updateSpinSpeed() {
  GLfloat difference = lastMouseY - yHome;
  GLfloat spinSpeedTarget = spinSpeedBase + difference / spinSpeedBias;
  GLfloat increment = 0.02;
  if (spinSpeed < spinSpeedTarget)
    spinSpeed -= increment;
  else if (spinSpeed > spinSpeedTarget)
    spinSpeed += increment;
  if (spinSpeed < 0.0)
    spinSpeed = 0.0;
}

