#pragma once

#include "delegate/entity.hh"
#include "tween/tween.hh"
#include "util/dragger.hh"
#include "util/mouseHome.hh"
#include "util/tweenable.hh"

#include <GL/glut.h>

// draws and controls a hexagon on the screen
class A2Object : public Entity {
public:
  A2Object(int x, int y);

  virtual void update() override;
  virtual void draw() override;

  virtual void keyboardEvent(unsigned char key, int x, int y) override;
  virtual void leftMouse() override;
  virtual void middleMouse() override;
  virtual void rightMouse() override;

private:
  bool spinning;
  bool reverse; // whether spin velocity should be reversed
  MouseHome mouseHome;
  Tweenable spinSpeed;
  GLenum hexagonMode; // openGL mode used when drawing the hexagon
  Dragger drag; // mechanism for dragging myself

  void mouseDown(bool reverse);
  void spinLayer();
  void updateSpinSpeed();
  void updateSpin();
};
