/* File automatically created by MariaMole */ 

#ifndef _MIDI_DEFINITIONS_H_
#define _MIDI_DEFINITIONS_H_


#define NOTE_OFF       0x80
#define NOTE_ON        0x90
#define CC             0xB0
	
typedef struct {
  uint8_t status;   // first  byte   : status message (NOTE_ON, NOTE_OFF or CC (controlchange) and midi channel (0-15)
  uint8_t data1;    // second byte   : first value (0-127), controller number or note number
  uint8_t data2;    // third  byte   : second value (0-127), controller value or velocity
} t_midiMsg; 
	
#endif
