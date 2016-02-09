#pragma once

#include <GL/glut.h>

#include "vector2.hh"

namespace Transform2D {

// translate current matrix by a translation vector2
void translate(Vector2 translation);

// rotate current matrix about an origin by spin degrees
void rotate(float spin, Vector2 origin);

}
