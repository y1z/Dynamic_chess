#include "drawing.hpp"
#include <cassert>

namespace dc {
void
draw_board_row(const int cell_width_distance, const unsigned int how_many_cells_to_draw, Rectangle starting_cell) {

  assert(how_many_cells_to_draw > 0 || "need a minimum of 1 cells to draw");


  Rectangle board_cell = starting_cell;
  for (unsigned int i = 0; i < how_many_cells_to_draw; ++i) {
    DrawRectangleRec(board_cell, DARKGRAY);
    board_cell.x += static_cast<float>(cell_width_distance);
  }
}

}
