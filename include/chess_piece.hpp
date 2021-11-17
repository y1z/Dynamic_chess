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
  chessPiece(pieceData piece_data,
             const point32 position,
             const bool _is_white,
             std::string_view _text_form = "?");


  /// @return The text representation of a piece
  std::string_view
  get_text_form()const;

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
  /// @brief No the actual color of the piece if it's on the side with the first turn
  bool m_is_white_side;
};


}
