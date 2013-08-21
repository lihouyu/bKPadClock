/*
 * timer_delay.h
 *
 * Delay functions using timer compare interrupt
 * The Timer1_A3 is used. Please check your device spec to see whether Timer1_A3 is
 * available.
 * Interrupt TIMER1_A1_VECTOR is used.
 *
 * HouYu Li <karajan_ii@hotmail.com>
 *
 * Does not apply any license. Use as you wish!
 */

#ifndef TIMER_DELAY_H_
#define TIMER_DELAY_H_

#define TIMERCTL		TA1CTL
#define TIMERCCTL		TA1CCTL0
#define TIMERCCR		TA1CCR0

#define uS_CCR_fix		5

#define uS_CCR_8MHz		8
#define uS_CCR_12MHz	12
#define uS_CCR_16MHz	16

#define mS_CCR_1MHz		1000
#define mS_CCR_8MHz		uS_CCR_8MHz * 1000
#define mS_CCR_12MHz	uS_CCR_12MHz * 1000
#define mS_CCR_16MHz	uS_CCR_16MHz * 1000

#define uS_CCR			uS_CCR_8MHz - uS_CCR_fix
#define mS_CCR			mS_CCR_8MHz - uS_CCR_fix * 10

void timer_delay_uS(unsigned int uS);
void timer_delay_mS(unsigned int mS);

#endif /* TIMER_DELAY_H_ */
