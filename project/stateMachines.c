#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

char interruptTime;
char button_four;

void blink_button_advance(){
  //  char switch_pressed = 0;
  // char changed = 0;
 
  if(switch_state_down_1){ //full bright and high buzz
    // switch_pressed = 1;
    interruptTime=0;
    turn_on_red();
    buzzer_set_period(2551);
  }
  else if(switch_state_down_2){ //half dim and mid buzz
    // switch_pressed = 2;
    interruptTime=2;
    turn_on_red();
    buzzer_set_period(3214);
  }
  else if(switch_state_down_3){ //full dim and low buzz
    //switch_pressed = 3;
    interruptTime=0;
    turn_on_red();
    turn_off_red();
    buzzer_set_period(3822);
  }
  else if(switch_state_down_4){ // count to 3

    button_four = 1;
    interruptTime = 250;
    buzzer_set_period(0);
    static char state = 0;
    switch(state){
  case 0: buzzer_set_period(3822); red_on=0; green_on+0; state++; break;
  case 1: buzzer_set_period(2551); red_on=0; green_on=1; state++; break;
  case 2: buzzer_set_period(3822); red_on=1; green_on=0; state++; break;
  case 3: buzzer_set_period(2551); red_on=1; green_on=1; state=0; break;
  default: state = 0;
    }
    led_changed=1;
    led_update();
  } else {
    button_four=0;
    turn_off_red();
    turn_off_green();
    buzzer_set_period(0);
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


