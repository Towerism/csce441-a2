#include "rectangle.hh"

void drawRectangle(GLint x, GLint y, GLint w, GLint h, ColorSetter color) {
  color();
  glRectf(x, y, x + w, y + h);
}
