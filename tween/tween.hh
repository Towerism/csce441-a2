#pragma once

class Tween {
public:
  // Tweens a current value to a target value using increment over time
  // Once the tween is complete, current is set to 0
  void oneShotLinear(float& current, float target, float increment);

  void reset();

private:
  bool complete;
  float current;
  float target;

  void checkComplete(bool lessThan);

  void linearContinue(float & current, float target, float increment);
  void linearUp(float& current, float target, float increment);
  void linearDown(float& current, float target, float increment);
};
