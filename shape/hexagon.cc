#include "hexagon.hh"

void drawHexagon(GLint x, GLint y, GLint w, GLint h, GLint delta,
                 std::array<ColorSetter, 6> colors) {
  // the x value that the diagonals meet up at
  // on the left and right sides of the hexagon
  GLint meetup = y - (h / 2);

  // draw the diagonals
  drawLine(x, meetup, x + delta, y - h, colors[0]); 
  drawLine(x, meetup, x + delta, y, colors[1]);
  drawLine(x + w - delta, y - h, x + w, meetup, colors[2]);
  drawLine(x + w - delta, y, x + w, meetup, colors[3]);

  // draw the horizontals
  drawLine(x + delta, y - h, x + w - delta, y - h, colors[4]);
  drawLine(x + delta, y, x + w - delta, y, colors[5]);
}

void drawHexagon(GLint x, GLint y, GLint w, GLint h, GLint delta,
                 ColorSetter color, GLenum mode) {
  GLint meetup = y - (h / 2);

  color();
  glBegin(mode);
  glVertex2i(x, meetup);
  glVertex2i(x + delta, y - h);
  glVertex2i(x + w - delta, y - h);
  glVertex2i(x + w, meetup);
  glVertex2i(x + w - delta, y);
  glVertex2i(x + delta, y);
  glVertex2i(x, meetup);
  glEnd();
}

void drawLine(GLint x1, GLint y1, GLint x2, GLint y2, ColorSetter color) {
  color(); // set the color by calling the function object
  glBegin(GL_LINES);
  glVertex2i(x1, y1); // Specify line segment geometry
  glVertex2i(x2, y2);
  glEnd();
}
