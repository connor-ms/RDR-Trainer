#include "menu_backend.h"
#include "util.h"

#include "natives.h"
#include "constants.h"
#include "common.h"
#include "intrinsics.h"

void HandleInput()
{
    if (IsButtonDown(BUTTON_L2) && IsButtonPressed(BUTTON_Y))
    {
        if (draw_menu)
            draw_menu = false;
        else
            draw_menu = true;
    }
}

void HandleMenuInput()
{
    if (IsButtonPressed(DPAD_DOWN))
    {
        if (selected_index < current_submenu_count - 1)
        {
            selected_index++;

            if (selected_index > menu_first_row + MENU_SCROLL_HEIGHT)
                menu_first_row++;

            PLAY_SOUND_FRONTEND("HUD_MENU_NAV_UP_MASTER");
        }
        
        menu_pressed_left  = false;
        menu_pressed_right = false;
    }

    if (IsButtonPressed(DPAD_UP))
    {
        if (selected_index > 1)
        {
            selected_index--;

            if (selected_index < menu_first_row)
                menu_first_row--;

            PLAY_SOUND_FRONTEND("HUD_MENU_NAV_DOWN_MASTER");
        }

        menu_pressed_left  = false;
        menu_pressed_right = false;
    }

    if (IsButtonPressed(DPAD_LEFT))
        menu_pressed_left = true;

    if (IsButtonPressed(DPAD_RIGHT))
        menu_pressed_right = true;

    if (IsButtonPressed(BUTTON_A))
    {
        menu_pressed = true;
        PLAY_SOUND_FRONTEND("HUD_MENU_SELECT_MASTER");
    }

    if (IsButtonPressed(BUTTON_B))
    {
        menu_back = true;
        PLAY_SOUND_FRONTEND("HUD_MENU_BACK_MASTER");
    }

    if (IsButtonPressed(BUTTON_SELECT) || IsButtonPressed(BUTTON_START))
        draw_menu = false;
}

void HSVtoRGB(float *fR, float *fG, float *fB, float *fH, float *fS, float *fV)
{
    float fC = *fV * *fS; // Chroma
    float fHPrime = fMod(*fH / 60.0, 6);

    float fX = fC * (1 - FABS(fMod(fHPrime, 2) - 1));
    float fM = *fV - fC;

    if (0 <= fHPrime && fHPrime < 1)
    {
        *fR = fC;
        *fG = fX;
        *fB = 0;
    }
    else if (1 <= fHPrime && fHPrime < 2)
    {
        *fR = fX;
        *fG = fC;
        *fB = 0;
    }
    else if (2 <= fHPrime && fHPrime < 3)
    {
        *fR = 0;
        *fG = fC;
        *fB = fX;
    }
    else if (3 <= fHPrime && fHPrime < 4)
    {
        *fR = 0;
        *fG = fX;
        *fB = fC;
    }
    else if (4 <= fHPrime && fHPrime < 5)
    {
        *fR = fX;
        *fG = 0;
        *fB = fC;
    }
    else if (5 <= fHPrime && fHPrime < 6)
    {
        *fR = fC;
        *fG = 0;
        *fB = fX;
    }
    else
    {
        *fR = 0;
        *fG = 0;
        *fB = 0;
    }

    *fR += fM;
    *fG += fM;
    *fB += fM;
}