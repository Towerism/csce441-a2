#include "tweenable.hh"

void Tweenable::tween(float delta, float increment) {
  float biasAdjustedDelta = delta / bias;
  tweener.oneShotLinear(value, base + biasAdjustedDelta, increment);
  if (value < minimum) {
    value = minimum;
  }
}

void Tweenable::reset() {
  value = base;
  tweener = Tween();
}
