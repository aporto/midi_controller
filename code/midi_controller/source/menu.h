/* File automatically created by MariaMole */ 

#ifndef _MENU_H_
#define _MENU_H_

#include "definitions.h"


class Menu {
	
public:
	Menu();
	void execute(void);

private:	
	void refreshScreen(void);
	unsigned char menuOption;
	void up(void);
	void down(void);
	char menu_titles[MENU_END][17];
	char YES_NO[2][4] = {"No", "Yes"};		  	

};

#endif