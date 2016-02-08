#pragma once

// Facilitates dragging logic
class Dragger {
public:
  Dragger(int& xBinding, int& yBinding)
    : startX(0), startY(0), endX(0), endY(0),
      xBinding(xBinding), yBinding(yBinding) {}

  // indicate where the drag is starting
  void start(int x, int y);

  // where it is ending
  void end(int x, int y);

  // execute the drag
  void operator()();

private:
  int startX, startY, endX, endY;
  int& xBinding; // the x value we are controlling
  int& yBinding;
};
