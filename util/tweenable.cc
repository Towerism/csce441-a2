#include "tweenable.hh"

#include <iostream>
void Tweenable::tween(float delta, float increment) {
  float biasAdjustedDelta = delta / bias;
  tweener.setTarget(base + biasAdjustedDelta, increment);
  tweener.oneShotLinear();
  std::cout << value << std::endl;
  clampToMinimum();
}

void Tweenable::clampToMinimum() {
  if (value < minimum)
    value = minimum;
}

void Tweenable::reset() {
  value = base;
  tweener.reset();
}
