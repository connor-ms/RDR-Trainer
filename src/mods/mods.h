#pragma once

#include "types.h"
#include "constants.h"
#include "natives.h"
#include "common.h"
#include "intrinsics.h"

#include "../menu.h"

#define ToggleBool(a) a = (a == true) ? false : true
#define self GET_PLAYER_ACTOR(0)

extern bool self_invincible;
extern bool self_invisible;
extern bool self_drunk;
extern bool self_showcoords;
extern bool self_noclip;

void Self_ToggleInvincible();
void Self_ToggleNoclip();
void Self_ToggleDrunk();

extern bool weapon_allgold;
extern bool weapon_infammo;

void Weapon_ToggleAllGold();
void Weapon_ToggleInfAmmo();
void Weapon_GiveAll();

extern int world_weather;

void World_SetWeather();

extern int teleport_location;
extern int teleport_dir;

void Teleport_Locations();
void Teleport_Direction();

extern int vehicles_spawn;

void Vehicles_Spawn();

extern int  animals_index;
extern bool animals_invincible;
extern bool animals_rideable;
extern bool animals_bodyguard;
extern bool animals_ismount;

void Animals_ToggleInvincible();
void Animals_ToggleRideable();
void Animals_ToggleBodyguard();
void Animals_ToggleMount();
void Animals_Spawn();

extern char *net_player_names[17];
extern int   net_selected_player;

const char *GetColoredSlotName(int slot);

void Net_FixServer();

void Net_RefreshPlayerlist();

void Net_TeleportToPlayer();
void Net_SpectatePlayer();

void Net_Loop();

// ugly, but couldn't get variadic arguments working without crashes :(
void Net_Slot0()  { Network_ShowSlot(0);  }
void Net_Slot1()  { Network_ShowSlot(1);  }
void Net_Slot2()  { Network_ShowSlot(2);  }
void Net_Slot3()  { Network_ShowSlot(3);  }
void Net_Slot4()  { Network_ShowSlot(4);  }
void Net_Slot5()  { Network_ShowSlot(5);  }
void Net_Slot6()  { Network_ShowSlot(6);  }
void Net_Slot7()  { Network_ShowSlot(7);  }
void Net_Slot8()  { Network_ShowSlot(8);  }
void Net_Slot9() { Network_ShowSlot(9);  }
void Net_Slot10() { Network_ShowSlot(10); }
void Net_Slot11() { Network_ShowSlot(11); }
void Net_Slot12() { Network_ShowSlot(12); }
void Net_Slot13() { Network_ShowSlot(13); }
void Net_Slot14() { Network_ShowSlot(14); }
void Net_Slot15() { Network_ShowSlot(15); }

void ExecLoopMods();

extern int script_index;

void Script_Run();
void Script_RunByPath(const char* path);