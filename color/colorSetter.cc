//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "colorSetter.hh"

void ColorSetter::operator()() { glColor3f(red, green, blue); }

void ColorSetter::operator*=(GLfloat intensityScale) {
  red *= norm(red, intensityScale);
  green *= norm(green, intensityScale);
  blue *= norm(blue, intensityScale);
  clamp();
}

ColorSetter ColorSetter::operator*(GLfloat intensityScale) {
  ColorSetter color(red, green, blue);
  color *= intensityScale;
  return color;
}

ColorSetter ColorSetter::operator/(GLfloat intensityScale) {
  return *this * (1 / intensityScale);
}

void ColorSetter::operator/=(GLfloat intensityScale) {
  *this *= (1 / intensityScale);
}

void ColorSetter::operator+=(GLfloat intensityDelta) {
  red += norm(red, intensityDelta);
  green += norm(green, intensityDelta);
  blue += norm(blue, intensityDelta);
  clamp();
}

ColorSetter ColorSetter::operator+(GLfloat intensityDelta) {
  ColorSetter color(red, green, blue);
  color += intensityDelta;
  return color;
}

ColorSetter ColorSetter::operator-(GLfloat intensityDelta) {
  return *this + -intensityDelta;
}

void ColorSetter::operator-=(GLfloat intensityDelta) {
  *this += -intensityDelta;
}

bool ColorSetter::operator==(ColorSetter other) {
  return red == other.red && green == other.green && blue == other.blue;
}

// Returns input if control is >0, otherwise returns control
GLfloat ColorSetter::norm(GLfloat control, GLfloat input) {
  return (control > 0) ? input : control;
}

// make sure color values stay between 0 and 1
void ColorSetter::clamp() {
  clampColor(red);
  clampColor(green);
  clampColor(blue);
}

void ColorSetter::clampColor(GLfloat& color) {
  if (color < 0.0) {
    color = 0.0;
  } else if (color > 1.0) {
    color = 1.0;
  }
}
