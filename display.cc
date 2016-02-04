#include "display.hh"

#include <GL/glut.h>

void Delegator::add(Entity* entity) {
  entities.emplace_back(entity);
}

void Delegator::draw() {
  drawEntities();
}

void Delegator::drawEntities() {
  for (auto& entity : entities)
    drawEntity(entity);
}

void Delegator::drawEntity(std::unique_ptr<Entity>& entity) {
  glPushMatrix();
  glRotatef(entity->getSpin(), 0.0, 0.0, 1.0);
  entity->draw();
  glPopMatrix();
}


void Delegator::idle() {
  for (auto& entity : entities)
    entity->update();
}

void Delegator::mouse(int button, int status, int x, int y) {
  for (auto& entity : entities)
    entity->mouseEvent(button, status, x, y);
}
