#include "mods.h"

int script_index = 1;

void Script_Run()
{
    char script[100];

    stradd_s(script, "$/content/scripting/");
    straddi_s(script, script_index);

    if (DOES_SCRIPT_EXIST(script) == false)
    {
        print("<red>Error: Script doesn't exist", 2000);
        return;
    }

    REQUEST_ASSET(script, ASSET_TYPE_Script);

    int id = GET_ASSET_ID(script, ASSET_TYPE_Script);

    while (STREAMING_IS_SCRIPT_LOADED(id) == false)
    {
        STREAMING_REQUEST_SCRIPT(id);
        print("Loading script...", 200);
        WAIT(0);
    }

    int scr = LAUNCH_NEW_SCRIPT(script, 0);
    ADD_PERSISTENT_SCRIPT(scr);

    print("<green>Ran script!", 1000);
}

void Script_HowTo()
{
    print("<green>To use the script loader, place your script in <0xFFD700>/content/", 2000);
}