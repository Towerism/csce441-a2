#pragma once

#include "tween/tween.hh"

#include <limits>

class Tweenable {
public:
  Tweenable(float base, float bias, float minimum = -std::numeric_limits<float>::max())
    : base(base), bias(bias), minimum(minimum), value(base) {}

  void tween(float delta, float increment);
  void reset();
  float getValue() const { return value; }

  operator float() { return getValue(); }

private:
  float base, bias, minimum, value;
  Tween tweener;
};

