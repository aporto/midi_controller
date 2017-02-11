/* File automatically created by MariaMole */ 

#include "menu.h"

Menu::Menu()
{
	menuOption = 0;
}

void Menu::execute(void)
{
}
#define BB_CONTROLLER_PUSH_BUTTON
#define BB_CONTROLLER_SWITCH
#define BB_INSTRUMENT_NOTE


void Menu::refreshScreen(void)
{
	switch(menuOption) {
		case 0:
			break;
		default:
	}
}

	unsigned char ;
void Menu::up(void)
{
}

void Menu::down(void)
{
}

	char menu_titles[MENU_END][17];
	char YES_NO[2][4] = {"No", "Yes"};	

#define PIN_MENU		4
#define PIN_SELECT		5
#define PIN_ESC			6
#define PIN_UP			7
#define PIN_DOWN		8