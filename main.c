#include "raylib.h"
#include <stdbool.h>

int main(void)
{
    SetTargetFPS(60);
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
    float square_pos_x = 400.0f;
    float square_pos_y = 400.0f;
    float circle_pos_x = 400.0f;
    float circle_pos_y = 400.0f;
    float speed = 800.0f;
    bool S = false;
    bool C = false;

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

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
        {
            S = true;

            DrawRectangle(square_pos_x, square_pos_y, 200, 200, bg);

            if (IsKeyDown(KEY_UP) && S == true)
            {
                square_pos_y -= speed * deltaTime;
            }
            if (IsKeyDown(KEY_DOWN) && S == true)
            {
                square_pos_y += speed * deltaTime;
            }
            if (IsKeyDown(KEY_RIGHT) && S == true)
            {
                square_pos_x += speed * deltaTime;
            }
            if (IsKeyDown(KEY_LEFT) && S == true)
            {
                square_pos_x -= speed * deltaTime;
            }
            
        }
        else
            S = false;

        if (IsKeyDown(KEY_C))
        {
            C = true;

            DrawCircle(circle_pos_x, circle_pos_y, 200, bg);

            if (IsKeyDown(KEY_UP) && C == true)
            {
                circle_pos_y -= speed * deltaTime;
            }
            if (IsKeyDown(KEY_DOWN) && C == true)
            {
                circle_pos_y += speed * deltaTime;
            }
            if (IsKeyDown(KEY_RIGHT) && C == true)
            {
                circle_pos_x += speed * deltaTime;
            }
            if (IsKeyDown(KEY_LEFT) && C == true)
            {
                circle_pos_x -= speed * deltaTime;
            }
            
        }
        else
            C = false;

        EndDrawing();
    }

    return 0;
}