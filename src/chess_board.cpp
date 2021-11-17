#include "chess_board.hpp"

namespace dc {

using std::vector;

chessBoard::chessBoard(vector<chessPiece> _pieces,
                       usize32 _board_size)
  :
  m_pieces(move(_pieces)),
  m_board_size(_board_size) {}

void
chessBoard::draw() const {

  for (const auto& ele : m_pieces) {
    const auto str_view = ele.get_text_form();
    DrawText(str_view.data(),
             ele.m_position.x * 100,
             ele.m_position.y * 100,
             48,
             RED);
  }

}

chessBoard
chessBoard::default_chess_board() {

  vector<chessPiece> pieces;

  const auto pawn = pieceData::pawn();

  for (int32 i = 0; i < 8; ++i) {
    pieces.push_back(chessPiece(pawn,
                     point32{ 1,i },
                     true));
  }

  for (int32 i = 0; i < 8; ++i) {
    pieces.push_back(chessPiece(pawn,
                     point32{ 6,i },
                     false));
  }

  const vector<pieceData> back_row =
  {
    pieceData::tower(),
    pieceData::knight(),
    pieceData::bishop(),
    pieceData::queen(),

    pieceData::king(),
    pieceData::bishop(),
    pieceData::knight(),
    pieceData::tower(),
  };

  const auto length = back_row.size() - 1;

  for (int32 i = 0; i < length; i++) {
    pieces.push_back(chessPiece(back_row.at(i),
                     point32{ 0,i },
                     true));
  }

  for (int32 i = 0; i < length; i++) {
    pieces.push_back(chessPiece(back_row.at(i),
                     point32{ 7,i },
                     false));
  }




  return chessBoard(pieces, { 8,8 });
}

}
