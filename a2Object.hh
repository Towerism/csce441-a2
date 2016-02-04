#pragma once

#include "entity.hh"

#include <GL/glut.h>

// draws and controls a hexagon on the screen
class A2Object : public Entity {
public:
  A2Object(int x, int y) : Entity(x, y) { }

  virtual void update() override;
  virtual void draw() override;

  virtual void keyboardEvent(char key, int x, int y) override;
  virtual void mouseEvent(int button, int state, int x, int y) override;

private:
  bool spinning = false;
  bool reverse = false; // whether spin velocity should be reversed
  bool firstClick = true; // whether the next click is the first click
  int yHome = 0; // the x position of the first mouse click
  const GLfloat spinSpeedBase = 5.0;
  GLfloat spinSpeed = spinSpeedBase;
  GLfloat spinSpeedBias = 30.0; // spin speed's resistance to change

  void spinLayer();
  void updateSpinVelocity(int y);
};
