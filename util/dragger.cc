#include "dragger.hh"

void Dragger::start(int x, int y) {
  startX = x;
  startY = y;
}

void Dragger::end(int x, int y) {
  endX = x;
  endY = y;
}

void Dragger::operator()() {
  int deltaX = endX - startX;
  int deltaY = endY - startY;
  xBinding += deltaX * 100 / 250;
  yBinding += -deltaY * 100 / 250;
}
