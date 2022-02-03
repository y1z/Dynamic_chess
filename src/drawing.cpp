#include "drawing.hpp"
#include <cassert>

namespace dc {
void
draw_board_row(const int32 distance_between_cells,
               const uint32 how_many_cells_to_draw,
               const Rectangle starting_cell,
               const Color cell_color) {

  draw_board_row(static_cast<float>(distance_between_cells),
                 how_many_cells_to_draw,
                 starting_cell,
                 cell_color);
}

void
draw_board_row(const float distance_between_cells,
               const uint32 how_many_cells_to_draw,
               const Rectangle starting_cell,
               const Color cell_color) {

  assert(how_many_cells_to_draw > 0 || "need a minimum of 1 cells to draw");


  Rectangle board_cell = starting_cell;
  for (uint32 i = 0; i < how_many_cells_to_draw; ++i) {
    DrawRectangleRec(board_cell, cell_color);
    board_cell.x += distance_between_cells;
  }
}

void
draw_chess_board(const uint32 column_total,
                 const uint32 row_total,
                 Rectangle starting_cell,
                 const Color starting_side_color,
                 const Color opposite_side_color) {
  assert(row_total > 0 || "minimum value for height is 1");
  assert(column_total > 0 || "minimum value for width is 1");
  assert(starting_cell.width > 0.0f || "cannot have negative width cells");
  assert(starting_cell.height > 0.0f || "cannot have negative height cells");

  const float starting_x_position = starting_cell.x;
  for (uint32 i = 0; i < column_total; ++i) {
    if (i % 2 == 0) {
      draw_board_row(starting_cell.width * 2.0f, row_total / 2, starting_cell, starting_side_color);
      starting_cell.x += starting_cell.width;
      draw_board_row(starting_cell.width * 2.0f, row_total / 2, starting_cell, opposite_side_color);
    }
    else {
      draw_board_row(starting_cell.width * 2.0f, row_total / 2, starting_cell, opposite_side_color);
      starting_cell.x += starting_cell.width;
      draw_board_row(starting_cell.width * 2.0f, row_total / 2, starting_cell, starting_side_color);
    }

    starting_cell.x = starting_x_position;
    starting_cell.y += starting_cell.height;
  }



}

}



