#include "raylib.h"

//------------------------------------------------------------------------------------------
// [코드설명] 델타 타임 유무에 따른 속도 차이를 시각적으로 비교한다.
//           마우스 휠로 FPS를 조절하면, 델타 타임을 사용하는 빨간 원은 속도가 일정하고
//           프레임에 종속된 파란 원은 FPS에 따라 속도가 변한다.
//           R키로 두 원의 위치를 초기화할 수 있다.
//------------------------------------------------------------------------------------------

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;


    // WM_CREATE
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [core] example - delta time");

    int currentFps = 60;




    // 두 원의 위치를 저장
    Vector2 deltaCircle = { 0, (float)screenHeight / 3.0f };
    Vector2 frameCircle = { 0, (float)screenHeight * (2.0f / 3.0f) };




    // 두 원에 공통으로 적용되는 속도
    const float speed = 10.0f;
    const float circleRadius = 32.0f;




    SetTargetFPS(currentFps);
    //--------------------------------------------------------------------------------------










    // Main game loop = 윈플 사람들아, 이게 switch(umsg) {} 같은 역할임
    while (!WindowShouldClose()) // 창 닫기 버튼 또는 ESC 키 감지
    {




        // Update
        //----------------------------------------------------------------------------------
        // 윈플하는 사람들아, 이건 TIMER 업데이트랑 뭐 비슷한 거인 듯??

        // 마우스 휠을 기반으로 목표 FPS 조정
        float mouseWheel = GetMouseWheelMove();

        if (mouseWheel != 0)
        {
            currentFps += (int)mouseWheel;
            if (currentFps < 0) currentFps = 0;
            SetTargetFPS(currentFps);
        }

        // GetFrameTime()은 마지막 프레임을 그리는 데 걸린 시간을 초 단위로 반환 (보통 델타 타임이라고 부름)
        // 델타 타임을 사용해 FPS에 관계없이 원이 "일정한" 속도로 움직이는 것처럼 보이게 함

        // 비교를 위해 다른 원(60fps 기준)과 시각적으로 속도를 맞추려고
        // 임의의 값인 6.0을 곱함
        deltaCircle.x += GetFrameTime() * 6.0f * speed;

        // 이 원은 FPS에 따라 시각적으로 빠르거나 느리게 움직일 수 있음
        frameCircle.x += 0.1f * speed;

        // 원이 화면 밖으로 나가면 시작 지점으로 되돌림
        if (deltaCircle.x > screenWidth) deltaCircle.x = 0;
        if (frameCircle.x > screenWidth) frameCircle.x = 0;


        // 두 원의 위치를 초기화
        if (IsKeyPressed(KEY_R))
        {
            deltaCircle.x = 0;
            frameCircle.x = 0;
        }
        //----------------------------------------------------------------------------------







        // WM_PAINT
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);




        // 두 원을 화면에 그림
        DrawCircleV(deltaCircle, circleRadius, RED);
        DrawCircleV(frameCircle, circleRadius, BLUE);




        // 도움말 텍스트를 그림
        // 현재 목표 FPS에 따라 표시할 텍스트를 결정
        const char* fpsText = 0;
        
        if (currentFps <= 0)
            fpsText = TextFormat("FPS: unlimited (%i)", GetFPS());
        else 
            fpsText = TextFormat("FPS: %i (target: %i)", GetFPS(), currentFps);
        
        DrawText(fpsText, 10, 10, 20, DARKGRAY);
        DrawText(TextFormat("Frame time: %02.02f ms", GetFrameTime()), 10, 30, 20, DARKGRAY);
        DrawText("Use the scroll wheel to change the fps limit, r to reset", 10, 50, 20, DARKGRAY);




        // 원 위에 텍스트를 그림
        DrawText("FUNC: x += GetFrameTime()*speed", 10, 90, 20, RED);
        DrawText("FUNC: x += speed", 10, 240, 20, BLUE);




        EndDrawing();
        //----------------------------------------------------------------------------------
    }




    // WM_DESTROY
    //--------------------------------------------------------------------------------------
    CloseWindow();        // 창 및 OpenGL 컨텍스트를 닫음
    //--------------------------------------------------------------------------------------

    return 0;
}