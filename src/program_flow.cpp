#include "program_flow.hpp"

#include "../raylib/src/raylib.h"

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

constexpr const int g_screenWidth = 1280;
constexpr const int g_screenHeight = 720;
constexpr const int g_cell_width = g_screenWidth / 8;
constexpr const int g_cell_height = g_screenHeight / 8;

namespace dc {

int run() {

  // Initialization
  //--------------------------------------------------------------------------------------
  InitWindow(g_screenWidth, g_screenHeight, "raylib [core] example - basic screen manager");

  GameScreen currentScreen = static_cast<GameScreen>(TITLE);

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

    switch (currentScreen) {
    case LOGO:
    {
        // TODO: Draw LOGO screen here!
      DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
      DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);

    } break;
    case TITLE:
    {
        // TODO: Draw TITLE screen here!
      DrawRectangle(0, 0, g_screenWidth, g_screenHeight, CLITERAL(Color){255, 255, 255, 255 });
      const Rectangle starting_point = board_cell;
      DrawRectangleRec(board_cell, DARKGRAY);

      for (int i = 0; i < (g_screenWidth / g_cell_width); ++i) {

        board_cell.x += board_cell.width * 2;
        DrawRectangleRec(board_cell, DARKGRAY);

      }

      board_cell = starting_point;

      DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
      DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

    } break;
    case GAMEPLAY:
    {
        // TODO: Draw GAMEPLAY screen here!
      DrawRectangle(0, 0, g_screenWidth, g_screenHeight, PURPLE);
      DrawText("GAMEPLAY SCREEN", 20, 20, 40, GOLD);
      DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, GOLD);

    } break;
    case ENDING:
    {
        // TODO: Draw ENDING screen here!
      DrawRectangle(0, 0, g_screenWidth, g_screenHeight, BLUE);
      DrawText("ENDING SCREEN", 20, 20, 40, VIOLET);
      DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, VIOLET);

    } break;
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
