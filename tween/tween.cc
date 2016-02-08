#include "tween.hh"

void Tween::oneShotLinear(float& current, float target, float increment) {
  this->current = current;
  this->target = target;
  if (!complete)
    linearContinue(current, target, increment);
  if (complete)
    current = 0;
}

void Tween::linearContinue(float& current, float target, float increment) {
    if (current < target)
      linearUp(current, target, increment);
    else if (current > target)
      linearDown(current, target, increment);
}

void Tween::linearUp(float& current, float target, float increment) {
  current += increment;
  checkComplete(true);
}

void Tween::linearDown(float& current, float target, float increment) {
  current -= increment;
  checkComplete(false);
}

void Tween::checkComplete(bool lessThan) {
  if (lessThan) {
    if (current > target)
      complete = true;
  } else if (current < target)
    complete = true;
}

void Tween::reset() {
  complete = false;
}
