#include "mods.h"

#include "../menu_backend.h"

#pragma region test
void Test_1()
{
	/*if (UI_ISACTIVE("OL_NetworkingMenu") == false)
	{
		UI_ACTIVATE("OL_NetworkingMenu");
	}

	if (UI_ISACTIVE("OL_NetworkingMenu"))
	{
		draw_menu = false;

		UI_SHOW("OL_NetworkingMenu");

		print("<green>Showing menu...", 2000);
	}
	else
	{
		print("<red>Failed to activate menu!", 3000);
	}*/

	//UI_ENTER("AAPrompts_Stats");
	//UNK_0xFA382FCB(0, UI_GET_STRING("Common_Null"));

	/*if (UI_ISACTIVE("OL_ModMenu") == false)
	{
		UI_ACTIVATE("OL_ModMenu");
	}

	if (UI_ISACTIVE("OL_ModMenu"))
	{
		draw_menu = false;
		UI_SHOW("OL_ModMenu");
		print("<green>Showing menu...", 2000);
	}
	else
	{
		print("<red>Failed to activate menu!", 3000);
	}*/

	char temp[100];

	stradd_s(temp, "index true: ");
	straddi_s(temp, UI_GET_SELECTED_INDEX("HudGamerList", true));
	stradd_s(temp, " false: ");
	straddi_s(temp, UI_GET_SELECTED_INDEX("HudGamerList", false));

	print(temp, 1000);
}

void Test_2()
{
	//SET_FORCE_PLAYER_AIM_MODE(0, 0);
	//SET_FORCE_PLAYER_AIM_MODE(0,1);
	//UI_BUTTON_SET_TEXT("testbutton", "mp_gamer_joinbarker");

	/*if (UI_ISACTIVE("HudSceneOnline") || UI_ISACTIVE("PlayerList"))
	{
		print("One is active", 2000);
		UI_ENTER("HudSceneOnline");
	}

	UI_ENTER("");
	UI_SEND_EVENT("y_released");*/

	//UNK_0x794F5C21(0);
	//UNK_0x794F5C21(1);
	//UNK_0x794F5C21(2);
	//UNK_0x794F5C21(3);
	//UNK_0x794F5C21(4);

	//UI_DISABLE("HudGamerList");
	/*UI_EXCLUDE("HudGamerList");
	UI_EXCLUDE("HudSceneLayer");
	UI_EXCLUDE("HudSceneOnline");*/
}

void Test_3()
{
	//UI_SEND_EVENT("Prestige");
	//UI_SET_STRING("lblexit", "cumn");

	//UI_ACTIVATE("HudSceneOnline");
	//UI_ACTIVATE("PlayerList");

	//ENABLE_USE_CONTEXTS(true);

	//UNK_0xFD355ED1("<red>Test", 0);

	/*UNK_0xC673362C("Test", 0);
	UNK_0xC673362C("Test1", 1); crashes
	UNK_0xC673362C("Test2", 2);*/

	//UNK_0x777A1CA2();

//	UNK_0xFD355ED1(UI_GET_STRING("Common_Null"), 1);

	/*UI_DEACTIVATE("HudGamerList");
	UI_DEACTIVATE("HudSceneLayer");
	UI_DEACTIVATE("HudSceneOnline");*/

	//HudGamerList
	//playerlist
	// netmachine
	//netui.gamersupdated
	//netui.gamerschanged
}

void Test_4()
{
	/*CreateSizedArray(int, arr, 2, 100, 100);

	GUI_MAKE_TEXT(GUI_MAIN_WINDOW(), &arr, "Title", "Text", 2.0);*/
	//printtest("test %s %f %d", "cum", 215.25f, 5);

	/*Blip self_blip = GET_BLIP_ON_ACTOR(self);

	if (IS_BLIP_VALID(self_blip))
	{
		print("Blip valid", 1000);

		SET_BLIP_NAME(self_blip, "test");
	}
	else
	{
		print("<red> invalid", 1000);
	}*/

	UNK_0xC09ACD5C(0);
	
	/*UI_EXIT("HudGamerList");
	UI_EXIT("HudSceneLayer");
	UI_EXIT("HudSceneOnline");*/

	//draw_menu = false;
}

void Test_5()
{
	//print(UNK_0xC7612A79("netNoAmbientWorld", "blah"), 1000);
	//UNK_0xC73DAD2B(UI_GET_STRING("net_posse_left"), 0, 0, 0, 0, 0, 0);
	UI_ACTIVATE("HudGamerList");
	UI_ENTER("HudGamerList");
	UI_FOCUS("HudGamerList");

	UNK_0xFD355ED1("<green>Test1", 1);
	UNK_0xFD355ED1("<blue>Test2", 2);
	UNK_0xFD355ED1("<red>Test3", 3);
}

void Test_6()
{
	//UNK_0x3C2D93C1(80.0f, 0.0f, "test", 1, 1, 1, 1);
	//ADD_SCRIPT_USE_CONTEXT();
	//UI_ENTER("AAPrompts_PlayerList");
	//UNK_0xFD355ED1("Common_Null", 0);
	//UNK_0xFD355ED1("Common_Null", 1);
	//UNK_0xFA382FCB(0, "Common_Null");
	//UNK_0xFA382FCB(1, "Common_Null");
	//UNK_0xFA382FCB(2, "Common_Null");
	//UNK_0xFA382FCB(3, "Common_Null");
//	UNK_0xFA382FCB(4, "Common_Null");	
	UI_UNFOCUS("HudGamerList");
}
#pragma endregion

void ExecLoopMods()
{
	Self_Loop();
	Animals_Loop();
	Net_Loop();
}