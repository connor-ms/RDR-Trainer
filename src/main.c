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
    LAUNCH_NEW_SCRIPT("scripting/DesignerDefined/UI/FuiEventMonitor_o", 1);

    //REQUEST_ASSET("ui/pausemenu/lobby/menu.sc", ASSET_TYPE_ActorType);

    while (HUD_IS_FADED())
    {
        if (IsButtonDown(BUTTON_B))
        {
            UI_EXIT("LoadingScreenTexture");
            UI_EXIT("LoadingScreen");
            UI_EXIT("MPSplash");
            UI_ACTIVATE("HudSceneLayer");
            UI_SHOW("HudSceneLayer");
            UI_ENTER("HudSceneLayer");
            UI_ACTIVATE("HudSceneOnline");
            UI_SHOW("HudSceneOnline");
            UI_ENTER("HudSceneOnline");

            UI_SEND_EVENT("net.worldLoaded");
            UI_SEND_EVENT("loadComplete");
        }

        WAIT(0);
    }

    char welcome_msg[200];

    if (NET_IS_IN_SESSION())
    {
        NET_SET_THIS_SCRIPT_IS_NET_SCRIPT(_GET_ID_OF_THIS_SCRIPT());
    }

    Net_RefreshPlayerlist();

    net_player_names[16] = null;

    stradd_s(welcome_msg, "<blue>Welcome, <red>");
    stradd_s(welcome_msg, GET_SLOT_NAME(GET_LOCAL_SLOT()));
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
