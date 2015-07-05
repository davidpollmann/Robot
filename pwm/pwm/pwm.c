/*
 * pwm.c
 *
 * Created: 2015-07-05 5:39:37 PM
 *  Author: David
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/io.h>

void _pwm_init(void);

int main(void)
{
	_pwm_init();
}

void _pwm_init(void)
{
    DDRB |=_BV(PB3)|_BV(PB4);
    OCR0A = 64;																//set duty cycle
	OCR0B = 64;
    TCCR0A |= _BV(COM0A1)|_BV(COM0A0)| _BV(WGM00) |_BV(COM0B1)|_BV(COM0B0);	//phase correct pwm; inverting
    TCCR0B = 1<<CS00;														//gives pre-scaler of 256
    while(1);
	PORTB = _BV(PB3)|_BV(PB4);
}
