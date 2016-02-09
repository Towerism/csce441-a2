//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

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
