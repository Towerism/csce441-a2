#pragma once

#include <GL/glut.h>

#include "util/vector2.hh"

// Base class for receiving messages from
// opengl callbacks
class Entity {
public:
  Entity(int x, int y) : position({x, y}), origin({0, 0}) { }

  // Handle idle event
  virtual void update() = 0;

  // Handle drawing event
  virtual void draw() = 0;

  // Handle keyboard event
  virtual void keyboardEvent(unsigned char key, Vector2 mousePosition) = 0;

  // Handle mouse event
  virtual void mouseEvent(int button, int state, Vector2 mousePosition);

  virtual void leftMouse() {}

  virtual void middleMouse() {}

  virtual void rightMouse() {}

  const Vector2& getPosition() const { return position; }
  const Vector2& getOrigin() const { return origin; }
  GLfloat getSpin() const { return spin; }

  virtual ~Entity() = default;

protected:
  Vector2 position, origin;

  // last* variables indicate what state the mouse was in
  // for the most recently captured mouse event
  int lastMouseX, lastMouseY, lastMouseState;
  GLfloat spin = 0.0; // how much the polygon on screen should spin

  void saveMouseState(int state, Vector2 mousePosition);
};
