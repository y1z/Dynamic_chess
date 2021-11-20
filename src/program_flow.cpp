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

constexpr const int g_screenWidth = 1280;
constexpr const int g_screenHeight = 720;
constexpr const int g_cell_width = g_screenWidth / 8;
constexpr const int g_cell_height = g_screenHeight / 8;

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

// Initialization
//--------------------------------------------------------------------------------------
  InitWindow(g_screenWidth, g_screenHeight, "dynamic chess");

  GameState current_state = static_cast<GameState>(GameState::INIT);

  Rectangle board_cell = { 0 };
  board_cell.width = static_cast<float>(g_cell_width);
  board_cell.height = static_cast<float>(g_cell_height);

  chessBoard board = chessBoard::default_chess_board();

  // TODO: Initialize all required variables and load all required data here!

  ::SetTargetFPS(60);               // Set desired framerate (frames-per-second)
  //--------------------------------------------------------------------------------------

  // Main game loop

  bool is_default_color = true;
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();
    const auto mouse_pos = GetMousePosition();
    switch (current_state)
    {
    case GameState::INIT:
    {

      Rectangle test_rect = { 0.0f,0.0f,400.0f,400.0f };
      //DrawRectangle(0, 0, g_screenWidth, g_screenHeight, CLITERAL(Color){255, 255, 255, 255 });
      //draw_chess_board(g_screenWidth, g_screenHeight, board_cell);
      if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse_pos, test_rect))
      {

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

    }
    default: break;
    }

    ClearBackground(DARKBROWN);

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
