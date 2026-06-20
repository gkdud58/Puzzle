#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    

    InitWindow(screenWidth, screenHeight, "raylib [core] example - input keys");



    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };



    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
            ballPosition.x += 2.0f;

        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
            ballPosition.x -= 2.0f;

        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
            ballPosition.y -= 2.0f;

        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
            ballPosition.y += 2.0f;
        //----------------------------------------------------------------------------------






        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

		// 원만들기 [ 원 - DrawCircleV(), 사각형 - DrawRectangleV(), 삼각형 - DrawTriangle() ]
        DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }



    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}