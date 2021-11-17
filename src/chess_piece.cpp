#include "chess_piece.hpp"

namespace dc
{

chessPiece::chessPiece(pieceData _piece_data ,
                       const point32 _position,
                       const bool _is_white,
                       std::string_view _text_form)
  :
  m_how_piece_works(std::move(_piece_data)),
  m_position(_position),
  m_is_white_side(_is_white),
  m_text_form(_text_form)
{}

std::string_view
chessPiece::get_text_form() const {
  return m_text_form;
}

}
