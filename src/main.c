#include "menu_backend.h"

#include "types.h"
#include "constants.h"
#include "intrinsics.h"
#include "natives.h"
#include "common.h"

#include "util.h"
#include "mods/mods.h"
#include "menu.h"

void main()
{
    Script_RunByPath("scripting/DesignerDefined/UI/FuiEventMonitor_o");

    char welcome_msg[200];

    if (NET_IS_IN_SESSION())
    {
        NET_SET_THIS_SCRIPT_IS_NET_SCRIPT(_GET_ID_OF_THIS_SCRIPT());
    }

    Net_RefreshPlayerlist();

    net_player_names[16] = null;

    stradd_s(welcome_msg, "<blue>Welcome, <red>");
    stradd_s(welcome_msg, GET_LOCAL_PLAYER_NAME(0));
    stradd_s(welcome_msg, "<blue>. Menu made by <purple>Fuhzbot<blue>.</blue> \n Press <lt> + <y> to open.\n");

    PRINT_BIG(welcome_msg, 4, 1, 0, 0);

    while (true)
    {
        HandleInput();
        DrawMenu();
        ExecLoopMods();
        WAIT(0);
    }
}
