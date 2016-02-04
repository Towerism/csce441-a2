class Tween {
public:
  // Tweens a current value to a target value using increment over time
  // when positive is true, the value will not be allowed to fall below 0.0
  static void linear(float& current, float target, float increment, bool positive) {
    if (current < target)
      current -= increment;
    else if (current > target)
      current += increment;
    if (positive && current < 0.0)
      current = 0.0;
  }
};
