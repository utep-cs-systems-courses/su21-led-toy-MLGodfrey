#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char interruptTime;

void blink_button_advance(){
  //  char switch_pressed = 0;
  // char changed = 0;
 
  if(switch_state_down_1){
    // switch_pressed = 1;
    interruptTime=0;
    turn_on_red();
    buzzer_set_period(2551);
  }
  else if(switch_state_down_2){
    // switch_pressed = 2;
    interruptTime=2;
    turn_on_red();
    buzzer_set_period(3214);
  }
  else if(switch_state_down_3){
    //switch_pressed = 3;
    interruptTime=0;
    turn_on_red();
    turn_off_red();
    buzzer_set_period(3822);
  }
  else if(switch_state_down_4){
    //switch_pressed = 4;
  }
  else{
    // switch_pressed = 0;
    turn_off_red();
    buzzer_set_period(0);
  }
}
  
  /* switch(switch_pressed){
  case 0:
    turn_off_green();
    turn_off_red();
    break;
  case 1:
    turn_on_green();
    break;
  case 2:
    turn_on_red();
    break;
  case 3:
    dimLed();
  }
  } */


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
void turn_on_green(){
  green_on=1;
  led_changed = 1;
  led_update();
}
void turn_off_green(){
  green_on=0;
  led_changed=1;
  led_update();
}

/*void dimLed(){
  char iTime = 0;
  while (iTime<=250){
    if(iTime%5==0){
      turn_on_red();
    iTime++;
    }else
      {
	turn_off_red();
	iTime++;
      }
    break;
    }*/

