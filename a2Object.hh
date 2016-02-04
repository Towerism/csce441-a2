#include <GL/glut.h>

#include "entity.hh"

// draws and controls a hexagon on the screen
class A2Object : public Entity {
public:
  A2Object(int x, int y) : Entity(x, y) { }

  virtual void update();
  virtual void draw();

  virtual void keyboardEvent(char key, int x, int y);
  virtual void mouseEvent(int button, int state, int x, int y);

private:
  bool spinning = false;
  GLfloat spin = 0.0; // how much the polygon on screen should spin
  bool reverse = false; // whether spin velocity should be reversed
  bool firstClick = true; // whether the next click is the first click
  int yHome = 0; // the x position of the first mouse click
  const GLfloat spinVelocityBase = 5.0;
  GLfloat spinVelocity = spinVelocityBase;
  GLfloat spinVelocityBias = 30.0; // spin velocity's resistance to change

  void spinLayer();
  void updateSpinVelocity(int y);
};
