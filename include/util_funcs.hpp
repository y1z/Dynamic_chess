#pragma once
#include "util_type.hpp"

#include "../raylib/src/raylib.h"

namespace dc
{

static fpoint32 get_rect_center(const Rectangle& rect)
{
  return {  rect.x + (rect.width * .5f)  , rect.y - (rect.height * .5f) };
}

}
