#pragma once

// Keeps track of the position of the first mouse click
class MouseHome {
public:
  MouseHome();

  // register a click, if it is the first click
  // update x and y
  void click(int x, int y);

  int getX() const { return x; }
  int getY() const { return y; }

private:
  int x, y;
  bool firstClick;
};
