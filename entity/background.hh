//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

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

  virtual void keyboardEvent(unsigned char key, Vector2 mousePosition) override;
  virtual void leftMouse() override;
  virtual void rightMouse() override;

private:
  Vector2 dimensions; // dimensions for the rectangle
  ColorSetter color, lastColor; // storing lastColor so we can switch back to it
  bool changing; // whether we are changing colors
  MouseHome mouseHome;
  Tweenable intensityDelta; // how much to change the intensity of lastColor
  
  void changeIntensity();
  void updateColorDelta();
  void updateColor();
  void mouseDown();
  void setColor(ColorSetter newColor);
};
