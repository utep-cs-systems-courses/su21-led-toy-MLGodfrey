#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"


void __interrupt_vec(WDT_VECTOR) WDT(){

  static char interruptTime =250;
  static char blink_count = 0;
  static char buzz_count = 0;

  if(++blink_count == interruptTime){
    blink_button_advance(blink_count);
    blink_count=0;

  }
}
