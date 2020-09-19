#include "mods.h"

int vehicles_spawn = 0;

void Vehicles_Spawn()
{
    Actor vehicle = vehicles_spawn + 1177;
    vector3 pos, rotation;

    rotation.x = 0;
    rotation.y = 0;
    rotation.z = 0;

    STREAMING_REQUEST_ACTOR(vehicle, true, false);
    
    while (!STREAMING_IS_ACTOR_LOADED(vehicle, -1)) 
        WAIT(0);

    GET_POSITION(self, &pos);

    char name[25];

    stradd_s(name, "vehicle");
    straddi_s(name, vehicles_spawn);

    Actor actor = CREATE_ACTOR_IN_LAYOUT(GET_AMBIENT_LAYOUT(), name, vehicle, pos, rotation);

    SET_VEHICLE_ALLOWED_TO_DRIVE(actor, true);
    ENABLE_VEHICLE_SEAT(actor, 0, true);
    SET_ACTOR_AUTO_TRANSITION_TO_DRIVER_SEAT(self, 1);
    SET_ACTOR_IN_VEHICLE(self, actor, 0);

    START_VEHICLE(actor);
    SET_VEHICLE_ENGINE_RUNNING(actor, true);
    
}