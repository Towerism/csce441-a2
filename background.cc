#include "background.hh"

#include "rectangle.hh"

Background::Background(int x, int y, int width, int height)
  : Entity(x, y), width(width), height(height) {}

void Background::update() {
  
}

void Background::draw() {
  ColorSetter color(0.2, 0.2, 0.2);
  drawRectangle(x, y, width, height, color);
}

void Background::keyboardEvent(unsigned char key, int x, int y) {
  
}

void Background::mouseEvent(int button, int state, int x, int y) {
  
}
