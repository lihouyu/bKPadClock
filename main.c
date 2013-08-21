#include <msp430.h> 

#include "74hc595.h"
#include "4d7s_display.h"

#include "timer_delay.h"

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    BCSCTL1	= CALBC1_8MHZ;
    DCOCTL	= CALDCO_8MHZ;

    fD7S_init();

    while (1) {
		fD7S_show_digit(0, 0, 1);
		timer_delay_mS(200);
		fD7S_show_digit(1, 1, 0);
		timer_delay_mS(200);
		fD7S_show_digit(3, 2, 0);
		timer_delay_mS(200);
		fD7S_show_digit(5, 3, 0);
		timer_delay_mS(200);
    }
}
