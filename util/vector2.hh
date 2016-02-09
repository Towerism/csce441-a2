#pragma once

struct Vector2 {
  int x, y;
};

inline Vector2 operator-(Vector2 vector2) {
  return { -vector2.x, -vector2.y };
}
