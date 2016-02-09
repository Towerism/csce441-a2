#include "rectangle.hh"

void drawRectangle(Vector2 position, Vector2 dimensions, ColorSetter color) {
  color();
  glRectf(position.x, position.y, position.x + dimensions.x, position.y + dimensions.y);
}
