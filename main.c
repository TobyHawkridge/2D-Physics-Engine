#include "raylib.h"
#include <stdbool.h>

int main(void)
{
    const int screenWidth = 1600;
    const int screenHeight = 1200;
    bool isWhite = false;

    InitWindow(screenWidth, screenHeight, "My Test Window");

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