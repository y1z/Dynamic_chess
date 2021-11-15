#pragma once
#include <vector>
#include <array>
#include <optional>
#include "util_type.hpp"

namespace dc
{

/// @brief Describes how a piece moves
enum class moveTypes : uint32
{
  REGULAR = 0,
  PAWN = 0b0000'0001,
  BISHOP = 0b0000'0010,
  TOWER = 0b0000'0100,
  QUEEN = BISHOP | TOWER,
  KNIGHT = 0b1000'0000,
};

/// @brief Describes how a piece attacks
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
            const attackAttributes _move_attri ,
            const std::optional<std::vector<point32>> _how_piece_attacks = std::nullopt)
    :
    how_piece_moves(_how_piece_moves),
    move_type(_move_type),
    move_attri( _move_attri),
    how_piece_attacks(_how_piece_attacks)
  {}

  /// @return The data necessary for a pawn
  static pieceData pawn();

  /// @brief Which moves can the pieces do
  std::vector<point32> how_piece_moves;

  /// @brief The relative where a piece goes to attack
  const std::optional<std::vector<point32>> how_piece_attacks;

  /// @brief which moves can the pieces do
  moveTypes move_type;
  attackAttributes move_attri;
};


}