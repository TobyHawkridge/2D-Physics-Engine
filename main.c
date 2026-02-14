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

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F11))
        {
            ToggleFullscreen();
        }

        BeginDrawing();
        
        if (IsKeyDown(KEY_SPACE) == true)
        {
            ClearBackground(WHITE);
        }
        if (IsKeyUp(KEY_SPACE) == true)
        {
            ClearBackground(BLACK);
        }
        
        EndDrawing();
    }

    return 0;

}