#include "piece_data.hpp"

namespace dc
{
using std::vector;

pieceData
pieceData::pawn() {
  const vector<point32> pawn_movement = { point32{ 0,1} };
  const vector<point32> pawn_attack = { point32{ 1,1},point32{1,-1} };
  return pieceData(pawn_movement,
                   movementTypes::PAWN,
                   attackType::MOVEMENT_DIFFERNT_FROM_ATTACK,
                   false,
                   pawn_attack);
}

pieceData
pieceData::knight() {
  const vector<point32> knight_movement =
  {
    point32{1,2},
    point32{-1,2},
    point32{2,1},
    point32{2,-1},
    point32{-2,1},
    point32{-2,-1},
    point32{1,-2},
    point32{-1,-2},
  };
  return pieceData(knight_movement, movementTypes::KNIGHT, attackType::MOVEMENT_SAME_AS_ATTACK);
}

pieceData
pieceData::tower() {
  const vector<point32> tower_movement = { point32{1,0}, point32{-1,0}, point32{0,1},point32{0,-1} };
  return pieceData(tower_movement,
                   movementTypes::TOWER,
                   attackType::MOVEMENT_SAME_AS_ATTACK);
}

pieceData
pieceData::bishop() {
  const vector<point32> bishop_movement = { point32{1,1}, point32{-1,1}, point32{1,-1}, point32{-1,-1} };
  return pieceData(bishop_movement,
                   movementTypes::BISHOP,
                   attackType::MOVEMENT_SAME_AS_ATTACK);
}

pieceData
pieceData::queen() {
  const vector<point32> queen_movement =
  {
    point32{1,1},
    point32{-1,1},
    point32{1,-1},
    point32{-1,-1},

    point32{1,0},
    point32{-1,0},
    point32{0,1},
    point32{0,-1},
  };
  return pieceData(queen_movement,
                   movementTypes::QUEEN,
                   attackType::MOVEMENT_SAME_AS_ATTACK);
}

pieceData
pieceData::king() {

  const vector<point32> king_movement =
  {
    point32{1,1},
    point32{-1,1},
    point32{1,-1},
    point32{-1,-1},

    point32{1,0},
    point32{-1,0},
    point32{0,1},
    point32{0,-1},
  };
  return pieceData(king_movement,
                   movementTypes::REGULAR,
                   attackType::MOVEMENT_SAME_AS_ATTACK,
                   true);
}








}