#pragma once  

#include <array>
#include <GL/glut.h>

#include "color/colorSetter.hh"
#include "util/vector2.hh"

// draw a colored w by h octogon with x, y coordinates being the top left
// corner of an imaginary encompassing square
// delta is the distance from any vertex to the nearest corner of an
// imaginary encompassing square
// Mode allows you to set the vertex mode for openGL
void drawHexagon(Vector2 position, Vector2 dimensions, GLint delta,
                 ColorSetter color, GLenum mode = GL_POLYGON);

// draw a colored line
void drawLine(Vector2 startPoint, Vector2 endPoint, ColorSetter color);
