#pragma once

#include "colorSetter.hh"

#include <memory>

namespace Colors {

std::shared_ptr<ColorSetter> cyan =
  std::make_shared<ColorSetter>(0.0, 1.0, 1.0);

std::shared_ptr<ColorSetter> white =
  std::make_shared<ColorSetter>(1.0, 1.0, 1.0);

std::shared_ptr<ColorSetter> magenta =
  std::make_shared<ColorSetter>(1.0, 0.0, 1.0);

std::shared_ptr<ColorSetter> yellow =
  std::make_shared<ColorSetter>(1.0, 1.0, 0.0);

}
