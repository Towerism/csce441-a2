#pragma once

#include <GL/glut.h>

class ColorSetter {
public:
  ColorSetter() : red(0.0), green(0.0), blue(0.0) {}
  ColorSetter(GLfloat red, GLfloat green, GLfloat blue)
    : red(red), green(green), blue(blue) { }

  void operator()() { glColor3f(red, green, blue); }

private:
  GLfloat red, green, blue;
};
