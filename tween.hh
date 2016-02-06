#pragma once

class Tween {
public:
  // Tweens a current value to a target value using increment over time
  // Once the tween is complete, current is set to 0
  void oneShotLinear(float& current, float target, float increment) {
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

private:
  bool complete;
  float current;
  float target;

  void checkComplete(bool lessThan) {
    if (lessThan) {
      if (current > target)
        complete = true;
    } else if (current < target)
        complete = true;
  }
};
