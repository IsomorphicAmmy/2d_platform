#include "world.h"
#include "player.h"

void InitPlayer(struct Player *self)
{
	memset(self, 0, sizeof(struct Player));
}

void DrawPlayer(struct Player self)
{
	Vector2 screen_pos = TransFromWorldToScreen(self.pos);
	DrawRectangle((int) screen_pos.x - PLAYER_SIZE*WORLD_SIZE/2, (int) screen_pos.y - PLAYER_SIZE*WORLD_SIZE/2, PLAYER_SIZE*WORLD_SIZE, PLAYER_SIZE*WORLD_SIZE, YELLOW);
}

void UpdatePlayer(struct Player *self, float dt)
{
	self->vel.x += self->acc.x * dt;
	self->vel.y += self->acc.y * dt;
	self->pos.x += self->vel.x * dt;
	self->pos.y += self->vel.y * dt;

	DrawPlayer(*self);
}
