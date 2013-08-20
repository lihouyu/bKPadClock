/*
 * 74hc595.c
 *
 * 74HC595 Driver Supporting Multiple Cascade
 *
 * Based on sample code from TI MSP430 Launchpad Wiki
 *
 * HouYu Li <karajan_ii@hotmail.com>
 *
 * Does not apply any license. Use as you wish!
 */

#include <msp430.h>

#include "74hc595.h"

void HC595_latch_off() {
	HC595_POUT &= ~HC595_LATCH;
}

void HC595_latch_on() {
	HC595_POUT |= HC595_LATCH;
	HC595_POUT &= ~HC595_LATCH;
}

void HC595_shiftout (unsigned char val) {
	unsigned char i;
	for (i = 0; i < 8; i++) {
	    // Write bit
		if (val & (1 << i)) {
	        HC595_POUT |= HC595_DATA;
	    } else {
	        HC595_POUT &= ~HC595_DATA;
	    }
		// Tick clock
	    HC595_POUT |= HC595_CLOCK;
	    HC595_POUT ^= HC595_CLOCK;
	}
}

void HC595_enable() {
	HC595_POUT &= ~HC595_ENABLE;
}

void HC595_disable() {
	HC595_POUT |= HC595_ENABLE;
}
