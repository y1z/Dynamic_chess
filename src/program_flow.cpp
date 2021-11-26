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
constexpr const int g_cell_width = g_starting_screen_width / 8;
constexpr const int g_cell_height = g_starting_screen_height / 8;

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

  chessBoard board = chessBoard::default_chess_board();

  // TODO: Initialize all required variables and load all required data here!

  ::SetTargetFPS(60);               // Set desired framerate (frames-per-second)
  //--------------------------------------------------------------------------------------

  // Main game loop

  bool is_default_color = true;
  size32 current_size_of_screen{ g_starting_screen_width, g_starting_screen_height };
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();


    ClearBackground(CLITERAL(Color) {230,230,230,255});
    size32 size_of_screen{ 0 };
    size_of_screen.x = GetScreenWidth();
    size_of_screen.y = GetScreenHeight();
    const auto mouse_pos = GetMousePosition();
    switch (current_state)
    {
    case GameState::GAME:
    {
      const auto piece_ref = board.get_piece_ref_at(mouse_pos);
      if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && piece_ref.has_value())
      {
        const auto& piece = piece_ref.value();
        if (is_default_color)
        {
          board.m_opposite_side_color = BLUE;
        }
        else
        {
          board.m_opposite_side_color = BLACK;
        }
        is_default_color = !is_default_color;

      }

      if (size_of_screen.x != current_size_of_screen.x && size_of_screen.y != current_size_of_screen.x)
      {
        current_size_of_screen = size_of_screen;
      }

    }
    break;
    default: break;
    }


    board.draw();


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
