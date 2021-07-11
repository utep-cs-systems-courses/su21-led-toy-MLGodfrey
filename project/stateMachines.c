#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

void blink_button_advance(char blink_count){

  char changed = 0;

  //Turn on Normal light
  if(switch_state_down_1){
    turn_on_red();
  }
  // Turn on half DIM light
  else if(switch_state_down_2){
    while(blink_count <=250){
      if(blink_count == 250){
	turn_on_red();
	blink_count=0;
      }
      else{
	turn_off_red();
	blink_count++;
      }
    }
  }
  else if (switch_state_down_3){
    turn_on_red();
    turn_off_red();
  }
  // Turn off light
  else{
    turn_off_red();
  }
}


void turn_on_red(){
  red_on=1;
  led_changed = 1;
  led_update();
}

void turn_off_red(){
  red_on=0;
  led_changed=1;
  led_update();
}