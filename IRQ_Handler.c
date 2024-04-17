#case
volatile short int beeping=0;

// ======================
//
// ISR related functions.
//
// ======================

#int_timer0
void ISR_Ticker( void )
{
  static short spk_phase = 0;

	delay_cycles( 9 );
	// Reset Timer0.  (the pic does not have and automatic reload).
	set_timer0( TICKRATE );
	

  if( beeping )
  {
    LED_Morse( 1 );
    spk_phase = !spk_phase;
    SPK_Beep( spk_phase );
  }
  else 
  {
    LED_Morse( 0 );
    SPK_Beep( 0 );
  }


	if( ident_period > 0 ) ident_period--;
  if( systick > 0 ) systick--;

	clear_interrupt( INT_TIMER0 );
}


void ServiceInterruptInit( void )
{
	setup_timer_0( RTCC_DIV_4 | RTCC_INTERNAL );		// Setup interrupts

	set_timer0( TICKRATE );
	enable_interrupts( INT_TIMER0 );
	enable_interrupts( GLOBAL );
}

void Delay_Ticks( long long int ticks )
{
	systick = ticks;
	while( systick > 0 );
}