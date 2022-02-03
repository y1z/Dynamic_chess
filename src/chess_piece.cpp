#include "chess_piece.hpp"


namespace dc
{

chessPiece::chessPiece(pieceData _piece_data,
                       const point32 _position,
                       const usize32 _piece_size,
                       const bool _is_white,
                       size_t _piece_id,
                       std::string_view _text_form,
                       const Color _text_color)
  :
  m_how_piece_works(std::move(_piece_data)),
  m_text_form(_text_form),
  m_text_color(_text_color),
  m_position(_position),
  m_piece_size(_piece_size),
  m_piece_id(_piece_id),
  m_is_white_side(_is_white),
  m_is_alive(true)
{}

std::string_view
chessPiece::get_text_form() const
{
  return m_text_form;
}

void
chessPiece::draw_text() const
{
  DrawText(m_text_form.c_str(),
           (m_position.x * m_piece_size.x) + m_piece_size.x / 2,
           (m_position.y * m_piece_size.y),
           m_piece_size.x / 2,
           m_text_color);

}

const pieceData&
chessPiece::get_piece_data() const
{
  return m_how_piece_works;
}

size_t
chessPiece::get_id() const
{
  return m_piece_id;
}

movementTypes
chessPiece::get_movement_type() const
{
  return m_how_piece_works.move_type;
}

chessPiece
chessPiece::pawn(const point32 position,
                 const usize32 piece_size,
                 const bool is_white_piece,
                 size_t piece_id,
                 const Color piece_color)
{

  return chessPiece(pieceData::pawn(), position, piece_size, is_white_piece, piece_id, "p", piece_color);
}

chessPiece
chessPiece::knight(const point32 position,
                   const usize32 piece_size,
                   const bool is_white_piece,
                   size_t piece_id,
                   const Color piece_color)
{
  return chessPiece(pieceData::knight(), position, piece_size, is_white_piece, piece_id, "k", piece_color);
}

chessPiece
chessPiece::tower(const point32 position,
                  const usize32 piece_size,
                  const bool is_white_piece,
                  size_t piece_id,
                  const Color piece_color)
{

  return chessPiece(pieceData::tower(), position, piece_size, is_white_piece, piece_id, "t", piece_color);
}

chessPiece
chessPiece::bishop(const point32 position,
                   const usize32 piece_size,
                   const bool is_white_piece,
                   size_t piece_id,
                   const Color piece_color)
{
  return chessPiece(pieceData::bishop(), position, piece_size, is_white_piece, piece_id, "b", piece_color);
}

chessPiece
chessPiece::queen(const point32 position,
                  const usize32 piece_size,
                  const bool is_white_piece,
                  size_t piece_id,
                  const Color piece_color)
{
  return chessPiece(pieceData::queen(), position, piece_size, is_white_piece, piece_id, "Q", piece_color);
}

chessPiece
chessPiece::king(const point32 position,
                 const usize32 piece_size,
                 const bool is_white_piece,
                 size_t piece_id,
                 const Color piece_color)
{
  return chessPiece(pieceData::king(), position, piece_size, is_white_piece, piece_id, "K", piece_color);
}

}
