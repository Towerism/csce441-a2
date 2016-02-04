#pragma once

#include "entity.hh"

#include <vector>
#include <memory>

// delegates events to entities
class EventDelegator {
public:
  EventDelegator() { }

  void add(Entity* entity);
  
  void draw();
  void idle();
  void mouse(int button, int status, int x, int y);
  void keyboard(unsigned char key, int x, int y);

private:
  std::vector<std::unique_ptr<Entity>> entities;

  void drawEntities();
  void drawEntity(std::unique_ptr<Entity>& entity);
};
