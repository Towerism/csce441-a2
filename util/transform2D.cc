#include "transform2D.hh"

namespace Transform2D {

// translate current matrix to (x, y)
void translate(Vector2 translation) {
  glTranslatef(translation.x, translation.y, 0);
}

// rotate current matrix about (x,y) by spin degrees
void rotate(float spin, Vector2 origin) {
  translate(-origin);
  glRotatef(spin, 0, 0, 1);
  translate(origin);
}

}
