#pragma once

#include <GL/glut.h>

class ColorSetter {
public:
  ColorSetter(GLfloat red, GLfloat green, GLfloat blue)
    : red(red), green(green), blue(blue) { }

  void operator()() { glColor3f(red, green, blue); }

private:
  GLfloat red, green, blue;
};
