#include "mods.h"

int  animals_index      = 0;
bool animals_invincible = false;
bool animals_rideable   = false;
bool animals_bodyguard  = false;
bool animals_ismount    = false;

Actor last_spawned;

void Animals_ToggleInvincible() { ToggleBool(animals_invincible); }
void Animals_ToggleRideable()   { ToggleBool(animals_rideable);   }
void Animals_ToggleBodyguard()  { ToggleBool(animals_bodyguard);  }
void Animals_ToggleMount()      { ToggleBool(animals_ismount);    }

void Animals_Spawn()
{
    vector3 pos, rot;
    GET_POSITION(self, &pos);

    rot.x = 0;
    rot.y = 0;
    rot.z = 0;

    last_spawned = CREATE_ACTOR_IN_LAYOUT(GET_AMBIENT_LAYOUT(), "", animals_index + 976, pos, rot);

    SET_ACTOR_INVULNERABILITY(last_spawned, animals_invincible);

    SET_ACTOR_RIDEABLE(last_spawned, animals_rideable);
    SET_ALLOW_RIDE_BY_PLAYER(last_spawned, animals_rideable);

    if (animals_bodyguard)
    {
        SET_ACTOR_FACTION(last_spawned, 20);
        TASK_FOLLOW_ACTOR(last_spawned, self);
    }

    if (animals_ismount)
    {
        SET_ACTORS_HORSE(self, last_spawned);
    }

    RELEASE_ACTOR(last_spawned);
}