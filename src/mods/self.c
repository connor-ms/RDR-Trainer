#include "mods.h"

#include "../util.h"

bool self_invincible  = false;
bool self_drunk       = false;
bool self_noclip      = false;

void Self_ToggleInvincible()
{
    ToggleBool(self_invincible);

    SET_ACTOR_INVULNERABILITY(self, self_invincible);
}

void Self_ToggleNoclip()
{
    ToggleBool(self_noclip);

    if (self_noclip)
        SUSPEND_MOVER(self);
    else
        ENABLE_MOVER(self);
}

void Self_ToggleDrunk()
{
    ToggleBool(self_drunk);

    SET_ACTOR_DRUNK(self, self_drunk);
}