#pragma once  

#include <array>
#include <GL/glut.h>

#include "color/colorSetter.hh"

// draw a colored w by h octogon with x, y coordinates being the top left
// corner of an imaginary encompassing square
// delta is the distance from any vertex to the nearest corner of an
// imaginary encompassing square
// colors is an array of ColorSetters corresponding to each edge
void drawHexagon(GLint x, GLint y, GLint w, GLint h, GLint delta,
                 std::array<ColorSetter, 6> colors);

// Same as above, except only one color is specified for all the edges
// plus the fill color
// Mode allows you to set the vertex mode for openGL
void drawHexagon(GLint x, GLint y, GLint w, GLint h, GLint delta,
                 ColorSetter color, GLenum mode = GL_POLYGON);

// draw a colored line starting at (x1, y1) and ending at (x2, y2) 
void drawLine(GLint x1, GLint y1, GLint x2, GLint y2, ColorSetter color);
