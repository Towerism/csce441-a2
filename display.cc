#include "display.hh"

#include <GL/glut.h>

void Display::add(Entity* entity) {
  entities.emplace_back(entity);
}

void Display::draw() {
  drawEntities();
}

void Display::drawEntities() {
  for (auto& entity : entities)
    drawEntity(entity);
}

void Display::drawEntity(std::unique_ptr<Entity>& entity) {
  glPushMatrix();
  glRotatef(entity->getSpin(), 0.0, 0.0, 1.0);
  entity->draw();
  glPopMatrix();
}


void Display::idle() {
  for (auto& entity : entities)
    entity->update();
}

void Display::mouse(int button, int status, int x, int y) {
  for (auto& entity : entities)
    entity->mouseEvent(button, status, x, y);
}
