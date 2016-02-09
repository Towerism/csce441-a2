#include "eventDelegator.hh"
#include "util/transform2D.hh"

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
  Transform2D::translate(entity->getPosition());
  Transform2D::rotate(entity->getSpin(), entity->getOrigin());
  entity->draw();
  glPopMatrix();
}

void EventDelegator::idle() {
  for (auto& entity : entities)
    entity->update();
}

void EventDelegator::mouse(int button, int status, Vector2 mousePosition) {
  for (auto& entity : entities)
    entity->mouseEvent(button, status, mousePosition);
}

void EventDelegator::keyboard(unsigned char key, Vector2 mousePosition) {
  for (auto& entity : entities)
    entity->keyboardEvent(key, mousePosition);
}
