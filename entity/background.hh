#pragma once

#include "delegate/entity.hh"

#include "color/colorSetter.hh"
#include "tween/tween.hh"
#include "util/mouseHome.hh"
#include "util/tweenable.hh"

#include <GL/glut.h>
#include <memory>

// draws and controls a hexagon on the screen
class Background : public Entity {
public:
  Background(int x, int y, int width, int height);

  virtual void update() override;
  virtual void draw() override;

  virtual void keyboardEvent(unsigned char key, int x, int y) override;
  virtual void leftMouse() override;
  virtual void rightMouse() override;

private:
  int width, height;
  ColorSetter color, lastColor;
  bool changing;
  MouseHome mouseHome;
  Tweenable intensityDelta;
  
  void changeIntensity();
  void updateColorDelta();
  void updateColor();
  void mouseDown();
  void setColor(ColorSetter newColor);
};
