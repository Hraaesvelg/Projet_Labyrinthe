#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ch.h"
#include "hal.h"
#include "memory_protection.h"
#include <motors.h>
#include <selector.h>
#include <leds.h>
#include <modeSelect.h>
#include <proximity.h>
#include <main.h>


int main(void)
{
    chSysInit();
    clear_leds();
   /* motors_init();
    proximity_start();
    calibrate_ir();*/

    /* Infinite loop. */
    while (1) {
    	/*int prox = (get_prox(0)+get_prox(8))/2;
    	if (prox >= 20){
    		left_motor_set_speed(500);
			right_motor_set_speed(500);
    	}
    	else{
    		set_body_led(1);
    	}
    	//waits 1 second
        chThdSleepMilliseconds(100);
        clear_leds();*/
    	selectionMode();
    }
}

#define STACK_CHK_GUARD 0xe2dee396
uintptr_t __stack_chk_guard = STACK_CHK_GUARD;

void __stack_chk_fail(void)
{
    chSysHalt("Stack smashing detected");
}
