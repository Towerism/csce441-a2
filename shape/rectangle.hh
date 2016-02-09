#pragma once

#include <GL/glut.h>

#include "color/colorSetter.hh"
#include "util/vector2.hh"

// draws a colored w by h rectangle at (x, y)
void drawRectangle(Vector2 position, Vector2 dimensions, ColorSetter color);
