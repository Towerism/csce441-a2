#pragma once

class MouseHome {
public:
  MouseHome();

  void click(int x, int y);

  int getX() const { return x; }
  int getY() const { return y; }

private:
  int x, y;
  bool firstClick;
};
