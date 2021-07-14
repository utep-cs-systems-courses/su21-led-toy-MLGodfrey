#include <msp430.h>
#include "led.h"
	
	.arch msp430g2553
	.p2align 1,0

	.data

red_on:
	.byte 0
green_on:
	.byte 0
led_changed:
	.byte 0

led_init:
	bis LEDS, P1DIR
	mov #1, led_changed
	call led_update()

led_update:
	cmp #1, led_changed
	JNZ out
	mov &redVal, r13
	mov &greenVal, r14
	bis 0(r13), ledFlags
	bis 0(r14), ledFlags
	xor 0xff, LEDS
	or LEDS, r15
	and r15, P1OUT
	or ledFlags, P1OUT
	mov #0, led_changed
out:	
