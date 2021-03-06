//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "hexagon.hh"

void drawHexagon(Vector2 position, Vector2 dimensions, GLint delta,
                 ColorSetter color, GLenum mode) {
  GLint meetup = position.y - (dimensions.y / 2);

  color();
  glBegin(mode);
  glVertex2i(position.x, meetup);
  glVertex2i(position.x + delta, position.y - dimensions.y);
  glVertex2i(position.x + dimensions.x - delta, position.y - dimensions.y);
  glVertex2i(position.x + dimensions.x, meetup);
  glVertex2i(position.x + dimensions.x - delta, position.y);
  glVertex2i(position.x + delta, position.y);
  glEnd();
}

void drawLine(Vector2 startPoint, Vector2 endPoint, ColorSetter color) {
  color(); // set the color by calling the function object
  glBegin(GL_LINES);
  glVertex2i(startPoint.x, startPoint.y); // Specify line segment geometry
  glVertex2i(startPoint.x, endPoint.y);
  glEnd();
}
