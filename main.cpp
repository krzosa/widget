#include "raylib.h"

void ApplyTransparency();

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetWindowState(FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TOPMOST | FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_MOUSE_PASSTHROUGH);
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetWindowPosition(0, 0);

    SetTargetFPS(60);

    // ApplyTransparency();

    while (!WindowShouldClose())
    {

        BeginDrawing();

            ClearBackground({0, 0, 0, 0});

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}