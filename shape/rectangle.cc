//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "rectangle.hh"

void drawRectangle(Vector2 position, Vector2 dimensions, ColorSetter color) {
  color();
  glRectf(position.x, position.y, position.x + dimensions.x, position.y + dimensions.y);
}
