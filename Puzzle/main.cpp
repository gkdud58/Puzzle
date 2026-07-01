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
    const int screenHeight = 400;
    //const int screenWidth = GetMonitorWidth(0);
    //const int screenHeight = GetMonitorHeight(0);


    // 윈도우 창 띄우기 ---------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    //ToggleFullscreen();
    //--------------------------------------------------------------------------------------


    // Timer??
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second



    // Main game loop
    while (!WindowShouldClose())    // esc키 누르면 게임 종료
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------






		// WM_PAINT
        //----------------------------------------------------------------------------------
        BeginDrawing(); // [필수] 그리기 시작한다~ 알리는 함수

        ClearBackground(BLACK); // 배경 색 채워주는 함수

        // DrawText(글자, 출력 X축, 출력 Y축, 글자크기, 글자색)
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);


        EndDrawing(); // [필수] 더블 버퍼링 자동으로 해주는듯
        //----------------------------------------------------------------------------------
    }





	// WM_DESTROY
    //--------------------------------------------------------------------------------------
    CloseWindow();        // [필수] 나 이제 창 닫을게~ 알리는 함수 -> 이거 안 넣으면, 창 닫아도 작업관리자에 계속 남아있음
    //--------------------------------------------------------------------------------------

    return 0;
}