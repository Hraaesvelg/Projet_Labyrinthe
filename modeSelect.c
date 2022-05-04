#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <selector.h>
#include <motors.h>
#include <leds.h>

#include "modeSelect.h"
#include "leds.h"

static THD_WORKING_AREA(waThdSelectMode, 256);
static THD_FUNCTION(ThdSelectMode, arg) {

    chRegSetThreadName(__FUNCTION__);
    (void)arg;

    while(1){
    	int valueSelector = get_selector();
    	switch (valueSelector)
		{
			case 0:
				clear_leds();
				motors_init();
				right_motor_set_pos(500);
				left_motor_set_pos(500);
				break;
			case 1:
				clear_leds();
				set_body_led(1);
				break;
			case 2:
				set_front_led(1);
				break;
			case 3:
				clear_leds();
				set_front_led(1);
				set_body_led(1);
				break;
			default:
				clear_leds();
				break;
		}
    	chThdSleepMilliseconds(375);
    }
}

void selectionMode(void)
{
	chThdCreateStatic(waThdSelectMode, sizeof(waThdSelectMode), NORMALPRIO, ThdSelectMode, NULL);
}
