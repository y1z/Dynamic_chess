#pragma once
#include "util_type.hpp"
#include "piece_data.hpp"
#include "../raylib/src/raylib.h"
#include <string>

namespace dc
{
/**
* @class chessPiece chess_piece.hpp
* @brief Represents a chess piece
*/
class chessPiece
{
public:
  chessPiece(pieceData _piece_data,
             const point32 _position,
             const usize32 _piece_size,
             const bool _is_white,
             size_t piece_id,
             std::string_view _text_form = "?",
             const Color _text_color = GRAY);


  /// @return The text representation of a piece
  std::string_view
  get_text_form()const;

  /// @brief Draws the chess piece.
  void
  draw_text()const;

  /// @return A reference to the data of the piece.
  const pieceData&
  get_piece_data()const;


  /// @param position Where the piece will be in the board
  /// @param piece_size How big is the chess piece
  /// @return A pawn for a chess game
  static chessPiece
  pawn(const point32 position,
       const usize32 piece_size,
       const bool is_white_piece,
       size_t piece_id,
       const Color piece_color = GRAY);

  /// @param position Where the piece will be in the board
  /// @param piece_size How big is the chess piece
  /// @return A knight for a chess game
  static chessPiece
  knight(const point32 position,
         const usize32 piece_size,
         const bool is_white_piece,
         size_t piece_id,
         const Color piece_color = GRAY);

  /// @param position Where the piece will be in the board
  /// @param piece_size How big is the chess piece
  /// @return A tower for a chess game
  static chessPiece
  tower(const point32 position,
        const usize32 piece_size,
        const bool is_white_piece,
        size_t piece_id,
        const Color piece_color = GRAY);

  /// @param position Where the piece will be in the board
  /// @param piece_size How big is the chess piece
  /// @return A bishop for a chess game
  static chessPiece
  bishop(const point32 position,
         const usize32 piece_size,
         const bool is_white_piece,
         size_t piece_id,
         const Color piece_color = GRAY);

  /// @param position Where the piece will be in the board
  /// @param piece_size How big is the chess piece
  /// @return A queen for a chess game
  static chessPiece
  queen(const point32 position,
        const usize32 piece_size,
        const bool is_white_piece,
        size_t piece_id,
        const Color piece_color = GRAY);

  /// @param position Where the piece will be in the board
  /// @param piece_size How big is the chess piece
  /// @return A king for a chess game
  static chessPiece
  king(const point32 position,
       const usize32 piece_size,
       const bool is_white_piece,
       size_t piece_id,
       const Color piece_color = GRAY);

private:
  /// @brief Determines how the piece works
  pieceData m_how_piece_works;

  /// @brief How the piece looks
  Texture2D m_texture;

  /// @brief How to represent the piece in text form
  std::string m_text_form;

public:
  /// @brief Where the piece is located.
  point32 m_position;

  /// @brief How big the piece is
  usize32 m_piece_size;

  size_t m_piece_id;

  /// @brief It's the color the text from uses
  Color m_text_color;

  /// @brief No the actual color of the piece if it's on the side with the first turn
  bool m_is_white_side;

  /// @brief keeps track of if the piece is still in play
  bool m_is_alive;
};


}
