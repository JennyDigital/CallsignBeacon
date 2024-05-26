/** Callsign Beacon.
  * ----------------
  *
  * Written esp for Steve Norman by Jennifer Gunn.
  */


/** Revision History:
  * =================
  *
  *
  * Version 1.0: 
  * Initial release.
  */
#include <16F819.h>

#device PIC16F819
#device PASS_STRINGS = IN_RAM
#FUSES INTRC_IO, NOWDT, PUT, MCLR, NOBROWNOUT, CCPB3
#USE DELAY ( CLOCK = 2M )




#define TICKRATE	142u

#include <string.h>
#include "hardware.h"
#include "IRQ_Handler.h"
#include "morse.h"

extern volatile long long int systick;
extern volatile long long int ident_period;


void main( void )
{
  ServiceInterruptInit();

  LED_PWR_On( 1 );


  while( TRUE )
  {
    LED_Beat( 1 );

    ident_period = 1000u * 60u * 10u;

    Morse_puts("Code by Jennifer Gunn.");

    LED_Beat( 0 );

    while( ident_period );
  }
}
