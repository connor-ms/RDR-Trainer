#include "mods.h"

int script_index = 1;

void Script_Run()
{
    char script[100];

    stradd_s(script, "$/content/scripting/");
    straddi_s(script, script_index);

    Script_RunByPath(script);
}

void Script_RunByPath(const char *path)
{
    if (DOES_SCRIPT_EXIST(path) == false)
    {
        print("<red>Error: Script doesn't exist", 2000);
        return;
    }

    REQUEST_ASSET(path, ASSET_TYPE_Script);

    int id = GET_ASSET_ID(path, ASSET_TYPE_Script);

    while (STREAMING_IS_SCRIPT_LOADED(id) == false)
    {
        STREAMING_REQUEST_SCRIPT(id);
        print("Loading script...", 200);
        WAIT(0);
    }

    int scr = LAUNCH_NEW_SCRIPT(path, 0);
    ADD_PERSISTENT_SCRIPT(scr);

    _PRINT_CHAT("<green>Launched script!", 0, 0, 0, 0, 0, 0);
}