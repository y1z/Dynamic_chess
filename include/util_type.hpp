#pragma once
#include <cstdint>

// yes this exist just to i don't have to type the '_t'
using int32 = int32_t;
using uint32 = uint32_t;



struct point32
{
  int32 x;
  int32 y;
};


struct upoint32
{
  uint32 x;
  uint32 y;
};

using size32 = point32;
using usize32 = upoint32;
