#include "mods.h"

int teleport_location = 0;
int teleport_dir      = 0;

void Teleport_Locations()
{
	vector3 loc;

	switch (teleport_location)
	{
	case 0: // agave viejo
		loc.x = -1545.03f;
		loc.y = 15.03f;
		loc.z = 3913.46f;
		break;
	case 1: // armadillo
		loc.x = -2175.62f;
		loc.y = 16.31f;
		loc.z = 2613.50f;
		break;
	case 2: // beechers hope
		loc.x = -83.45f;
		loc.y = 117.68f;
		loc.z = 1374.10f;
		break;
	case 3: // benedict point
		loc.x = -3686.96f;
		loc.y = 8.62f;
		loc.z = 3493.24f;
		break;
	case 4: // blackwater
		loc.x = 711.18f;
		loc.y = 78.31f;
		loc.z = 1252.763f;
		break;
	case 5: // Casa Madrugada
		loc.x = -788.78f;
		loc.y = 13.04f;
		loc.z = 3729.81f;
		break;
	case 6: // Chuparosa
		loc.x = -2714.70f;
		loc.y = 32.37f;
		loc.z = 4251.90f;
		break;
	case 7: // Cochinay
		loc.x = -739.29f;
		loc.y = 179.10f;
		loc.z = 784.69f;
		break;
	case 8: // Coot's Chapel
		loc.x = -1793.48f;
		loc.y = 23.78f;
		loc.z = 2836.85f;
		break;
	case 9: // El Matadero
		loc.x = -455.44f;
		loc.y = 20.84f;
		loc.z = 3926.91f;
		break;
	case 10: // El Presidio
		loc.x = -698.10f;
		loc.y = 63.25f;
		loc.z = 3323.25f;
		break;
	case 11: // Escalera
		loc.x = -4279.04f;
		loc.y = 18.07f;
		loc.z = 4447.64f;
		break;
	case 12: // Fort Mercer
		loc.x = -2622.53f;
		loc.y = 68.08f;
		loc.z = 3390.51f;
		break;
	case 13: // Gaptooth Breach
		loc.x = -4461.66f;
		loc.y = 7.78f;
		loc.z = 3310.42f;
		break;
	case 14: // Lake Don Julio
		loc.x = -1955.07f;
		loc.y = 24.82f;
		loc.z = 3255.67f;
		break;
	case 15: // Las Hermanas
		loc.x = -1700.31f;
		loc.y = 8.08f;
		loc.z = 4242.14f;
		break;
	case 16: // Manzanita Post
		loc.x = -428.16f;
		loc.y = 151.34f;
		loc.z = 1615.59f;
		break;
	case 17: // McFarlane's Ranch
		loc.x = -887.08f;
		loc.y = 90.19f;
		loc.z = 2420.53f;
		break;
	case 18: // Nosalida
		loc.x = -4701.72f;
		loc.y = 3.04f;
		loc.z = 3958.90f;
		break;
	case 19: // Pacific Union Camp
		loc.x = -273.95f;
		loc.y = 84.31f;
		loc.z = 2113.30f;
		break;
	case 20: // Plainview
		loc.x = -3126.40f;
		loc.y = 43.57f;
		loc.z = 3724.13f;
		break;
	case 21: // Rathskeller Fork
		loc.x = -3661.76f;
		loc.y = 42.23f;
		loc.z = 2124.7;
		break;
	case 22: // Ridgewood Farm
		loc.x = -3275.14f;
		loc.y = 15.89f;
		loc.z = 2719.86f;
		break;
	case 23: // Serendipity's Wreck
		loc.x = 325.34f;
		loc.y = 74.29f;
		loc.z = 1939.81f;
		break;
	case 24: // Thieve's Landing
		loc.x = 111.55f;
		loc.y = 73.29f;
		loc.z = 2318.82f;
		break;
	case 25: // Tumbleweed
		loc.x = -4007.25f;
		loc.y = 28.46f;
		loc.z = 2935.45f;
		break;
	case 26: // Tesoro Azul
		loc.x = -3288.00f;
		loc.y = 38.20f;
		loc.z = 4547.00f;
		break;
	case 27: // Torquemada
		loc.x = 376.66f;
		loc.y = 76.30f;
		loc.z = 3459.57f;
		break;
	case 28: // Twin Rocks
		loc.x = -2425.06f;
		loc.y = 25.00f;
		loc.z = 2138.93f;
		break;
	}

	TELEPORT_ACTOR(self, &loc, 1, 1, 1);
}

void Teleport_Direction()
{
	vector3 loc;
	GET_POSITION(self, &loc);

	float heading = GET_HEADING(self);

	float dist = 2.0;

	float a = dist * SIN(heading);
	float b = dist * COS(heading);

	switch (teleport_dir)
	{
	case 0: // forward
		loc.x -= a;
		loc.z -= b;
		break;
	case 1: // back
		loc.x += a;
		loc.z += b;
		break;
	case 2: // up
		loc.y += 2.0;
		break;
	case 3: // down
		loc.y -= 2.0;
		break;
	}

	TELEPORT_ACTOR_WITH_HEADING(self, loc, heading, 1, 1, 1);
}