#include "mods.h"

#include "../util.h"

bool self_invincible  = false;
bool self_invisible   = false;
bool self_drunk       = false;
bool self_showcoords  = false;
bool self_noclip      = false;

void Self_ToggleInvincible()
{
    ToggleBool(self_invincible);

    SET_ACTOR_INVULNERABILITY(self, self_invincible);
}

void Self_ToggleInvisible()
{
    ToggleBool(self_invisible);

    UNK_0x3E509DF1(GET_OBJECT_FROM_ACTOR(self), !self_invisible);
    //SET_INFINITE_DEADEYE(self, self_inf_deadeye);
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

    //SET_ACTOR_DRUNK(self, self_drunk);
}

void Self_SetModel()
{
    //vector3 pos;
    //GET_POSITION(self, &pos);

//    _CHANGE_ACTOR_MODEL_IN_LAYOUT(GET_AMBIENT_LAYOUT(), self, "player", ACTOR_ANIMAL_Chicken, pos, pos, true);
    //CREATE_ACTOR_IN_LAYOUT()

    vector3 position;
    vector3 rotation;

    rotation.x = 0;
    rotation.y = 0;
    rotation.z = 0;

    eActor actor = ACTOR_MPPLAYER26;

    STREAMING_REQUEST_ACTOR(actor, 1, 0);
    while (!STREAMING_IS_ACTOR_LOADED(actor, -1)) WAIT(0);
    GET_POSITION(self, &position);

    Actor res = //_CHANGE_ACTOR_MODEL_IN_LAYOUT(GET_AMBIENT_LAYOUT(), self, "player", actor, position, rotation, 1);
        CREATE_ACTOR_IN_LAYOUT(GET_AMBIENT_LAYOUT(), "player", actor, position, rotation);
    //SET_CAMERA_FOLLOW_ACTOR(res);

    TASK_KILL_CHAR(GET_ACTORS_HORSE(self), self);
//    DESTROY_CAMERA(GET_GAME_CAMERA());


    //STREAMING_EVICT_ACTOR(ACTOR_VEHICLE_Car01, -1);
    //RELEASE_ACTOR(ACTOR_VEHICLE_Car01);

}

void Self_Loop()
{
    if (IsButtonDown(BUTTON_LB) && IsButtonPressed(BUTTON_A))
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

        print("yo", 1000);
    }

    if (self_drunk)
    {
        UNK_0xFD355ED1("<green>Test1", 1);
        UNK_0xFD355ED1("<blue>Test2", 2);
        UNK_0xFD355ED1("<red>Test3", 3);
    }

    // coach name is ""
}