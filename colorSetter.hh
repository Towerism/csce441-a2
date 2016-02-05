#pragma once

#include <GL/glut.h>
#include <array>

class ColorSetter {
public:
  ColorSetter() : red(0.0), green(0.0), blue(0.0) {}
  ColorSetter(GLfloat red, GLfloat green, GLfloat blue)
    : red(red), green(green), blue(blue) { }

  void operator()() { glColor3f(red, green, blue); }

  ColorSetter operator*(GLfloat intensityScale) {
    ColorSetter color(red, green, blue);
    color.red *= norm(red, intensityScale);
    color.green *= norm(green, intensityScale);
    color.blue *= norm(blue, intensityScale);
    clamp();
    return color;
  }
  void operator*=(GLfloat intensityScale) {
    red *= norm(red, intensityScale);
    green *= norm(green, intensityScale);
    blue *= norm(blue, intensityScale);
    clamp();
  }
  ColorSetter operator/(GLfloat intensityScale) { return *this * (1 / intensityScale); }
  void operator/=(GLfloat intensityScale) { *this *= (1 / intensityScale); }

  ColorSetter operator+(GLfloat intensityDelta) {
    ColorSetter color(red, green, blue);
    color.red += norm(red, intensityDelta);
    color.green += norm(green, intensityDelta);
    color.blue += norm(blue, intensityDelta);
    clamp();
    return color;
  }
  void operator+=(GLfloat intensityDelta) {
    red += norm(red, intensityDelta);
    green += norm(green, intensityDelta);
    blue += norm(blue, intensityDelta);
    clamp();
  }
  ColorSetter operator-(GLfloat intensityDelta) { return *this + -intensityDelta; }
  void operator-=(GLfloat intensityDelta) { *this -= intensityDelta; }

  bool operator==(ColorSetter other) {
    return red == other.red && green == other.green && blue == other.blue;
  }

private:
  GLfloat red, green, blue;

  // Returns input if control is >0, otherwise returns control
  GLfloat norm(GLfloat control, GLfloat input) {
    return (control > 0) ? input : control;
  }

  // make sure color values stay between 0 and 1
  void clamp() {
    clampColor(red);
    clampColor(green);
    clampColor(blue);
  }

  void clampColor(GLfloat& color) {
    if (color < 0.0) {
      color = 0.0;
    } else if (color > 1.0) {
      color = 1.0;
    }
  }
};

template <int count>
std::array<ColorSetter, count> makeColorSetters(GLfloat red,
                                                GLfloat green,
                                                GLfloat blue) {
  std::array<ColorSetter, count> colorSetters;
  colorSetters.fill(ColorSetter(red, green, blue));
  return colorSetters;
}
