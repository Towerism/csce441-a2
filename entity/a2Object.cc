#include "a2Object.hh"

#include "color/colorSetter.hh"
#include "shape/hexagon.hh"

A2Object::A2Object(int x, int y)
  : Entity(x, y),
    spinning(false),
    reverse(false),
    firstClick(true),
    lastMouseY(0.0),
    yHome(0),
    spinSpeedBase(5.0),
    spinSpeed(spinSpeedBase),
    spinSpeedBias(30.0),
    hexagonMode(GL_POLYGON)
{}

void A2Object::update() {
  if (spinning)
    spinLayer();
}

void A2Object::draw() {
  ColorSetter color(0.4, 0.2, 0.05);
  drawHexagon(0, 0, 50, 50, 12, color, hexagonMode);
}

// 1,2,3 keys control we are drawn
void A2Object::keyboardEvent(unsigned char key, int x, int y) {
  switch (key) {
  case '1':
    hexagonMode = GL_POINTS;
    break;
  case '2':
    hexagonMode = GL_LINE_STRIP;
    break;
  case '3':
    hexagonMode = GL_POLYGON;
    break;
  }
}

// Controls our position and rotation
void A2Object::mouseEvent(int button, int state, int x, int y) {
  lastMouseY = y;
  lastMouseState = state;
  switch (button) {
  case GLUT_LEFT_BUTTON:
    mouseDown(false);
    break;
  case GLUT_MIDDLE_BUTTON:
    if (state == GLUT_DOWN) {
      startX = x;
      startY = y;
    } else {
      endX = x;
      endY = y;
      int deltaX = endX - startX;
      int deltaY = endY - startY;
      this->x += deltaX * 100 / 250;
      this->y += -deltaY * 100 / 250;
    }
    break;
  case GLUT_RIGHT_BUTTON:
    mouseDown(true);
    break;
  default:
    break;
  }  
}

// left click spins us one direction, right click spins us the other direction
void A2Object::mouseDown(bool reverse) {
  spinSpeed = spinSpeedBase;
  if (lastMouseState == GLUT_DOWN) {
    tween = Tween(); // renew our tween
    if (firstClick)
      yHome = lastMouseY; // save y position on initial click
    firstClick = false;
    this->reverse = reverse;
    spinning = true;
  } else {
    spinning = false;
  }
}

void A2Object::spinLayer() {
  updateSpinSpeed();
  updateSpin();
}

// Control our spin speed by interpolating between current spin speed
// and target spin speed
void A2Object::updateSpinSpeed() {
  GLfloat difference = yHome - lastMouseY;
  GLfloat spinSpeedTarget = spinSpeedBase + difference / spinSpeedBias;
  GLfloat increment = 0.02;
  tween.oneShotLinear(spinSpeed, spinSpeedTarget, increment);
  if (spinSpeed < 0.09) {
    spinSpeed = 0.09;
  }
}

void A2Object::updateSpin() {
  spin = (reverse ? spin - spinSpeed : spin + spinSpeed);
  if (spin > 360.0)
    spin -= 360.0;
  if (spin < 0.0)
    spin += 360.0;
}

