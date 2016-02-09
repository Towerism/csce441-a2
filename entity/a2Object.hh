//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

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

  virtual void keyboardEvent(unsigned char key, Vector2 mousePosition) override;
  virtual void leftMouse() override;
  virtual void middleMouse() override;
  virtual void rightMouse() override;

private:
  Vector2 dimensions;
  bool spinning; // whether we are spinning
  bool reverse; // whether spin velocity should be reversed
  MouseHome mouseHome;
  Tweenable spinSpeed; // how fast we are spinning
  GLenum hexagonMode; // openGL mode used when drawing the hexagon
  Dragger drag; // mechanism for dragging myself

  void mouseDown(bool reverse);
  void spinLayer();
  void updateSpinSpeed();
  void updateSpin();
};
