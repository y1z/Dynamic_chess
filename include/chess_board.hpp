#pragma once
#include "util_type.hpp"
#include "chess_piece.hpp"

namespace dc
{
/**
* @class chessBoard chess_board.hpp
* @brief Represents a chess board
*/
class chessBoard
{
public:
  chessBoard(std::vector<chessPiece> _pieces,
             usize32 _board_size);

  /// @return A chess board with the default configuration (aka how chess is normally played )
  static chessBoard default_chess_board();

  /// @brief All the pieces in the chess board
  std::vector<chessPiece> m_pieces;

  /// @brief The size of the board
  usize32 m_board_size;
};

}
