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

  GLfloat getX() const { return x; }
  GLfloat getY() const { return y; }
  GLfloat getSpin() const { return spin; }

  virtual ~Entity() = default;

protected:
  int x, y, lastMouseX, lastMouseY, lastMouseState;
  GLfloat spin = 0.0; // how much the polygon on screen should spin
};
