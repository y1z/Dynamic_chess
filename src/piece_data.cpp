#include "piece_data.hpp"
#include <array>

namespace dc {

static constexpr std::array<point32, 1> pawn_movement = { point32{ 0,1} };
static constexpr std::array<point32, 2> pawn_attack = { point32{ 1,1},point32{1,-1} };

pieceData
pieceData::pawn()
{
  return pieceData(std::vector<point32>(pawn_movement.begin(), pawn_movement.end()),
                   moveTypes::PAWN,
                   attackAttributes::MOVEMENT_DIFFERNT_FROM_ATTACK,
                   std::vector<point32>(pawn_attack.begin(), pawn_attack.end()));
}

}