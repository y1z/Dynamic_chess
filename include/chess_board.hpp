#pragma once
#include "util_type.hpp"
#include "chess_piece.hpp"
#include <deque>
#include <optional>

namespace dc
{
/**
* @class chessBoard chess_board.hpp
* @brief Represents a chess board
*/
class chessBoard
{
public:

  struct boardCell
  {
    point32 cell_position;
    bool is_occupied_by_piece;
  };
  chessBoard(std::vector<chessPiece> _pieces,
             usize32 _column_and_row_count,
             usize32 _cell_size,
             const Color _starting_side_color = WHITE,
             const Color _opposite_side_color = BLACK);


  /// @brief Draws the board and the piece on it
  void
  draw()const;

  /// @param[in] index Which piece are you going to generate the `Rectangle` for
  /// @returns A `Rectangle` that defines the area the piece occupies on the board
  Rectangle
  gen_rectangle_for_piece(size_t index)const;


  /// @param position Where you check to see if there is a chess piece there.
  /// @returns A pointer to the given piece
  const chessPiece *
  get_piece_ptr_at(const Vector2 position);

  /// @param position Where you check to see if there is a chess piece there.
  /// @return A `Rectangle` that represent the area the piece occupies.
  std::optional<Rectangle>
  get_piece_rect_at(const Vector2 position);

  void
  print_board_cells();

  /// @return A chess board with the default configuration (aka how chess is normally played )
  static chessBoard
  default_chess_board(const std::optional<usize32> size_of_pieces = std::nullopt);

private:


  /// @param position Where you check to see if there is a chess piece there.
  /// @return true if the piece is at that position
  bool
  is_piece_at(const Vector2 position, const size_t index)const;

  /// @param cell_position Which of the cell to check
  /// @returns true if there is a cell at the cell_position
  bool
  is_piece_at_cell_position(const point32 cell_position)const;

  /// @param cell_position Which of the cell to check
  /// @return The text used to represent the piece
  std::string_view
  get_text_for_piece_at(const point32 cell_position)const;


  std::optional<size_t>
  get_chess_piece_index_at_cell(const point32 cell_position)const;

  std::vector<boardCell> m_board_cells;
public:
  /// @brief All the pieces in the chess board
  std::deque<chessPiece> m_pieces;

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
