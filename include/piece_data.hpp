#pragma once
#include <vector>
#include <array>
#include "util_type.hpp"

namespace dc
{

enum class moveTypes : uint32
{
  REGULAR = 0,
  BISHOP = 0b0000'0001,
  TOWER = 0b0000'0010,
  QUEEN = BISHOP | TOWER,
  KNIGHT = 0b1000'0000,
};

enum class attackAttributes : uint32
{
  MOVEMENT_SAME_AS_ATTACK = 0b0000'0001,
  MOVEMENT_DIFFERNT_FROM_ATTACK = ~MOVEMENT_SAME_AS_ATTACK,
};

/**
* @class pieceData piece_data.hpp
* @brief Represents how a piece works.
*/
struct pieceData
{
  pieceData(const std::vector<point32>& _how_piece_moves,
            const moveTypes _move_type,
            const attackAttributes _move_attri )
    :
    how_piece_moves(_how_piece_moves),
    move_type(_move_type),
    move_attri( _move_attri)
  {}

  /** which moves can the pieces do*/
  std::vector<point32> how_piece_moves;

  /** which moves can the pieces do*/
  moveTypes move_type;
  attackAttributes move_attri;
};


}
