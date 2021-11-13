#include "program_flow.hpp"
#include "drawing.hpp"

#include "../raylib/src/raylib.h"

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

namespace dc {

int run() {

  // Initialization
  //--------------------------------------------------------------------------------------
  InitWindow(g_screenWidth, g_screenHeight, "raylib [core] example - basic screen manager");

  GameState current_state = static_cast<GameState>(GameState::INIT);

  Rectangle board_cell = { 0 };
  board_cell.width = static_cast<float>(g_cell_width);
  board_cell.height = static_cast<float>(g_cell_height);

  // TODO: Initialize all required variables and load all required data here!

  int framesCounter = 0;          // Useful to count frames

  ::SetTargetFPS(60);               // Set desired framerate (frames-per-second)
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    switch (current_state) {
    case GameState::INIT:
    {
      //DrawRectangle(0, 0, g_screenWidth, g_screenHeight, CLITERAL(Color){255, 255, 255, 255 });

      draw_chess_board(g_screenWidth, g_screenHeight, board_cell);

    }
    default: break;
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
