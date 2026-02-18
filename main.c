#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    SetTargetFPS(60);

    struct Vector2 {
        float x;
        float y;
    };

    const int screenWidth = 1600;
    const int screenHeight = 1200;

    Color bg = WHITE;

    Vector2 sqaure1_pos;
    Vector2 sqaure2_pos;
    Vector2 direction;
    float speed = 800.0f;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "My Test Window");

    MaximizeWindow();
    if (IsWindowFullscreen() == false)
    {
        ToggleFullscreen();
    }

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        if (IsKeyPressed(KEY_F11))
        {
            ToggleFullscreen();
        }

        BeginDrawing();
        
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
        if (IsKeyDown(KEY_KP_1))
        {
            DrawRectangle(sqaure1_pos.x, sqaure1_pos.y, 200, 200, bg);

            if (IsKeyDown(KEY_UP) && (IsKeyDown(KEY_KP_1)) == true)
            {
                sqaure1_pos.y -= speed * deltaTime;
            }
            if (IsKeyDown(KEY_DOWN) && (IsKeyDown(KEY_KP_1)) == true)
            {
                sqaure1_pos.y += speed * deltaTime;
            }
            if (IsKeyDown(KEY_RIGHT) && (IsKeyDown(KEY_KP_1)) == true)
            {
                sqaure1_pos.x += speed * deltaTime;
            }
            if (IsKeyDown(KEY_LEFT) && (IsKeyDown(KEY_KP_1)) == true)
            {
                sqaure1_pos.x -= speed * deltaTime;
            }
            
        }

        if (IsKeyDown(KEY_KP_2))
        {
            DrawRectangle(sqaure2_pos.x, sqaure2_pos.y, 200, 200, bg);

            if (IsKeyDown(KEY_UP) && (IsKeyDown(KEY_KP_2)) == true)
            {
                sqaure2_pos.y -= speed * deltaTime;
            }
            if (IsKeyDown(KEY_DOWN) && (IsKeyDown(KEY_KP_2)) == true)
            {
                sqaure2_pos.y += speed * deltaTime;
            }
            if (IsKeyDown(KEY_RIGHT) && (IsKeyDown(KEY_KP_2)) == true)
            {
                sqaure2_pos.x += speed * deltaTime;
            }
            if (IsKeyDown(KEY_LEFT) && (IsKeyDown(KEY_KP_2)) == true)
            {
                sqaure2_pos.x -= speed * deltaTime;
            }
            
        }
        
        EndDrawing();
    }

    return 0;
}