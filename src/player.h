#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include <raylib.h>

#define PLAYER_SIZE 5

struct Player
{
	Vector2 pos;
	Vector2 vel;
	Vector2 acc;
	float mass;
};

void InitPlayer(struct Player *self);
void DrawPlayer(struct Player self);
void UpdatePlayer(struct Player *self, float dt);

#endif
