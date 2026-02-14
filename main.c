#include "raylib.h"
#include <stdbool.h>

int main(void)
{
    const int screenWidth = 1600;
    const int screenHeight = 1200;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "My Test Window");

    MaximizeWindow();

    bool isWhite = false;

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_SPACE))
        {
            isWhite = true;
        }

        BeginDrawing();

        if (isWhite == true)
        {
            ClearBackground(WHITE);
        }
        else
        {
            ClearBackground(BLACK);
        }
        
        EndDrawing();
    }

    return 0;

}