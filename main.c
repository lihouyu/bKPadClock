#include <msp430.h> 

#include "74hc595_conf.h"
#include "74hc595.h"
#include "4d7s_display.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    fD7S_init();
    fD7S_show_digit(0, 0, 1);

	return 0;
}
