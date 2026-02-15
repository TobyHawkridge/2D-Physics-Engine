#include "raylib.h"
#include <stdbool.h>

int main(void)
{
    const int screenWidth = 1600;
    const int screenHeight = 1200;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "My Test Window");

    MaximizeWindow();
    if (IsWindowFullscreen() == false)
    {
        ToggleFullscreen();
    }

    Color bg = WHITE;
    int square_pos_x = 400;
    int square_pos_y = 400;
    int circle_pos_x = 400;
    int circle_pos_y = 400;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F11))
        {
            ToggleFullscreen();
        }

        BeginDrawing();
        // CHANGING THE BACKGROUND
        if (IsKeyDown(KEY_BACKSPACE) == true)
        {
            bg = BLACK;
            ClearBackground(WHITE);
        }
        if (IsKeyUp(KEY_BACKSPACE) == true)
        {
            bg = WHITE;
            ClearBackground(BLACK);
        }
        
        // DRAWING A SQUARE
        if (IsKeyDown(KEY_S))
            DrawRectangle(square_pos_x, square_pos_y, 200, 200, bg);
        if (IsKeyDown(KEY_C))
            DrawCircle(circle_pos_x, circle_pos_y, 200, bg);

        EndDrawing();
    }

    return 0;
}