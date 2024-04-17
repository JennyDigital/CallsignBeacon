#case
#ifndef HARDWARE_H
#define HARDWARE_H

// Pins Associated with the hardware
//
#define LED_BT        PIN_A7    // White LED
#define LED_PWR_ON    PIN_A1    // Green LED
#define LED_MORSE     PIN_A0    // Blue LED

#define BEEPER        PIN_A6    // Sing fer ya suppa!

// Function declarations for hardware.
//
void LED_Beat( short beat_state );
void LED_PWR_On( short pwr_state );
void LED_Morse( short morse_state );
void SPK_Beep( short beep_state );

#include "hardware.c"
#endif