#pragma once
#include <cstdint>

// yes this exist just to i don't have to type the '_t'
using int32 = int32_t;
using uint32 = uint32_t;



template<class T>
struct point
{
  T x;
  T y;


  bool operator!=(const point& other)const
  {
    return !(this->operator==(other));
  }

  bool operator==(const point& other)const
  {
    return this->x == other.x && this->y == other.y;
  }
};

using point32 = point<int32>;
using upoint32 = point<uint32>;
using fpoint32 = point<float>;

using size32 = point32;
using usize32 = upoint32;
using fsize32 = fpoint32;
