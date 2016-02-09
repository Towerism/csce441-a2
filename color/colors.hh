//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include "colorSetter.hh"

#include <memory>

namespace Colors {

ColorSetter cyan(0.0, 1.0, 1.0);
ColorSetter white(1.0, 1.0, 1.0);
ColorSetter magenta(1.0, 0.0, 1.0);
ColorSetter yellow(1.0, 1.0, 0.0);

ColorSetter halfCyan(0.0, 0.5, 0.5);
ColorSetter halfWhite(0.5, 0.5, 0.5);
ColorSetter halfMagenta(0.5, 0.0, 0.5);
ColorSetter halfYellow(0.5, 0.5, 0.0);

}
