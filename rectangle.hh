#pragma once

#include <GL/glut.h>

#include "colorSetter.hh"

// draws a colored w by h rectangle at (x, y)
void drawRectangle(GLint x, GLint y, GLint w, GLint h, ColorSetter color);
