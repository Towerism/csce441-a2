#include "background.hh"

#include "color/colors.hh"
#include "shape/rectangle.hh"
#include "tween.hh"

Background::Background(int x, int y, int width, int height)
  : Entity(x, y),
    width(width),
    height(height),
    intensity(0),
    color(Colors::halfCyan),
    lastColor(color),
    changing(false),
    reverse(false),
    firstClick(true),
    lastMouseX(0.0),
    xHome(0),
    deltaBase(0.0),
    delta(deltaBase),
    deltaBias(400) { }

void Background::update() {
  if (changing)
    changeIntensity();
}

void Background::changeIntensity() {
  updateColorDelta();
  updateColor();
}

void Background::updateColorDelta() {
  GLfloat difference = lastMouseX - xHome;
  GLfloat deltaTarget = deltaBase + difference / deltaBias;
  GLfloat scale = 0.002;
  tween.oneShotLinear(delta, deltaTarget, scale);
}

void Background::updateColor() {
  color = lastColor + delta;
}

void Background::draw() {
  drawRectangle(x, y, width, height, color);
}

void Background::keyboardEvent(unsigned char key, int x, int y) {
  switch (key) {
  case 'c':
    setColor(Colors::halfCyan);
    break;
  case 'w':
    setColor(Colors::halfWhite);
    break;
  case 'm':
    setColor(Colors::halfMagenta);
    break;
  case 'y':
    setColor(Colors::halfYellow);
    break;
  } 
}

void Background::mouseEvent(int button, int state, int x, int y) {
  lastMouseX = x;
  lastMouseState = state;
  delta = deltaBase;
  switch (button) {
  case GLUT_LEFT_BUTTON:
    mouseDown();
    break;
  case GLUT_MIDDLE_BUTTON:
    break;
  case GLUT_RIGHT_BUTTON:
    mouseDown();
    break;
  default:
    break;
  }  
}

void Background::mouseDown() {
  if (lastMouseState == GLUT_DOWN) {
    tween = Tween();
    color = lastColor;
    if (firstClick)
      xHome = lastMouseX;
    firstClick = false;
    changing = true;
  } else {
    changing = false;
  }
}

