//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <GL/glut.h>
#include <array>

class ColorSetter {
public:
  ColorSetter() : red(0.0), green(0.0), blue(0.0) {}
  ColorSetter(GLfloat red, GLfloat green, GLfloat blue)
    : red(red), green(green), blue(blue) { }

  void operator()();

  void operator*=(GLfloat intensityScale);
  ColorSetter operator*(GLfloat intensityScale);

  void operator/=(GLfloat intensityScale);
  ColorSetter operator/(GLfloat intensityScale);

  void operator+=(GLfloat intensityDelta);
  ColorSetter operator+(GLfloat intensityDelta);

  void operator-=(GLfloat intensityDelta);
  ColorSetter operator-(GLfloat intensityDelta);

  bool operator==(ColorSetter other);

private:
  GLfloat red, green, blue;

  // Returns input if control is >0, otherwise returns control
  GLfloat norm(GLfloat control, GLfloat input);

  // make sure color values stay between 0 and 1
  void clamp();
  void clampColor(GLfloat& color);
};

template <int count>
std::array<ColorSetter, count> makeColorSetters(GLfloat red,
                                                GLfloat green,
                                                GLfloat blue) {
  std::array<ColorSetter, count> colorSetters;
  colorSetters.fill(ColorSetter(red, green, blue));
  return colorSetters;
}
