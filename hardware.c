#case
#include "hardware.h"

void LED_Beat( short int beat_state )
{
  output_bit( LED_BT, beat_state );
}

void LED_PWR_On( short int pwr_state )
{
  output_bit( LED_PWR_ON, pwr_state );
}

void LED_Morse( short int morse_state )
{
  output_bit( LED_MORSE, morse_state );
}

void SPK_Beep( short int beep_state )
{
  output_bit( BEEPER, beep_state );
}