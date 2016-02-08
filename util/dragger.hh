#pragma once

class Dragger {
public:
  Dragger(int& xBinding, int& yBinding)
    : startX(0), startY(0), endX(0), endY(0),
      xBinding(xBinding), yBinding(yBinding) {}

  void start(int x, int y);
  void end(int x, int y);

  void operator()();

private:
  int startX, startY, endX, endY;
  int& xBinding;
  int& yBinding;
};
