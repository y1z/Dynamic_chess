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
             usize32 _column_and_row_count,
             usize32 _cell_size,
             const Color _starting_side_color = WHITE,
             const Color _opposite_side_color = BLACK);



  /// @brief Draws the board and the piece on it
  void
  draw()const;

  /// @return A chess board with the default configuration (aka how chess is normally played )
  static chessBoard default_chess_board(const std::optional<usize32> size_of_pieces = std::nullopt);

  /// @brief All the pieces in the chess board
  std::vector<chessPiece> m_pieces;

  /// @brief How big is the board
  Rectangle m_area;


  /// @brief Counts the columns and rows
  usize32 m_column_and_row_count;

  /// @brief The size of every cell
  usize32 m_cell_size;

  /// @brief The first color
  Color m_starting_side_color;

  /// @brief The second color
  Color m_opposite_side_color;
};

}
