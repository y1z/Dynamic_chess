#pragma once
#include "util_type.hpp"
#include "piece_data.hpp"

namespace dc
{
/**
* @class chessPiece chess_piece.hpp
* @brief Represents a chess piece
*/
class chessPiece
{
public:
  chessPiece(pieceData piece_data,const point32 position,const bool _is_white);

private:
  pieceData m_how_piece_works;
public:
  point32 m_position;
  /// @brief no the actual color of the piece if it's on the side with the first turn
  bool m_is_white_side;
};


}
