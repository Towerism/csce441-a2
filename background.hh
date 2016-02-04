#pragma once

#include "entity.hh"

#include <GL/glut.h>

// draws and controls a hexagon on the screen
class Background : public Entity {
public:
  Background(int x, int y, int width, int height);

  virtual void update() override;
  virtual void draw() override;

  virtual void keyboardEvent(unsigned char key, int x, int y) override;
  virtual void mouseEvent(int button, int state, int x, int y) override;

private:
  int width, height;
};
