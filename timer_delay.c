/*
 * timer_delay.c
 *
 * Delay functions using timer compare interrupt
 * The Timer1_A3 is used. Please check your device spec to see whether Timer1_A3 is
 * available.
 * Interrupt TIMER1_A0_VECTOR is used.
 *
 * HouYu Li <karajan_ii@hotmail.com>
 *
 * Does not apply any license. Use as you wish!
 */

#include <msp430.h>

#include "timer_delay.h"

void timer_delay_uS(unsigned int uS) {
	unsigned int delay_CCR	= 0;
	unsigned int CPUOFF_GIE	= 0;
	delay_CCR	= uS_CCR;
	CPUOFF_GIE	= CPUOFF + GIE;

	TIMERCTL	= TASSEL_2 + MC_1;
	TIMERCCTL	= CCIE;
	while (uS) {
		TIMERCCR	= delay_CCR;
		_BIS_SR(CPUOFF_GIE);
		uS--;
	}
	TIMERCCTL	= 0;
}

void timer_delay_mS(unsigned int mS) {
	unsigned int delay_CCR	= 0;
	unsigned int CPUOFF_GIE	= 0;
	delay_CCR	= mS_CCR;
	CPUOFF_GIE	= CPUOFF + GIE;

	TIMERCTL	= TASSEL_2 + MC_1;
	TIMERCCTL	= CCIE;
	while (mS) {
		TIMERCCR	= delay_CCR;
		_BIS_SR(CPUOFF_GIE);
		mS--;
	}
	TIMERCCTL	= 0;
}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer_Delay(void) {
	_BIC_SR_IRQ(CPUOFF);
	TIMERCCR	= 0;
	TIMERCCTL	= CCIE;		// Clear timer interrupt flag while retain the interrupt
							// enable bit
}
