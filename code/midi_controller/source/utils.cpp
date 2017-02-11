#include "utils.h"

bool debounce(int pin)
{
	unsigned char b1 = digitalRead(pin);
	delay(20);
	unsigned char b2 = digitalRead(pin);
	
	if (b1 == 0) {
		if (b1 == b2) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool wasButtonPressed(int pin)
{
	unsigned char b1 = digitalRead(pin);
	delay(5);
	unsigned char b2 = digitalRead(pin);
	
	if (b2 != 0) {
		return false;		
	}
	
	if (b1 == b2) {
		while (digitalRead(pin) == 0) {
			delay(1);
		}		
		return true;
	} else {
		return false;
	}	
}