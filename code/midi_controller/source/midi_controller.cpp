#include "mariamole_auto_generated.h"
/*
 MIDI note player
 
 This sketch shows how to use the serial transmit pin (pin 1) to send MIDI note data.
 If this circuit is connected to a MIDI synth, it will play 
 the notes F#-0 (0x1E) to F#-5 (0x5A) in sequence.

 
 The circuit:
 * digital in 1 connected to MIDI jack pin 5
 * MIDI jack pin 2 connected to ground
 * MIDI jack pin 4 connected to +5V through 220-ohm resistor
 Attach a MIDI cable to the jack, then to a MIDI synth, and play music.

 created 13 Jun 2006
 modified 13 Aug 2012
 by Tom Igoe 

 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Midi
 
 */
 
#include "definitions.h"
#include "menu.h"
#include "config.h" 
#include "utils.h" 
#include "ardumidi.h"
 
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7); //configura os pinos do arduino para se comunicar com o lcd
//unsigned char pinButton[NUMBER_CONTROL_BUTTONS];
char oldButtonValue[16][NUMBER_CONTROL_BUTTONS];
//char oldButtonValue[16][NUMBER_CONTROL_BUTTONS];
char oldSwitchValue[16][NUMBER_CONTROL_BUTTONS];
int oldAnalogValue[NUMBER_CONTROL_ANALOGS];
unsigned char channel = 0;

void checkAndSendSensors(void)
{	
	

	//#define CHANNEL  10

	/*int controllers[6] = { 
		0x10, 0x11, 0x12, 0x13, 0x14, 0x15
	};*/
	

	//int oldValue = -1;


	// Analogs desabilitados. 
	//TODO colocar comentario para nao deixar analog flutuante
	/* for (int i=0; i < NUMBER_CONTROL_ANALOGS; i++) {
		int sensorValue = analogRead(PIN_FIRST_ANALOG + i);
		if (sensorValue != oldAnalogValue[i]) {
			oldAnalogValue[i] = sensorValue;
			//msg.status = CC;		
			//msg.status = msg.status | (channel);  
			//msg.data1  = i; //controllers[0];                  // Get the controller number from the array above.
			//msg.data2  = sensorValue / 8;                    // Get the value of the analog input from the analogVal array.
			//Serial.write((uint8_t *)&msg, sizeof(msg));    // Send the MIDI message.
			midi_controller_change(channel, i , sensorValue/8);
			
			lcd.setCursor(0,1);
			lcd.print("Analog ");
			lcd.print((int)i);
			lcd.print(" ");
			lcd.print((int)sensorValue/8);
		}
	} */
	
	for (int i=0; i < NUMBER_CONTROL_BUTTONS; i++) {
		int sensorValue = !(digitalRead(PIN_FIRST_LED_BUTTON + i * 2 + 1));
		if (sensorValue != oldButtonValue[channel][i]) {			
			if (config.data.buttonBehavior[channel][i] == BB_CONTROLLER_SWITCH) {			
				if (sensorValue == 1) {
					oldSwitchValue[channel][i] = ! (oldSwitchValue[channel][i]);
					lcd.setCursor(0,1);
					lcd.print("                ");
					lcd.setCursor(0,1);
					lcd.print("Button ");
					lcd.print((int)i + 1);							
					if (oldSwitchValue[channel][i]) {
						lcd.print(" SW ON");
						digitalWrite(PIN_FIRST_LED_BUTTON + i * 2, 1);
						//Serial.println("on 1");				
						midi_controller_change(channel, i + NUMBER_CONTROL_ANALOGS, 127);			
						//Serial.println("on 2");				
					} else {
						lcd.print(" SW OFF");
						digitalWrite(PIN_FIRST_LED_BUTTON + i * 2, 0);
						//Serial.println("off 1");				
						midi_controller_change(channel, i + NUMBER_CONTROL_ANALOGS, 0);			
						//Serial.println("off 2");				
					}					
				}
			} else {
				if (config.data.buttonBehavior[channel][i] == BB_CONTROLLER_PUSH_BUTTON) {
					lcd.setCursor(0,1);
					lcd.print("                ");
					lcd.setCursor(0,1);
					lcd.print("Button ");
					lcd.print((int)i + 1);
					lcd.print("PB ");
					lcd.print((int)sensorValue);		
					digitalWrite(PIN_FIRST_LED_BUTTON + i * 2, sensorValue);			
					midi_controller_change(channel, i + NUMBER_CONTROL_ANALOGS, sensorValue);				
				} else if (config.data.buttonBehavior[channel][i] == BB_INSTRUMENT_NOTE) {
					lcd.setCursor(0,1);
					lcd.print("                ");
					lcd.setCursor(0,1);
					lcd.print("Button ");
					lcd.print((int)i + 1);										
					digitalWrite(PIN_FIRST_LED_BUTTON + i * 2, sensorValue);			
					if (sensorvalue) {
						lcd.print("Note ON");												
						midi_note_on(channel, i+80, 45);
					} else {
						lcd.print("Note OFF");
						midi_note_off(channel, i+80, 45);
					}												
				}
			}
			oldButtonValue[channel][i] = sensorValue;	
		}
	}
}

void setup() {	
	config.load();
	
	//  Set MIDI baud rate:
	//Serial.begin(31250);
	Serial.begin(115200);
	
	for (int i=0; i < NUMBER_CONTROL_BUTTONS; i++) {
		//pinButton[i] = PIN_FIRST_BUTTON + i;
		pinMode(PIN_FIRST_LED_BUTTON + i * 2, OUTPUT);
		pinMode(PIN_FIRST_LED_BUTTON + i * 2 + 1, INPUT_PULLUP);
		//Serial.print("Led ");		
		//Serial.print(PIN_FIRST_LED_BUTTON + i * 2);		
		//Serial.print(" button ");		
		//Serial.println(PIN_FIRST_LED_BUTTON + i * 2 + 1);				
		for (int c=0; c<16; c++) {
			oldButtonValue[c][i] = 0;
			oldSwitchValue[c][i] = 0;
		}
	}
	
	for (int i=0; i < NUMBER_CONTROL_ANALOGS; i++) {
		for (int c=0; c<16; c++) {
			oldAnalogValue[i] = -1;
		}
	}
	
	pinMode(PIN_MENU, INPUT_PULLUP);
	pinMode(PIN_SELECT, INPUT_PULLUP);
	pinMode(PIN_UP, INPUT_PULLUP);
	pinMode(PIN_DOWN, INPUT_PULLUP);
	
	
	//pinMode(13, OUTPUT);
	
	// Configure LCD
	pinMode(LCD_LED_PIN, OUTPUT);
	pinMode(LCD_CONTRAST_PIN, OUTPUT);	
	analogWrite(LCD_LED_PIN, 255 * config.data.lcdBrightness / 100);
	//analogWrite(LCD_CONTRAST_PIN, 10);
	lcd.begin(16, 2); 
	lcd.setCursor(0,0);
	lcd.print("Midi");	
}

void loop() {
	/*Serial.print(digitalRead(PIN_MENU));
	Serial.print(", ");
	Serial.print(digitalRead(PIN_SELECT));
	Serial.print(", ");
	Serial.print(digitalRead(PIN_UP));
	Serial.print(", ");
	Serial.println(digitalRead(PIN_DOWN));*/
	//delay(10);
//	return;
	
	
	if (wasButtonPressed(PIN_UP)) {		
		channel++;
		if (channel == 16) {
			channel = 0;
		}
	}
	if (wasButtonPressed(PIN_DOWN)) {				
		if (channel == 0) {
			channel = 15;
		} else {
			channel--;
		}
	}
	lcd.setCursor(0,0);
	lcd.print("-> Channel ");
	lcd.print((int)channel + 1);
	lcd.print("  ");
	
	checkAndSendSensors();
	//digitalWrite(42, 1);
	//Serial.println(digitalRead(43));
	
	digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(100);                       // wait for a second
	digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
	delay(100);
	
	if (debounce(PIN_MENU)) {
		menu.execute();		
	}
}

