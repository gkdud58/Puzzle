#include "raylib.h"

int main(void) {
	const int screenX = 800;
	const int screenY = 650;
	const int Cir_X = 300;
	const int Cir_Y = 225;

	// 윈도우창 띄우기
	InitWindow(screenX, screenY, "window screen");

	while (!WindowShouldClose())
	{
		// Paint
		BeginDrawing(); 

		DrawCircle(Cir_X, Cir_Y, 30, RED);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}