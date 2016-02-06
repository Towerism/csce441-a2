#include "tween.hh"

void Tween::oneShotLinear(float& current, float target, float increment) {
  this->current = current;
  this->target = target;
  if (!complete) {
    if (current > target) {
      current -= increment;
      checkComplete(false);
    }
    else if (current < target) {
      current += increment;
      checkComplete(true);
    }
  }
  if (complete) {
    current = 0;
  }
}

void Tween::checkComplete(bool lessThan) {
  if (lessThan) {
    if (current > target)
      complete = true;
  } else if (current < target)
    complete = true;
}
