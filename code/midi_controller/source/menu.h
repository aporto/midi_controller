/* File automatically created by MariaMole */ 

#ifndef _MENU_H_
#define _MENU_H_

#include "Arduino.h"
#include "LiquidCrystal.h"

#include "definitions.h"
#include "config.h"
#include "utils.h"

#define OPTION_LCD_BRIGHTNESS		0
#define OPTION_FIRST_PIN_SETUP		1

extern LiquidCrystal lcd;

class Menu {	
public:
	Menu();
	void execute(void);

private:	
	void refreshScreen(void);
	int menuOption;
};

extern Menu menu;

#endif