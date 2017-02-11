/* File automatically created by MariaMole */ 

#include "menu.h"

Menu menu;

Menu::Menu()
{
	menuOption = 0;
}

void Menu::execute(void)
{
	lcd.clear();	
	lcd.print("Entering menu...");
	Serial.println("Entrando");
	int lastPressedPin = 0;
	while (digitalRead(PIN_MENU) == 0) {
		delay(1);
	}	
	menuOption = 0;
	Serial.println("Entrou");
	refreshScreen();
	
	//return;
	
	while (true) {		
		if (debounce(PIN_UP)) {
			Serial.println("up");
			lastPressedPin = PIN_UP;
			menuOption++;			
			if (menuOption >= 16 * (NUMBER_CONTROL_BUTTONS) + OPTION_FIRST_PIN_SETUP) {
				menuOption = 0;
			}
			//refreshScreen();
		}
		if (debounce(PIN_DOWN)) {
			Serial.println("down");
			lastPressedPin = PIN_DOWN;
			menuOption--;			
			if (menuOption < 0) {
				menuOption = 16 * (NUMBER_CONTROL_BUTTONS) + OPTION_FIRST_PIN_SETUP - 1;
			}
			//refreshScreen();
		}
		
		if (debounce(PIN_MENU)) {
			lastPressedPin = PIN_MENU;
			config.save();
			lcd.clear();
			Serial.println("Saiu");
			return;
		}
		
		if (debounce(PIN_SELECT)) {
			Serial.println("Select");
			lastPressedPin = PIN_SELECT;
			if (menuOption == OPTION_LCD_BRIGHTNESS) {
				config.data.lcdBrightness += 5;
				if (config.data.lcdBrightness > 100) {
					config.data.lcdBrightness = 0;
				}
			} else if (menuOption >= OPTION_FIRST_PIN_SETUP) {
				int channel = (menuOption - OPTION_FIRST_PIN_SETUP) / NUMBER_CONTROL_BUTTONS;
				int button = (menuOption - OPTION_FIRST_PIN_SETUP) % NUMBER_CONTROL_BUTTONS;
				config.data.buttonBehavior[channel][button]++;
				if (config.data.buttonBehavior[channel][button] == BB_END) {
					config.data.buttonBehavior[channel][button] = 0;
				}
			}						
		}
		
		if (lastPressedPin != 0) {
			Serial.println("call refresh");
			refreshScreen();			
			while (digitalRead(lastPressedPin) == 0) {
				delay(1);
			}
			lastPressedPin = 0;
			Serial.println("continue");
		}
	}
}

void Menu::refreshScreen(void)
{
	Serial.println("Refresh");
	//return;
	analogWrite(LCD_LED_PIN, 255 * config.data.lcdBrightness / 100);
	lcd.clear();
	//lcd.print("Back to root...");					
	//lcd.setCursor(0,1);
	//lcd.print("is allowed!");
	
	if (menuOption == OPTION_LCD_BRIGHTNESS) {
		lcd.print("LCD Brightness");					
		lcd.setCursor(0,1);
		lcd.print((int)config.data.lcdBrightness); 
		lcd.print(" %");
	} else if (menuOption >= OPTION_FIRST_PIN_SETUP) {		
		int channel = (menuOption - OPTION_FIRST_PIN_SETUP) / NUMBER_CONTROL_BUTTONS;
		int button = (menuOption - OPTION_FIRST_PIN_SETUP) % NUMBER_CONTROL_BUTTONS;
		
		Serial.print("::");
		Serial.print(menuOption);
		Serial.print(",");
		Serial.print(channel);
		Serial.print(",");
		Serial.print(button);
		Serial.println(" ");
		
		lcd.print("Button ");					
		lcd.print((int)channel + 1);
		lcd.print("/");
		lcd.print((int)button + 1);
		lcd.setCursor(0,1);
		if (config.data.buttonBehavior[channel][button] == BB_CONTROLLER_PUSH_BUTTON) {
			lcd.print("PushButton");
		} else if (config.data.buttonBehavior[channel][button] == BB_CONTROLLER_SWITCH) {
			lcd.print("Switch/Latch");
		} else if (config.data.buttonBehavior[channel][button] == BB_INSTRUMENT_NOTE) {
			lcd.print("Instrument note");
		}
	}
}
