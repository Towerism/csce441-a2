#pragma once

#include "entity.hh"

#include <vector>
#include <memory>

#include "util/vector2.hh"

// delegates events to entities
class EventDelegator {
public:
  EventDelegator() { }

  // Add entity to list of entities to delegate events to
  void add(Entity* entity);
  
  // Delegate draw event to each entity
  void draw();
  
  // Delegate idle event to each entity
  void idle();

  // Delegate mouse event to each entity
  void mouse(int button, int status, Vector2 mousePosition);

  // Delegate keyboard event to each entity
  void keyboard(unsigned char key, Vector2 mousePosition);

private:
  std::vector<std::unique_ptr<Entity>> entities;

  void drawEntities();
  void drawEntity(std::unique_ptr<Entity>& entity);
};
