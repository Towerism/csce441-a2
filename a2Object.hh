#pragma once

#include "entity.hh"

#include <GL/glut.h>

// draws and controls a hexagon on the screen
class A2Object : public Entity {
public:
  A2Object(int x, int y);

  virtual void update() override;
  virtual void draw() override;

  virtual void keyboardEvent(unsigned char key, int x, int y) override;
  virtual void mouseEvent(int button, int state, int x, int y) override;

private:
  bool spinning;
  bool reverse; // whether spin velocity should be reversed
  bool firstClick; // whether the next click is the first click
  int lastMouseY; // during the most recent mouse event
  int lastMouseState;
  int yHome; // the x position of the first mouse click
  GLfloat spinSpeedBase;
  GLfloat spinSpeed;
  GLfloat spinSpeedBias; // spin speed's resistance to change
  GLenum hexagonMode; // openGL mode used when drawing the hexagon

  void mouseDown(bool reverse);
  void spinLayer();
  void updateSpinSpeed();
  void updateSpin();
};
