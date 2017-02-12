/* File automatically created by MariaMole */ 

#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#define PIN_MENU		23
#define PIN_SELECT		25
#define PIN_UP			27
#define PIN_DOWN		29

// Total number of buttons that are used as midi controllers
// DOES NOT include the buttons used for menu/bank selector
#define NUMBER_CONTROL_BUTTONS 6
// Pin where the fist pair of led and midi push button is connected
// All other pairs shall be connected on the subsequent pins
// e.g.: If PIN_FIRST_LED_BUTTON is 42, then the software will consider
// that first led is on pin 42 and first button in pin 43. 
// the second pair is pin 44/45, and goes on 
#define PIN_FIRST_LED_BUTTON 42

#define NUMBER_CONTROL_ANALOGS 10
#define PIN_FIRST_ANALOG A0
/*
#define PIN_KNOB_01		A0
#define PIN_KNOB_02		A1
#define PIN_KNOB_03		A2
#define PIN_KNOB_04		A3
#define PIN_KNOB_05		A4
#define PIN_KNOB_06		A5

#define PIN_SLIDER_01	A6
#define PIN_SLIDER_02	A7
#define PIN_SLIDER_03	A8
#define PIN_SLIDER_04	A9
*/
#define LCD_LED_PIN				2
#define LCD_CONTRAST_PIN		9
#define LCD_RS					8
#define LCD_EN					7
#define LCD_D4					6
#define LCD_D5					5
#define LCD_D6					4
#define LCD_D7					3



#endif
