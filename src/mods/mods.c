#include "mods.h"

#include "../menu_backend.h"

// call any functions that need to be looped here
void ExecLoopMods()
{
    Self_Loop();
    Net_Loop();
}