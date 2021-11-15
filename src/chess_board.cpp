#include "chess_board.hpp"

namespace dc
{
chessBoard::chessBoard(std::vector<chessPiece> _pieces,
                       usize32 _board_size)
  :
  m_pieces(std::move(_pieces)),
  m_board_size(_board_size)
{}

chessBoard
chessBoard::default_chess_board() {

  std::vector<chessPiece> pieces;

  auto pawn = pieceData::pawn();

  for (int32 i = 0; i < 8; ++i) {
    pieces.push_back(chessPiece(pawn, point32{ 1,i }, true));
  }

  for (int32 i = 0; i < 8; ++i) {
    pieces.push_back(chessPiece(pawn, point32{ 6,i }, false));
  }
  return chessBoard(pieces, { 8,8 });
}

}
