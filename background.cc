#include "background.hh"

#include "colors.hh"
#include "rectangle.hh"

Background::Background(int x, int y, int width, int height)
  : Entity(x, y), width(width), height(height),
    color(Colors::cyan) {}

void Background::update() {
  
}

void Background::draw() {
  drawRectangle(x, y, width, height, *color);
}

void Background::keyboardEvent(unsigned char key, int x, int y) {
  switch (key) {
  case 'c':
    color = Colors::cyan;
    break;
  case 'w':
    color = Colors::white;
    break;
  case 'm':
    color = Colors::magenta;
    break;
  case 'y':
    color = Colors::yellow;
    break;
  } 
}

void Background::mouseEvent(int button, int state, int x, int y) {
  
}
