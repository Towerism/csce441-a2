#include "eventDelegator.hh"

#include <GL/glut.h>

void EventDelegator::add(Entity* entity) {
  entities.emplace_back(entity);
}

void EventDelegator::draw() {
  drawEntities();
}

void EventDelegator::drawEntities() {
  for (auto& entity : entities)
    drawEntity(entity);
}

void EventDelegator::drawEntity(std::unique_ptr<Entity>& entity) {
  glPushMatrix();
  glRotatef(entity->getSpin(), 0.0, 0.0, 1.0);
  entity->draw();
  glPopMatrix();
}

void EventDelegator::idle() {
  for (auto& entity : entities)
    entity->update();
}

void EventDelegator::mouse(int button, int status, int x, int y) {
  for (auto& entity : entities)
    entity->mouseEvent(button, status, x, y);
}

void EventDelegator::keyboard(unsigned char key, int x, int y) {
  for (auto& entity : entities)
    entity->keyboardEvent(key, x, y);
}
