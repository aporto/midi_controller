/* File automatically created by MariaMole */ 

#include "config.h"

struct ConfigData {
	unsigned char lcdBrightness;
	unsigned char buttonBehavior[16][NUMBER_CONTROL_BUTTONS];
}

Config::Config(void)
{
	// Initialize with default values
	data.lcdBrightness = 50;
	for (int c=0; c<16; c++) {
		for (int i=0; i < NUMBER_CONTROL_BUTTONS; i++) {
			data.buttonBehavior[c][i] = BB_CONTROLLER_PUSH_BUTTON
		}
	}
}

void Config::load(void)
{
	unsined int addr = 0;
	data.lcdBrightness = EEPROM.read(addr);
	for (int c=0; c<16; c++) {
		for (int i=0; i < NUMBER_CONTROL_BUTTONS; i++) {
			addr++;
			data.buttonBehavior[c][i] = EEPROM.read(addr);
		}
	}
	
}

void Config::save(void)
{
	unsined int addr = 0;
	EEPROM.write(addr, &data.lcdBrightness);	
	for (int c=0; c<16; c++) {
		for (int i=0; i < NUMBER_CONTROL_BUTTONS; i++) {
			addr++;
			EEPROM.write(addr, &data.buttonBehavior[c][i]);			
		}
	}
	
}	