#include "menu_backend.h"
#include "menu.h"
#include "util.h"

#include "constants.h"
#include "intrinsics.h"
#include "natives.h"
#include "common.h"

char *menu_col_header     = "<purple>";
char *menu_col_selected   = "<blue>";
char *menu_col_unselected = "<grey>"; 

bool draw_menu             = false;
int  selected_index        = 1;
int  current_submenu_count = 1;
bool menu_pressed          = false;
bool menu_back             = false;
bool menu_pressed_right    = false;
bool menu_pressed_left     = false;
int  menu_first_row        = 1;
int  menu_depth            = 0;

unsigned int menu_header_color = 0;

int  menu_prev_index[5] = { 1, 1, 1, 1, 1 };
int  menu_prev_first[5] = { 1, 1, 1, 1, 1 };

void (*DrawCurrentMenu)() = Main;

char menu_text[255];

float fR = 0, fG = 0, fB = 0, fH = 0, fS = 1.0, fV = 1.0;

void SetHeader(char *str)
{
    fH += .5;

    if (fH == 360.0)
        fH = 0.0;

    HSVtoRGB(&fR, &fG, &fB, &fH, &fS, &fV);

    menu_header_color = ((int)(fB * 255) & 0xFF) | (((int)(fG * 255) & 0xFF) << 8) | (((int)(fR * 255) & 0xFF) << 16);

    stradd_s(menu_text, "<0x");
    stradd_s(menu_text, (IntToHex(menu_header_color, false) + 2));
    stradd_s(menu_text, ">");

    stradd_s(menu_text, str);
    stradd_s(menu_text, menu_col_unselected);
    stradd_s(menu_text, " ");
}

bool AddBaseItem(char *str, void *func, void *backfunc, const char *msg, bool submenu)
{
    void (*on_pressed)() = func;
    void (*on_back)()    = backfunc;

    if (current_submenu_count < menu_first_row || current_submenu_count > menu_first_row + MENU_SCROLL_HEIGHT)
    {
        current_submenu_count++;
        return false;
    }

    if (selected_index == current_submenu_count)
        stradd_s(menu_text, menu_col_selected);

    stradd_s(menu_text, " \n");

    if (selected_index == current_submenu_count)
        stradd_s(menu_text, " > ");

    stradd_s(menu_text, str);

    if (selected_index == current_submenu_count)
    {
        stradd_s(menu_text, menu_col_unselected);

        if (menu_pressed)
        {
            menu_pressed = false;

            if (STRING_LENGTH(msg) > 0)
            {
                char msg_formatted[255];

                stradd_s(msg_formatted, "<0x9c9c9c>[<0xffc157>Trainer<0x9c9c9c>]:</0x> ");
                stradd_s(msg_formatted, msg);

                _PRINT_CHAT(msg_formatted, 0, 0, 0, 0, 0, 0);
            }

            if (func != nullptr)
            {
                if (submenu)
                {
                    menu_prev_index[menu_depth] = selected_index;
                    menu_prev_first[menu_depth] = menu_first_row;
                    menu_depth++;
                    selected_index = 1;
                    menu_first_row = 1;
                    DrawCurrentMenu = func;
                }

                on_pressed();
            }
        }

        if (menu_back)
        {
            menu_back = false;

            if (backfunc != nullptr)
            {
                menu_depth--;
                DrawCurrentMenu = backfunc;
                selected_index = menu_prev_index[menu_depth];
                menu_first_row = menu_prev_first[menu_depth];
                on_back();
            }
            else
            {
                DrawCurrentMenu = Main;
                draw_menu = false;
            }
        }
    }

    current_submenu_count++;

    return true;
}

void AddText(char *str)
{

}

void AddItem(char *str, void *func, void *backfunc, const char *msg)
{
    AddBaseItem(str, func, backfunc, msg, false);
}

void AddSubmenu(char *str, void *func, void *backfunc)
{
    AddBaseItem(str, func, backfunc, "", true);
}

void AddBoolItem(char *str, void *func, void *backfunc, const char *msg, bool val)
{
    if (AddBaseItem(str, func, backfunc, msg, false))
    {
        val ? stradd_s(menu_text, ": <green>On") : stradd_s(menu_text, ": <red>Off");
        stradd_s(menu_text, menu_col_unselected);
    }
}

void AddScrollableItem(char *str, char *scrollable[], void *func, void *backfunc, const char *msg, int *index)
{
    if (AddBaseItem(str, func, backfunc, msg, false))
    {
        stradd_s(menu_text, ": ");
        stradd_s(menu_text, scrollable[*index]);

        if (selected_index == current_submenu_count - 1)
        {
            if (menu_pressed_right)
            {
                if (scrollable[(*index) + 1] != null)
                {
                    (*index)++;
                    PLAY_SOUND_FRONTEND("HUD_MENU_NAV_UP_MASTER");
                }

                menu_pressed_right = false;
            }

            if (menu_pressed_left)
            {
                if (*index > 0)
                {
                    (*index)--;
                    PLAY_SOUND_FRONTEND("HUD_MENU_NAV_DOWN_MASTER");
                }

                menu_pressed_left = false;
            }
        }
    }
}

void AddScrollableIntItem(char *str, void *func, void *backfunc, const char *msg, int *index, int min, int max)
{
    if (AddBaseItem(str, func, backfunc, msg, false))
    {
        stradd_s(menu_text, ": ");
        straddi_s(menu_text, *index);

        if (selected_index == current_submenu_count - 1)
        {
            if (menu_pressed_right)
            {
                if (*index < max)
                {
                    (*index)++;
                    PLAY_SOUND_FRONTEND("HUD_MENU_NAV_UP_MASTER");
                }

                menu_pressed_right = false;
            }

            if (menu_pressed_left)
            {
                if (*index > min)
                {
                    (*index)--;
                    PLAY_SOUND_FRONTEND("HUD_MENU_NAV_DOWN_MASTER");
                }

                menu_pressed_left = false;
            }
        }
    }
}

void DrawMenu()
{
    if (draw_menu == false)
        return;

    HUD_CLEAR_HELP_QUEUE();

    DrawCurrentMenu();
    HandleMenuInput();

    stradd_s(menu_text, " \n<yellow>== (");
    straddi_s(menu_text, selected_index);
    stradd_s(menu_text, "/");
    straddi_s(menu_text, current_submenu_count - 1);
    stradd_s(menu_text, ") ==");

    //UNK_0xFD355ED1(menu_text, 15);
    _PRINT_HELP(menu_text, 1, true, 2, 1, 0, 0, 0);
    //PRINT_BIG(menu_text, 1, 1, 0, 0);

    current_submenu_count = 1;
    memset(menu_text, 0, sizeof(menu_text));
}