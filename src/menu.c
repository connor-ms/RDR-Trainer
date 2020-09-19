#include "menu_backend.h"
#include "menu.h"

#include "mods/mods.h"

#include "constants.h"
#include "natives.h"
#include "common.h"
#include "intrinsics.h"

#pragma region Scrollables
char *teleport_locations[] =
{
	"Agave Viejo",
	"Armadillo",
	"Beecher's Hope",
	"Benedict Point",
	"Blackwater",
	"Casa Madrugada",
	"Chuparosa ",
	"Cochinay",
	"Coot's Chapel",
	"El Matadero",
	"El Presidio",
	"Escalera",
	"Fort Mercer",
	"Gaptooth Breach",
	"Lake Don Julio",
	"Las Hermanas",
	"Manzanita Post",
	"McFarlane's Ranch",
	"Nosalida",
	"Pacific Union Camp",
	"Plainview",
	"Rathskeller Fork",
	"Ridgewood Farm",
	"Serendipity's Wreck",
	"Thieve's Landing",
	"Tumbleweed",
	"Tesoro Azul",
	"Torquemada",
	"Twin Rocks",
	null
};

char *teleport_direction[] =
{
	"Forward",
	"Back",
	"Up",
	"Down",
	null
};

char *weather[] =
{
	"Clear",
	"Fair",
	"Cloudy",
	"Rainy",
	"Stormy",
	"Snowy",
	null
};

char *vehicles[] =
{
	"Stagecoach",
	"Stagecoach002",
	"Stagecoach003",
	"Stagecoach004",
	"dlc_Vehicle01x",
	"StagecoachGatling01",
	"Cart01",
	"Cart02",
	"Cart003",
	"Cart004",
	"Cart005",
	"Cart006",
	"Canoe01",
	"Raft02",
	"Raft03",
	"Raft01",
	"Truck01",
	"Car01",
	"Wagon04",
	"Wagon05",
	"WagonPrison01",
	"WagonGatling01",
	"Wagon02",
	"Chuckwagon",
	"Chuckwagon02",
	"Coach01",
	null
};

char *animals[] =
{
	"Horse01",
	"Horse02",
	"Horse03",
	"Horse04",
	"Horse05",
	"Horse06",
	"Horse07",
	"Horse08",
	"Horse09",
	"Horse10",
	"Horse11",
	"Horse12",
	"Horse13",
	"Horse14",
	"Horse15",
	"Horse16",
	"Horse17",
	"Horse18",
	"HorseMale01",
	"SaddleHorse01",
	"HorseMangy01",
	"HorseMangy02",
	"HorseMangy03",
	"HorseDead01",
	"MEX_Mule01",
	"MEX_Mule02",
	"MEX_Mule03",
	"MEX_Mule04",
	"Buffalo",
	"Buffalo04",
	"Bull04",
	"Bull05",
	"Cow",
	"Cow01",
	"Cow02",
	"Cow03",
	"Bull",
	"Bull01",
	"Bull02",
	"Chicken",
	"Chicken01",
	"Chicken02",
	"Rooster",
	"Rooster01",
	"Pig",
	"Pig01",
	"Pig03",
	"Sheep",
	"Sheep01",
	"Sheep03",
	"Goat01",
	"Goat02",
	"Goat03",
	"Goat",
	"Dog",
	"Dog01",
	"Dog02",
	"CollieDog",
	"CollieDog01",
	"CollieDog02",
	"CollieDog03",
	"GermanShepDog",
	"GermanShepDog01",
	"GermanShepDog02",
	"GermanShepDog03",
	"LabDog",
	"LabDog01",
	"LabDog02",
	"LabDog03",
	"NOR_HuskyDog",
	"NOR_HuskyDog01",
	"NOR_HuskyDog02",
	"NOR_HuskyDog03",
	"Coyote",
	"Coyote01",
	"Coyote03",
	"Coyote04",
	"Fox",
	"Fox01",
	"Fox02",
	"Fox03",
	"Snake",
	"Snake01",
	"Snake02",
	"FRO_Wolf",
	"FRO_Wolf01",
	"FRO_Wolf02",
	"FRO_Wolf03",
	"MEX_Wolf",
	"MEX_Wolf01",
	"MEX_Wolf02",
	"MEX_Wolf03",
	"NOR_Wolf",
	"NOR_Wolf01",
	"NOR_Wolf02",
	"NOR_Wolf03",
	"NAMED_Wolf",
	"NOR_WildBoar",
	"NOR_WildBoar01",
	"NOR_WildBoar02",
	"NOR_WildBoar04",
	"NAMED_WildBoar",
	"Rabbit02",
	"Rabbit03",
	"Jackalope01",
	"MEX_Armadillo02",
	"Raccoon01",
	"Raccoon02",
	"Skunk",
	"Skunk01",
	"Skunk02",
	"NOR_Cougar",
	"FRO_Cougar",
	"FRO_Cougar01",
	"FRO_Cougar02",
	"NOR_Cougar01",
	"NOR_Cougar02",
	"NOR_Cougar03",
	"NAMED_Cougar",
	"NOR_Bear",
	"NOR_Bear01",
	"NOR_Bear02",
	"NOR_GrizzlyBear",
	"NOR_GrizzlyBear01",
	"NOR_GrizzlyBear02",
	"NOR_GrizzlyBear03",
	"NOR_SuperGrizzlyBear",
	"NOR_SuperGrizzlyBear01",
	"NOR_SuperGrizzlyBear02",
	"NAMED_SuperGrizzlyBear",
	"NOR_Beaver",
	"NOR_Beaver01",
	"NOR_Beaver02",
	"NOR_Elk",
	"NOR_Elk01",
	"NOR_Elk02",
	"MEX_BobCat",
	"MEX_BobCat01",
	"NOR_BobCat02",
	"NOR_BobCat03",
	"Buck02",
	"Buck03",
	"Deer",
	"Deer01",
	"Deer03",
	"BigHorn",
	"BigHorn01",
	"BigHorn02",
	"NOR_Buffalo",
	"NOR_Buffalo01",
	"NOR_Buffalo02",
	"NOR_Buffalo04",
	"Vulture",
	"Vulture01",
	"Vulture02",
	"Crow",
	"Crow01",
	"Crow02",
	"SongBird",
	"SongBird01",
	"SongBird02",
	"NOR_Owl",
	"NOR_Owl01",
	"NOR_Owl02",
	"FRO_Duck02",
	"NOR_Duck01",
	"Bat",
	"Bat01",
	"Bat02",
	"Hawk",
	"Hawk01",
	"Hawk02",
	"NOR_Eagle",
	"NOR_Eagle01",
	"NOR_Eagle02",
	"MEX_Eagle",
	"MEX_Eagle01",
	"MEX_Eagle02",
	"Seagull01",
	null
};
#pragma endregion

void Main_Network();

#pragma region Network
void Network_ShowSlot(int slot)
{
	SetHeader(net_player_names[slot]);

	net_selected_player = slot;

	AddItem("Teleport to",    Net_TeleportToPlayer, Main_Network, "");
	AddItem("Teleport to me", Net_TPToMe,           Main_Network, "");
	AddItem("Explode",        Net_ExplodePlayer,    Main_Network, "Exploded player");
	AddItem("Spectate",       Net_SpectatePlayer,   Main_Network, "Spectating player");
	AddItem("Kill Horse",     Net_KillPlayersHorse, Main_Network, "Killed horse");
}

void Network_LevelSpoofer()
{
	SetHeader("== Level Spoofer ==");

	AddScrollableIntItem("Prestige", nullptr, Main_Network, "", &net_spoof_prestige, 0, 4);
	AddScrollableIntItem("Level",    nullptr, Main_Network, "", &net_spoof_level,    1, 50);

	AddItem("Apply", Net_SpoofLevel, Main_Network, "");
}
#pragma endregion

#pragma region Main
void Main_Test()
{
	SetHeader("Test Options");

	AddItem("Test1", Test_1, Main, "Test1");
	AddItem("Test2", Test_2, Main, "Test2");
	AddItem("Test3", Test_3, Main, "Test3");
	AddItem("Test4", Test_4, Main, "Test4");
	AddItem("Test5", Test_5, Main, "Test5");
	AddItem("Test6", Test_6, Main, "Test6");
}

void Main_Self()
{
	SetHeader("== Self Options ==");

	AddBoolItem("Invincible",  Self_ToggleInvincible,   Main, "Toggled invincibility", self_invincible);
	AddBoolItem("Invisible",   Self_ToggleInvisible,    Main, "Toggled invisibility", self_invisible);
	AddBoolItem("Noclip",      Self_ToggleNoclip,       Main, "Toggled noclip", self_noclip);
	AddBoolItem("Drunk",       Self_ToggleDrunk,        Main, "Toggled drunk", self_drunk);
}

void Main_Weapons()
{
	SetHeader("== Weapon Options ==");

	AddItem("Give All Weapons",     Weapon_GiveAll,       Main, "All weapons given");
	AddBoolItem("All Weapons Gold", Weapon_ToggleAllGold, Main, "Toggled gold weapons", weapon_allgold);
	AddBoolItem("Infinite Ammo",    Weapon_ToggleInfAmmo, Main, "Toggled infinite ammo", weapon_infammo);
}

void Main_World()
{
	SetHeader("== World Options ==");

	AddScrollableItem("Set Weather", weather, World_SetWeather, Main, "", &world_weather);
}

void Main_Teleporter()
{
	SetHeader("== Teleporter ==");
	
	AddScrollableItem("Teleport to",  teleport_locations, Teleport_Locations, Main, "", &teleport_location);
	AddScrollableItem("Teleport 2ft", teleport_direction, Teleport_Direction, Main, "", &teleport_dir);
}

void Main_Vehicles()
{
	SetHeader("== Vehicle Options ==");

	AddScrollableItem("Spawn", vehicles, Vehicles_Spawn, Main, "", &vehicles_spawn);
}

void Main_Animals()
{
	SetHeader("== Animal Spawner ==");

	AddScrollableItem("Animal", animals, nullptr,         Main, "", &animals_index);
	AddBoolItem("Invincible",   Animals_ToggleInvincible, Main, "", animals_invincible);
	AddBoolItem("Rideable",     Animals_ToggleRideable,   Main, "", animals_rideable);
	AddBoolItem("Bodyguard",    Animals_ToggleBodyguard,  Main, "", animals_bodyguard);
	AddBoolItem("Auto ride",    Animals_ToggleRideLoop,   Main, "", animals_rideloop);

	AddItem("Spawn Animal", Animals_Spawn, Main, "");
}

void Main_Network()
{
	SetHeader("== Network Options ==");

	if (!NET_IS_IN_SESSION())
	{
		AddItem("<red>Not in multiplayer session", nullptr, Main, "");
		return;
	}

	AddItem("Fix Server", Net_FixServer, Main, "Fixing server...");

	//AddScrollableItem("Players", net_player_names, nullptr, Main, &temp);
	AddSubmenu("Level Spoofer",   Network_LevelSpoofer,  Main);
	AddItem("Refresh playerlist", Net_RefreshPlayerlist, Main, "");

	for (int i = 0; i < 16; i++)
	{
		if (_STRING_COMPARE(net_player_names[i], "invalid"))
		{
			continue;
		}

		char name[100];

		stradd_s(name, GetSlotColor(i));

		/*if (i == GET_LOCAL_SLOT())
		{
			stradd_s(name, " <green>(YOU)<grey>");
		}

		if (GET_ACTOR_INVULNERABILITY(GET_SLOT_ACTOR(i)))
			stradd_s(name, " <red>(invincible)<grey> ");*/

		switch (i)
		{
		case 0:
			AddSubmenu(name, Net_Slot1, Main);
			break;
		case 1:
			AddSubmenu(name, Net_Slot2, Main);
			break;
		case 2:
			AddSubmenu(name, Net_Slot3, Main);
			break;
		case 3:
			AddSubmenu(name, Net_Slot4, Main);
			break;
		case 4:
			AddSubmenu(name, Net_Slot5, Main);
			break;
		case 5:
			AddSubmenu(name, Net_Slot6, Main);
			break;
		case 6:
			AddSubmenu(name, Net_Slot7, Main);
			break;
		case 7:
			AddSubmenu(name, Net_Slot8, Main);
			break;
		case 8:
			AddSubmenu(name, Net_Slot9, Main);
			break;
		case 9:
			AddSubmenu(name, Net_Slot10, Main);
			break;
		case 10:
			AddSubmenu(name, Net_Slot11, Main);
			break;
		case 11:
			AddSubmenu(name, Net_Slot12, Main);
			break;
		case 12:
			AddSubmenu(name, Net_Slot13, Main);
			break;
		case 13:
			AddSubmenu(name, Net_Slot14, Main);
			break;
		case 14:
			AddSubmenu(name, Net_Slot15, Main);
			break;
		case 15:
			AddSubmenu(name, Net_Slot16, Main);
			break;
		}

		memset(name, 0, sizeof(name));
	}
}

void Main_ScriptLoader()
{
	SetHeader("Script Loader");
	AddScrollableIntItem("Script", Script_Run, Main, "", &script_index, 1, 10);
	AddItem("How to use", Script_HowTo, Main, "");
}
#pragma endregion

void Main()
{
	SetHeader("== <ROCKSTAR> Fuhzbots Menu ==");
	AddSubmenu("Self Options",    Main_Self,         nullptr);
	AddSubmenu("Weapon Options",  Main_Weapons,      nullptr);
	AddSubmenu("World Options",   Main_World,        nullptr);
	AddSubmenu("Teleporter",      Main_Teleporter,   nullptr);
	AddSubmenu("Vehicle Spawner", Main_Vehicles,     nullptr);
	AddSubmenu("Animal Spawner",  Main_Animals,      nullptr);
	AddSubmenu("Object Spawner",  nullptr,           nullptr);
	AddSubmenu("Network Options", Main_Network,      nullptr);
	AddSubmenu("Test Options",    Main_Test,         nullptr);
	AddSubmenu("Script Loader",   Main_ScriptLoader, nullptr);
}