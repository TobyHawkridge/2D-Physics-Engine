#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    SetTargetFPS(60);

    const int screenWidth = 1600;
    const int screenHeight = 1200;

    Color bg = WHITE;

    Vector2 square1_pos = { 100.0f, 100.0f };
    Vector2 square2_pos = { 400.0f, 400.0f };
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
        
        if (IsKeyDown(KEY_ONE))
        {
            DrawRectangle(square1_pos.x, square1_pos.y, 200, 200, bg);

            if (IsKeyDown(KEY_UP)) direction.y = -1.0f;
            if (IsKeyDown(KEY_DOWN)) direction.y = 1.0f;
            if (IsKeyDown(KEY_RIGHT)) direction.x = 1.0f;
            if (IsKeyDown(KEY_LEFT)) direction.x = -1.0f;

            if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
            {
                square1_pos.y += direction.y * speed * deltaTime;
            }
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT))
            {
                square1_pos.x += direction.x * speed * deltaTime;
            }
        }

        if (IsKeyDown(KEY_TWO))
        {
            DrawRectangle(square2_pos.x, square2_pos.y, 200, 200, bg);

            if (IsKeyDown(KEY_UP)) direction.y = -1.0f;
            if (IsKeyDown(KEY_DOWN)) direction.y = 1.0f;
            if (IsKeyDown(KEY_RIGHT)) direction.x = 1.0f;
            if (IsKeyDown(KEY_LEFT)) direction.x = -1.0f;

            if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
            {
                square2_pos.y += direction.y * speed * deltaTime;
            }
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT))
            {
                square2_pos.x += direction.x * speed * deltaTime;
            }
        }
        EndDrawing();
    }
    return 0;
}