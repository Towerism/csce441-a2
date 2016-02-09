#pragma once

#include <GL/glut.h>

// Base class for receiving messages from
// opengl callbacks
class Entity {
public:
  Entity(int x, int y) : x(x), y(y) { }

  // Handle idle event
  virtual void update() = 0;

  // Handle drawing event
  virtual void draw() = 0;

  // Handle keyboard event
  virtual void keyboardEvent(unsigned char key, int x, int y) = 0;

  // Handle mouse event
  virtual void mouseEvent(int button, int state, int x, int y);

  virtual void leftMouse() {}

  virtual void middleMouse() {}

  virtual void rightMouse() {}

  int getX() const { return x; }
  int getY() const { return y; }
  GLfloat getSpin() const { return spin; }

  virtual ~Entity() = default;

protected:
  // last* variables indicate what state the mouse was in
  // for the most recently captured mouse event
  int x, y, lastMouseX, lastMouseY, lastMouseState;
  GLfloat spin = 0.0; // how much the polygon on screen should spin

  void saveMouseState(int state, int x, int y);
};
