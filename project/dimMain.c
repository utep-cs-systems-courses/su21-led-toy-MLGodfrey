#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"


void main(void) {
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  led_init(); //initialize leds, switches, and buzzer.
  switch_init();
  buzzer_init();
  buzzer_set_period(1000); // briefly activates buzzer to confirm code is loaded
  enableWDTInterrupts();/* enable periodic interrupt */
  or_sr(0x18);/* CPU off, GIE on (GIE = Global Interrupts Enable) */
}
