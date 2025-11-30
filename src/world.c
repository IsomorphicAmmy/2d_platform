#include "world.h"

Vector2 TransFromWorldToScreen(Vector2 vec)
{
	Vector2 result;
	result.y = ((float) (WORLD_SIZE - vec.y)/(WORLD_SIZE*2))*HEIGHT;
	result.x = (vec.x*HEIGHT / WORLD_SIZE + WIDTH)/2;
	return result;
}
