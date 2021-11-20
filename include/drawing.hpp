#pragma once
#include "util_type.hpp"

#include "../raylib/src/raylib.h"


namespace dc {

/**
* @param[in] distance_between_cells the distance between cells
* @param[in] staring_cell Where the cell starts
* @param[in] how_many_cells_to_draw The amount of cells to draw one after another

*/
void draw_board_row(const int32 distance_between_cells,
                    const uint32 how_many_cells_to_draw,
                    const Rectangle starting_cell,
                    const Color cell_color = DARKGRAY);


/**
* The board is drawn from the `Top-left` to the `bottom right`
* @param[in] board_width The width of the board
* @param[in] board_height The height of the board
* @param[in] starting_cell The first cell in the board controls the width and height of all
*            other cells
*/
void draw_chess_board(const uint32 board_width,
                      const uint32 board_height,
                      Rectangle starting_cell,
                      const Color starting_side_color = RAYWHITE,
                      const Color opposite_side_color = DARKBLUE);

}
