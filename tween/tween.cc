#include "tween.hh"

void Tween::oneShotLinear() {
  if (!complete)
    linearContinue();
}

void Tween::linearContinue() {
  if (current < target)
    linearUp();
  else if (current > target)
    linearDown();
}

void Tween::linearUp() {
  current += increment;
  checkComplete(true);
}

void Tween::linearDown() {
  current -= increment;
  checkComplete(false);
}

void Tween::checkComplete(bool linearUp) {
  if (linearUp) {
    if (current > target)
      complete = true;
  } else if (current < target)
    complete = true;
}

void Tween::setTarget(float newTarget, float newIncrement) {
  target = newTarget;
  increment = newIncrement;
}

void Tween::reset() {
  complete = false;
}
