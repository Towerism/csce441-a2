#include "mouseHome.hh"

MouseHome::MouseHome() : x(0), y(0), firstClick(true) {}

void MouseHome::click(int x, int y) {
  if (firstClick) {
    this->x = x;
    this->y = y;
    firstClick = false;
  }
}
