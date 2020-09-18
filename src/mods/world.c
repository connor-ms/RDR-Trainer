#include "mods.h"

int world_weather = 0;

void World_SetWeather()
{
	SET_WEATHER(world_weather, 0);
}