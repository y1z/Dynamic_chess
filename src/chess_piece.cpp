#include "chess_piece.hpp"

namespace dc {
chessPiece::chessPiece(pieceData _piece_data ,
                       const point32 _position)
  :
  m_how_piece_works(std::move(_piece_data)),
  m_position(_position)
{}

}
