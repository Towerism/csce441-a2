#pragma once

#include "delegate/entity.hh"

#include "color/colorSetter.hh"
#include "tween.hh"

#include <GL/glut.h>
#include <memory>

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
  GLfloat intensity;
  ColorSetter color;
  ColorSetter lastColor;
  bool changing;
  bool reverse;
  bool firstClick;
  int lastMouseX;
  int lastMouseState;
  int xHome;
  GLfloat deltaBase;
  GLfloat delta;
  GLfloat deltaBias;
  Tween tween;
  
  void changeIntensity();
  void updateColorDelta();
  void updateColor();
  void mouseDown();
  void setColor(ColorSetter newColor) {
    color = newColor;
    lastColor = color;
  }
};
