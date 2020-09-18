#include "mods.h"

bool weapon_allgold = false;
bool weapon_infammo = false;

void Weapon_ToggleAllGold()
{
	ToggleBool(weapon_allgold);

	for (int i = 0; i <= 37; i++)
	{
		SET_WEAPON_GOLD(self, i, weapon_allgold);
	}
}

void Weapon_ToggleInfAmmo()
{
	ToggleBool(weapon_infammo);

	for (int i = 0; i <= 37; i++)
	{
		_SET_ACTOR_INFINITE_AMMO(self, i, weapon_infammo);
	}
}

void Weapon_GiveAll()
{
	for (int i = 0; i <= 37; i++)
	{
		GIVE_WEAPON_TO_ACTOR(self, i, 1, 1, 1);
	}

	HUD_CLEAR_HELP_QUEUE();
}