#include "mods.h"

#include "../menu_backend.h"
#include "../util.h"

char *net_player_names[17];
int   net_selected_player = 1;
int   net_spoof_prestige  = 0;
int   net_spoof_level     = 1;

bool spectating = false;

// tp to posse leader: UI_SENDEVENT(RequestPosseTeleport)

bool IsSlotValid(int slot)
{
	if (IS_SLOT_VALID(slot))
	{
		return true;
	}
	else
	{
		_PRINT_CHAT("<red>Error: invalid player", 0, 0, 0, 0, 0, 0);
		print("<red>Error: invalid player", 2000);

		return false;
	}
}

const char *GetSlotColor(int slot)
{
	char temp[23] = "MPPlayerNameColored_";
	
	straddi_s(temp, slot);

	return UI_GET_STRING(temp);
}

void Net_FixServer()
{
	Iterator iterator = CREATE_OBJECT_ITERATOR(FIND_NAMED_LAYOUT("playerlayout"));

	ITERATE_ON_OBJECT_TYPE(iterator, 15);

	START_OBJECT_ITERATOR(iterator);
	
	int matches = GET_NUM_ITERATOR_MATCHES(iterator);

	char temp[50];

	stradd_s(temp, "Found ");
	straddi_s(temp, matches);
	stradd_s(temp, " matches.\nDeleting...");

	print(temp, 2000);

	for (int i = 0; i < matches; i++)
	{
		int current = OBJECT_ITERATOR_CURRENT(iterator);

		if (current != self)
		{
			DESTROY_ACTOR(current);
		}

		OBJECT_ITERATOR_NEXT(iterator);
	}

	DESTROY_ITERATOR(iterator);

	DESTROY_LAYOUT_OBJECTS(FIND_NAMED_LAYOUT("netlayout"));

	WAIT(2000);
	print("Deleted?", 2000);
}

void Net_RefreshPlayerlist()
{
	for (int i = 0; i < 15; i++)
	{
		if (IS_SLOT_VALID(i))
			net_player_names[i] = GET_SLOT_NAME(i);
		else
			net_player_names[i] = "invalid";
	}
}

void Net_TeleportToPlayer()
{
	if (!IsSlotValid(net_selected_player))
		return;

	vector3 pos;
	GET_SLOT_POSITION(net_selected_player, &pos);

	TELEPORT_ACTOR(self, &pos, true, true, true);
}

void Net_TPToMe()
{
	if (!IsSlotValid(net_selected_player))
		return;

	Object player = GET_OBJECT_FROM_ACTOR(GET_SLOT_ACTOR(net_selected_player));
	vector3 pos;
	GET_POSITION(self, &pos);

	NET_REQUEST_OBJECT(player);

	SET_OBJECT_POSITION(player, pos);
}

void Net_ExplodePlayer()
{
	if (!IsSlotValid(net_selected_player))
		return;

	vector3 pos, damage;
	GET_SLOT_POSITION(net_selected_player, &pos);

	damage.x = 1.0f;
	damage.y = 1.0f;
	damage.z = 1.0f;

	_CREATE_EXPLOSION(&pos, EXPLOSION_ExplosionLarge, true, &damage, true);

	char temp[100];

	stradd_s(temp, "x: ");
	straddi_s(temp, pos.x);
	stradd_s(temp, " y: ");
	straddi_s(temp, pos.y);
	stradd_s(temp, " z: ");
	straddi_s(temp, pos.z);

	print(temp, 2000);
}

void Net_SpectatePlayer()
{
	if (!IsSlotValid(net_selected_player))
		return;

	spectating = true;

	vector3 pos;
	GET_SLOT_POSITION(net_selected_player, &pos);

	vector3 oldpos;
	GET_POSITION(self, &oldpos);

	TELEPORT_ACTOR(self, &pos, 1, 1, 1);

	WAIT(500);

//	STREAMING_LOAD_BOUNDS(pos.x, pos.y, pos.z, 10.0f, 0);

	SET_CAMERA_FOLLOW_ACTOR(GET_SLOT_ACTOR(net_selected_player));

	TELEPORT_ACTOR(self, &oldpos, 1, 1, 1);
	//SET_PLAYER_CONTROL(0, 0, 1, 1);
}

void Net_KillPlayersHorse()
{
	if (!IsSlotValid(net_selected_player))
		return;

	KILL_ACTOR(GET_ACTORS_HORSE(GET_SLOT_ACTOR(net_selected_player)));
}

void Net_Loop()
{
	if (spectating)
	{
		char msg[255];

		stradd_s(msg, "Spectating ");
		stradd_s(msg, GetSlotColor(net_selected_player));

		stradd_s(msg, "</0x> \nPress <cancel> to stop spectating. -- ");

		straddi_s(msg, STREAMING_IS_WORLD_LOADED());

		print(msg, 200);

		if (IsButtonPressed(BUTTON_B))
		{
			SET_CAMERA_FOLLOW_ACTOR(self);
			spectating = false;
		}
	}
}

void Net_SpoofLevel()
{
	UNK_0x50C18480("Rank", (net_spoof_prestige * 50) + net_spoof_level);
}