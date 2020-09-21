#include "mods.h"

#include "../menu_backend.h"

void ExecLoopMods()
{
    Self_Loop();
    Animals_Loop();
    Net_Loop();
}