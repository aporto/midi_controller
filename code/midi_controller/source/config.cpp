/* File automatically created by MariaMole */ 

#include "config.h"

Config config;

Config::Config(void)
{
	// Initialize with default values
	data.lcdBrightness = 50;
	for (int c=0; c<16; c++) {
		for (int i=0; i < NUMBER_CONTROL_BUTTONS; i++) {
			data.buttonBehavior[c][i] = BB_CONTROLLER_PUSH_BUTTON;
		}
	}
}

void Config::load(void)
{
	unsigned int addr = 0;
	data.lcdBrightness = EEPROM.read(addr);
	if (data.lcdBrightness > 100) {
		data.lcdBrightness = 100;
	}
	for (int c=0; c<16; c++) {
		for (int i=0; i < NUMBER_CONTROL_BUTTONS; i++) {
			addr++;
			data.buttonBehavior[c][i] = EEPROM.read(addr);
			if (data.buttonBehavior[c][i] >= BB_END) {
				data.buttonBehavior[c][i] = 0;
			}
		}
	}
	
}

void Config::save(void)
{
	unsigned int addr = 0;
	EEPROM.write(addr, data.lcdBrightness);	
	for (int c=0; c<16; c++) {
		for (int i=0; i < NUMBER_CONTROL_BUTTONS; i++) {
			addr++;
			EEPROM.write(addr, data.buttonBehavior[c][i]);			
		}
	}
	
}	