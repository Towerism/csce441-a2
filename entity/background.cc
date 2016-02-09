//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "background.hh"

#include "color/colors.hh"
#include "shape/rectangle.hh"

Background::Background(int x, int y, int width, int height)
  : Entity(x, y),
    dimensions({width, height}),
    color(Colors::halfCyan),
    lastColor(color),
    changing(false),
    intensityDelta(0.0, 400.0)
    {}

void Background::update() {
  if (changing)
    changeIntensity();
}

void Background::changeIntensity() {
  updateColorDelta();
  updateColor();
}

// Interpolate our color from our current color to our target color
void Background::updateColorDelta() {
  GLfloat difference = lastMouseX - mouseHome.getX();
  intensityDelta.tween(difference, 0.002);
}

void Background::updateColor() {
  color = lastColor + intensityDelta;
}

void Background::draw() {
  drawRectangle({0, 0}, dimensions, color);
}

// c,w,m,y keys control our color
void Background::keyboardEvent(unsigned char key, Vector2 mousePosition) {
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

void Background::leftMouse() {
  mouseDown();
}

void Background::rightMouse() {
  mouseDown();
}

// lower intensity when mouse is left of home
// raise it when mouse is right of home
void Background::mouseDown() {
  if (lastMouseState == GLUT_DOWN) {
    intensityDelta.reset();
    color = lastColor;
    mouseHome.click(lastMouseX, lastMouseY);
    changing = true;
  } else {
    changing = false;
  }
}

void Background::setColor(ColorSetter newColor) {
  color = newColor;
  lastColor = color;
}
