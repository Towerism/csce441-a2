//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "a2Object.hh"

#include "color/colorSetter.hh"
#include "shape/hexagon.hh"

A2Object::A2Object(int x, int y)
  : Entity(x, y),
    dimensions({50, 50}),
    spinning(false),
    reverse(false),
    spinSpeed(5.0, 30.0, 0.09),
    hexagonMode(GL_POLYGON),
    drag(position.x, position.y)
{
  origin = {-dimensions.x / 2, dimensions.y / 2};
}

void A2Object::update() {
  if (spinning)
    spinLayer();
}

void A2Object::draw() {
  ColorSetter color(0.4, 0.2, 0.05);
  drawHexagon({0, 0}, dimensions, 12, color, hexagonMode);
}

// 1,2,3 keys control we are drawn
void A2Object::keyboardEvent(unsigned char key, Vector2 mousePosition) {
  switch (key) {
  case '1':
    hexagonMode = GL_POINTS;
    break;
  case '2':
    hexagonMode = GL_LINE_LOOP;
    break;
  case '3':
    hexagonMode = GL_POLYGON;
    break;
  }
}

void A2Object::leftMouse() {
  mouseDown(false);
}

void A2Object::middleMouse() {
  if (lastMouseState == GLUT_DOWN) {
    drag.start(lastMouseX, lastMouseY);
  } else {
    drag.end(lastMouseX, lastMouseY);
    drag();
  }
}

void A2Object::rightMouse() {
  mouseDown(true);
}

// left click spins us one direction, right click spins us the other direction
void A2Object::mouseDown(bool reverse) {
  if (lastMouseState == GLUT_DOWN) {
    spinSpeed.reset();
    mouseHome.click(lastMouseX, lastMouseY);
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
  GLfloat difference = mouseHome.getY() - lastMouseY;
  spinSpeed.tween(difference, 0.02);
}

void A2Object::updateSpin() {
  spin = (reverse ? spin - spinSpeed : spin + spinSpeed);
  if (spin > 360.0)
    spin -= 360.0;
  if (spin < 0.0)
    spin += 360.0;
}

