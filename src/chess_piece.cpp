#include "chess_piece.hpp"

namespace dc {

chessPiece::chessPiece(pieceData _piece_data,
                       const point32 _position,
                       const usize32 _piece_size,
                       const bool _is_white,
                       std::string_view _text_form)
  :
  m_how_piece_works(std::move(_piece_data)),
  m_text_form(_text_form),
  m_position(_position),
  m_piece_size(_piece_size),
  m_is_white_side(_is_white) {}

std::string_view
chessPiece::get_text_form() const {
  return m_text_form;
}

chessPiece
chessPiece::pawn(const point32 position,
                 const usize32 piece_size,
                 const bool is_white_piece) {

  return chessPiece(pieceData::pawn(), position, piece_size, is_white_piece, "p");
}

chessPiece
chessPiece::knight(const point32 position,
                   const usize32 piece_size,
                   const bool is_white_piece) {
  return chessPiece(pieceData::knight(), position, piece_size,is_white_piece, "k");
}

chessPiece
chessPiece::tower(const point32 position,
                  const usize32 piece_size,
                  const bool is_white_piece) {

  return chessPiece(pieceData::tower(), position, piece_size, is_white_piece, "t");
}

chessPiece
chessPiece::bishop(const point32 position,
                   const usize32 piece_size,
                   const bool is_white_piece) {
  return chessPiece(pieceData::bishop(), position, piece_size, is_white_piece, "b");
}

chessPiece
chessPiece::queen(const point32 position,
                  const usize32 piece_size,
                  const bool is_white_piece) {
  return chessPiece(pieceData::queen(), position, piece_size, is_white_piece, "Q");
}

chessPiece
chessPiece::king(const point32 position,
                 const usize32 piece_size,
                 const bool is_white_piece) {
  return chessPiece(pieceData::king(), position, piece_size, is_white_piece, "K");
}

}
