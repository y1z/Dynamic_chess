#include "chess_board.hpp"
#include "drawing.hpp"
#include "util_funcs.hpp"
#include "../raylib/src/raymath.h"

namespace dc
{

using std::vector;

constexpr static uint32 DEFAULT_CELL_WIDTH = 50;
constexpr static uint32 DEFAULT_CELL_HEIGHT = 50;

chessBoard::chessBoard(vector<chessPiece> _pieces,
                       usize32 _column_and_row_count,
                       usize32 _cell_size,
                       const Color _starting_side_color,
                       const Color _opposite_side_color)
  :
  m_pieces(_pieces.begin(), _pieces.end()),
  m_column_and_row_count(_column_and_row_count),
  m_cell_size(_cell_size),
  m_starting_side_color(_starting_side_color),
  m_opposite_side_color(_opposite_side_color)
{
  m_area.x = 0.0f;
  m_area.y = 0.0f;
  m_area.width = static_cast<float>(m_cell_size.x * m_column_and_row_count.x);
  m_area.height = static_cast<float>(m_cell_size.y * m_column_and_row_count.y);
}

void
chessBoard::draw() const
{

  Rectangle rect = { 0 };
  rect.width = m_cell_size.x;
  rect.height = m_cell_size.y;

  dc::draw_chess_board(m_column_and_row_count.x,
                       m_column_and_row_count.y,
                       rect,
                       m_starting_side_color,
                       m_opposite_side_color);

  for (const auto& ele : m_pieces)
  {
    const auto str_view = ele.get_text_form();
    DrawText(str_view.data(),
             ele.m_position.x * m_cell_size.x,
             ele.m_position.y * m_cell_size.y,
             m_cell_size.x,
             ele.m_text_color);

  }

}

Rectangle
chessBoard::gen_rectangle_for_piece(size_t index) const
{
  const auto piece = m_pieces.at(index);
  const auto x_offset = piece.m_position.x * piece.m_piece_size.x;
  const auto y_offset =  piece.m_position.y * piece.m_piece_size.y;

  Rectangle result;
  result.x = static_cast<float>(x_offset);
  result.y = static_cast<float>(y_offset);
  result.width = static_cast<float>(piece.m_piece_size.x);
  result.height = static_cast<float>(piece.m_piece_size.y);
  return  result;

}

const chessPiece *
chessBoard::get_piece_ptr_at(const Vector2 position)
{

  for (size_t i = 0; i < m_pieces.size(); ++i)
  {

    if (is_piece_at(position, i))
    {
      return &m_pieces[i];
    }
  }

  return nullptr;
}

std::optional<Rectangle>
chessBoard::get_piece_rect_at(const Vector2 position)
{
  for (size_t i = 0; i < m_pieces.size(); ++i)
  {

    if (is_piece_at(position, i))
    {
      return gen_rectangle_for_piece(i);
    }
  }

  return std::nullopt;
}


chessBoard
chessBoard::default_chess_board(const std::optional<usize32> size_of_pieces)
{

  vector<chessPiece> pieces;

  const auto final_size_of_pieces = size_of_pieces.value_or(usize32{ DEFAULT_CELL_WIDTH,DEFAULT_CELL_HEIGHT });

  for (int32 i = 0; i < 8; ++i)
  {
    pieces.push_back(chessPiece::pawn(point32{ i,1 },
                     final_size_of_pieces,
                     false,
                     MAROON));
  }

  for (int32 i = 0; i < 8; ++i)
  {
    pieces.push_back(chessPiece::pawn(point32{ i,6 },
                     final_size_of_pieces,
                     true,
                     SKYBLUE));
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

  for (int32 i = 0; i < length; i++)
  {
    pieces.push_back(chessPiece(back_row.at(i).first,
                     point32{ i,0 },
                     final_size_of_pieces,
                     false,
                     back_row.at(i).second,
                     MAROON));
  }

  for (int32 i = 0; i < length; i++)
  {
    pieces.push_back(chessPiece(back_row.at(i).first,
                     point32{ i,7 },
                     final_size_of_pieces,
                     true,
                     back_row.at(i).second,
                     SKYBLUE));
  }

  const usize32 column_and_rows{ 8,8 };

  return chessBoard(pieces, column_and_rows, final_size_of_pieces);
}

bool
chessBoard::is_piece_at(const Vector2 position, const size_t index)
{
  const auto piece_rec = gen_rectangle_for_piece(index);
  if (CheckCollisionPointRec(position, piece_rec))
  {
    return true;
  }
  return false;
}


}

