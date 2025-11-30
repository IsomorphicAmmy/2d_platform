#include <raylib.h>
#include <stdio.h>

#include "world.h"
#include "player.h"

#define G_ACC 9.80665

int main()
{
	InitWindow(WIDTH, HEIGHT, "2D Platformer");
	struct Player p;
	InitPlayer(&p);
	p.pos = (Vector2) {0.0f, 0.0f};
	p.mass = 1;

	while (!WindowShouldClose())
	{
		float dt = GetFrameTime();
		Vector2 p_screen_pos = TransFromWorldToScreen(p.pos);
		int player_real_size = PLAYER_SIZE*WORLD_SIZE;
		p.acc.y = -G_ACC * p.mass;
		if ((int) p_screen_pos.y + player_real_size/2 >= HEIGHT)
		{
			p.vel.y = -p.vel.y * 0.8f;
		}

		BeginDrawing();
			ClearBackground(BLUE);
			DrawRectangle(0, 0, MeasureText(TextFormat("x = %f y = %f\nvx = %f vy = %f\nax = %f ay = %f"), 20) + 50, 20 * 3 + 25, (Color) {0, 0, 0, 100});
			DrawText(TextFormat("x = %f y = %f\nvx = %f vy = %f\nax = %f ay = %f", p.pos.x, p.pos.y, p.vel.x, p.vel.y, p.acc.x, p.acc.y), 10, 10, 20, WHITE);
			UpdatePlayer(&p, dt);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
