#pragma once
#include "util_type.hpp"

#include "../raylib/src/raylib.h"


namespace dc {

/**
* @param[in] Cell_width_distance the distance between cells
* @param[in] staring_cell Where the cell starts
* @param[in] how_many_cells_to_draw The amount of cells to draw one after another

*/
void draw_board_row(const int cell_width_distance,
                    const unsigned int how_many_cells_to_draw,
                    const Rectangle starting_cell,
                    const Color cell_color = DARKGRAY);

}
