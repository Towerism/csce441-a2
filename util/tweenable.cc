#include "tweenable.hh"

#include <iostream>
void Tweenable::tween(float delta, float increment) {
  float biasAdjustedDelta = delta / bias;
  tweener.oneShotLinear(value, base + biasAdjustedDelta, increment);
  std::cout << "{before floor" << std::endl;
  std::cout << "value: " << value << std::endl;
  std::cout << "}" << std::endl;
  if (value < minimum) {
    value = minimum;
  }
  std::cout << "{after floor" << std::endl;
  std::cout << "value: " << value << std::endl;
  std::cout << "}" << std::endl;
}

void Tweenable::reset() {
  value = base;
  tweener = Tween();
}
