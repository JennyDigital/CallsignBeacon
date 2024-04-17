#ifndef IRQ_HANDLER_H
#define IRQ_HANDLER_H

volatile long long int systick = 0;
volatile long long int ident_period = 0;

void ISR_Ticker( void );
void ServiceInterruptInit( void );
void Delay_Ticks( long long int ticks);
#include "IRQ_Handler.c"
#endif