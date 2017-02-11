/* File automatically created by MariaMole */ 

#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "EEPROM.h"

#include "definitions.h"

#define BB_CONTROLLER_PUSH_BUTTON		0
#define BB_CONTROLLER_SWITCH			1
#define BB_INSTRUMENT_NOTE				2
#define BB_END							3

struct ConfigData {
	uint8_t lcdBrightness;
	uint8_t buttonBehavior[16][NUMBER_CONTROL_BUTTONS];
};

class Config {
public:	
	Config(void);
	void load(void);
	void save(void);
	ConfigData data;
};

extern Config config;

#endif
