#include <mouvement.h>
#include <motor.h>

#define PI                  3.1415926536f
#define WHEEL_DISTANCE      5.35f    //cm
#define PERIMETER_EPUCK     (PI * WHEEL_DISTANCE)

void tout_droit (void){
	right_motor_set_speed(500);
	left_motor_set_speed(500);
}


void virage_droite (void){  // virage à droite du robot
	right_motor_set_pos(0);
	left_motor_set_pos(0);
	while (left_motor_get_pos() < PERIMETER_EPUCK/4 && right_motor_get_pos() < PERIMETER_EPUCK/4){
		right_motor_set_speed(-500);
		left_motor_set_speed(500);
	}
}


void virage_gauche (void){  // virage à gauche du robot
	right_motor_set_pos(0);
	left_motor_set_pos(0);
	while (left_motor_get_pos() < PERIMETER_EPUCK/4 && right_motor_get_pos() < PERIMETER_EPUCK/4){
		right_motor_set_speed(500);
		left_motor_set_speed(-500);
	}
}


void demi_tour (void){  // le robot fait un demi tour
	right_motor_set_pos(0);
	left_motor_set_pos(0);
		while (left_motor_get_pos() < PERIMETER_EPUCK/2 && right_motor_get_pos() < PERIMETER_EPUCK/2){
			right_motor_set_speed(500);
			left_motor_set_speed(-500);
		}
}


void spin(void){  // le robot fait un tour sur lui même
	right_motor_set_pos(0);
	left_motor_set_pos(0);
	while (left_motor_get_pos() < PERIMETER_EPUCK && right_motor_get_pos() < PERIMETER_EPUCK){
		right_motor_set_speed(500);
		left_motor_set_speed(-500);
	}
}
