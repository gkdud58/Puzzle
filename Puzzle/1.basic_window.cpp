/*
===== 윈도우프로그래밍이랑 비교하기 =====
InitWindow();        // WM_CREATE 대신
BeginDrawing();      // WM_PAINT 대신
IsKeyPressed();      // WM_KEYDOWN 대신
CloseWindow();       // WM_DESTROY 대신
*/



#include "raylib.h"




int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

	// WM_CREATE
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------






    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------






		// WM_PAINT
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // DrawText(글자, 출력 X축, 출력 Y축, 글자크기, 글자색)
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);


        EndDrawing(); // 더블 버퍼링 자동으로 해주는듯?
        //----------------------------------------------------------------------------------
    }





	// WM_DESTROY
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}