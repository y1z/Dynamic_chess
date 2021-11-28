#include "program_flow.hpp"
#include "drawing.hpp"
#include "chess_board.hpp"

#include "../raylib/src/raylib.h"
#include <iostream>

enum class GameState
{
  INIT,
  GAME,
  END
};

constexpr const int g_starting_screen_width = 1920;
constexpr const int g_starting_screen_height = 1080;
constexpr const int g_cell_width = g_starting_screen_width / (8 * 3);
constexpr const int g_cell_height = g_starting_screen_height / (8 * 3);

namespace dc
{
using std::cout;

void print_rec(const Rectangle& rec)
{
  cout << "x = " << rec.x <<
    "\ny = " << rec.y <<
    "\nwidth = " << rec.width <<
    "\nheight = " << rec.height << '\n';
}

int run()
{
  SetWindowState(FLAG_MSAA_4X_HINT);
  InitWindow(g_starting_screen_width, g_starting_screen_height, "dynamic chess");
  SetWindowState(FLAG_WINDOW_RESIZABLE);

//  SetWindowSize();

  GameState current_state = GameState::GAME;
  Rectangle board_cell = { 0 };
  board_cell.width = static_cast<float>(g_cell_width);
  board_cell.height = static_cast<float>(g_cell_height);

  chessBoard board = chessBoard::default_chess_board(usize32{ g_cell_width, g_cell_height});


  ::SetTargetFPS(60);               // Set desired framerate (frames-per-second)
  //--------------------------------------------------------------------------------------
  // Main game loop
  size32 current_size_of_screen{ g_starting_screen_width, g_starting_screen_height };
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {

    size32 size_of_screen{ 0 };
    size_of_screen.x = GetScreenWidth();
    size_of_screen.y = GetScreenHeight();
    const auto mouse_pos = GetMousePosition();

    std::optional<Rectangle> mouse_cursor_rect = std::nullopt;
    switch (current_state)
    {
    case GameState::GAME:
    {
      mouse_cursor_rect = board.get_piece_rect_at(mouse_pos);
      if (size_of_screen.x != current_size_of_screen.x && size_of_screen.y != current_size_of_screen.x)
      {
        current_size_of_screen = size_of_screen;
      }

    }
    break;
    default: break;
    }
    // Draw
    //----------------------------------------------------------------------------------

    if (IsKeyPressed(KEY_P))
    {
      board.print_board_cells();
    }
    BeginDrawing();


    ClearBackground(CLITERAL(Color) {230,230,230,255});

    board.draw();
    if (mouse_cursor_rect.has_value() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      if (auto* ptr = board.get_piece_ptr_at(mouse_pos))
      {
        auto piece_data = ptr->get_piece_data();
        for (const auto& elem : piece_data.how_piece_moves)
        {
          std::cout << "\nx = " << elem.x << "\ny = " << elem.y << '\n';
        }
        std::cout << "\ndone\n\n";
      }
      const auto mouse_rect = mouse_cursor_rect.value();
      DrawRectangleRec(mouse_rect, CLITERAL(Color){ 253, 249, 0, 255 / 2 });
    }


    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------

  // TODO: Unload all loaded data (textures, fonts, audio) here!

  CloseWindow();        // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}

}
