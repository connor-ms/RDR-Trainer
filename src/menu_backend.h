#pragma once

#include "types.h"

#define MENU_SCROLL_HEIGHT 6

extern bool draw_menu;
extern int  selected_index;
extern int  current_submenu_count;
extern bool menu_pressed;
extern bool menu_back;
extern bool menu_pressed_left;
extern bool menu_pressed_right;
extern int  menu_first_row;

extern void (*DrawCurrentMenu)();

void DrawMenu();

void SetHeader(char *str);
bool AddBaseItem(char *str, void *func, void *backfunc, const char *msg, bool submenu);
void AddItem(char *str, void *func, void *backfunc, const char *msg);
void AddSubmenu(char *str, void *func, void *backfunc);
void AddBoolItem(char *str, void *func, void *backfunc, const char *msg, bool val);
void AddScrollableItem(char *str, char *scrollable[], void *func, void *backfunc, const char *msg, int *val);
void AddScrollableIntItem(char *str, void *func, void *backfunc, const char *msg, int *index, int min, int max);