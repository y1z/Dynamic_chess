#include "drawing.hpp"
#include <cassert>

namespace dc {
void
draw_board_row(const int32 distance_between_cells,
               const uint32 how_many_cells_to_draw,
               const Rectangle starting_cell,
               const Color cell_color) {

  assert(how_many_cells_to_draw > 0 || "need a minimum of 1 cells to draw");


  Rectangle board_cell = starting_cell;
  for (uint32 i = 0; i < how_many_cells_to_draw; ++i) {
    DrawRectangleRec(board_cell, cell_color);
    board_cell.x += static_cast<float>(distance_between_cells);
  }
}

void
draw_chess_board(const uint32 board_width,
                 const uint32 board_height,
                 Rectangle starting_cell,
                 const Color first_color,
                 const Color second_color) {
  assert(board_height > 0 || "minimum value for height is 1");
  assert(board_width > 0 || "minimum value for width is 1");
  assert(starting_cell.width > 0.0f || "cannot have negative width cells");
  assert(starting_cell.height > 0.0f || "cannot have negative height cells");

  const uint32 total_rows = board_width / starting_cell.width;
  const uint32 total_colums = board_height / starting_cell.height;
  const float starting_x_position = starting_cell.x;
  for (uint32 i = 0; i < total_colums; ++i) {
    if (i % 2 == 0) {
      draw_board_row(starting_cell.width * 2, total_rows / 2, starting_cell, first_color);
      starting_cell.x += starting_cell.width;
      draw_board_row(starting_cell.width * 2, total_rows / 2, starting_cell, second_color);
    }
    else {
      draw_board_row(starting_cell.width * 2, total_rows / 2, starting_cell, second_color);
      starting_cell.x += starting_cell.width;
      draw_board_row(starting_cell.width * 2, total_rows / 2, starting_cell, first_color);
    }

    starting_cell.x = starting_x_position;
    starting_cell.y += starting_cell.height;
  }



}

}



