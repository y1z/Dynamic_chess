#include "chess_board.hpp"
#include <optional>

namespace dc {

using std::vector;


constexpr static uint32 DEFAULT_CELL_WIDTH = 50;
constexpr static uint32 DEFAULT_CELL_HEIGHT = 50;


chessBoard::chessBoard(vector<chessPiece> _pieces,
                       usize32 _board_size)
  :chessBoard(std::move(_pieces),
              _board_size,
              { DEFAULT_CELL_WIDTH, DEFAULT_CELL_HEIGHT})
  {}

chessBoard::chessBoard(std::vector<chessPiece>&& _pieces,
                       usize32 _board_size,
                       usize32 _cell_size)
  :
  m_pieces(std::forward<std::vector<chessPiece> >(_pieces)),
  m_board_size(_board_size),
  m_cell_board_size(_cell_size)
{}

void
chessBoard::draw() const {

  for (const auto& ele : m_pieces) {
    const auto str_view = ele.get_text_form();
    DrawText(str_view.data(),
             ele.m_position.x * m_cell_board_size.x,
             ele.m_position.y * m_cell_board_size.y,
             m_cell_board_size.x,
             RED);
  }

}

chessBoard
chessBoard::default_chess_board(const std::optional<usize32> size_of_pieces) {

  vector<chessPiece> pieces;

  const auto pawn = pieceData::pawn();

  const auto final_size_of_pieces = size_of_pieces.value_or(usize32{ DEFAULT_CELL_WIDTH,DEFAULT_CELL_HEIGHT });

  for (int32 i = 0; i < 8; ++i) {
    pieces.push_back(chessPiece::pawn(point32{ i,1 },
                     final_size_of_pieces,
                     false));
  }

  for (int32 i = 0; i < 8; ++i) {
    pieces.push_back(chessPiece::pawn(point32{ i,6 },
                     final_size_of_pieces,
                     true));
  }

  const vector<std::pair< pieceData, const char*> > back_row =
  {
   { pieceData::tower(),"t"},
   { pieceData::knight(),"n"},
   { pieceData::bishop(), "b" },
   { pieceData::queen(), "Q" },

   { pieceData::king(), "K" },
   { pieceData::bishop(),"b" },
   { pieceData::knight(),"n" },
   { pieceData::tower(), "t" },
  };

  const auto length = back_row.size();

  for (int32 i = 0; i < length; i++) {
    pieces.push_back(chessPiece(back_row.at(i).first,
                     point32{ i,0 },
                     final_size_of_pieces,
                     true,
                     back_row.at(i).second));
  }

  for (int32 i = 0; i < length; i++) {
    pieces.push_back(chessPiece(back_row.at(i).first,
                     point32{ i,7 },
                     final_size_of_pieces,
                     false,
                     back_row.at(i).second));
  }


  return chessBoard(pieces, { 8,8 });
}

}
