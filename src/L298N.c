#include<Arduino.h>
#include<stdlib.h>
#include<stdint.h>
#include "L298N.h"

MOTOR* motorCreate(uint8_t pin1,uint8_t pin2){
	MOTOR* out=(MOTOR*)malloc(sizeof(MOTOR));
	out->pin1=pin1;
	out->pin2=pin2;
	out->pwmPin=_L298N_N_PWMPIN;
	return out;
}

MOTOR* motorCreatePwm(uint8_t pin1,uint8_t pin2,uint8_t pwmPin){
	MOTOR* out=(MOTOR*)malloc(sizeof(MOTOR));
	out->pin1=pin1;
	out->pin2=pin2;
	out->pwmPin=pwmPin;
	return out;
}

MOTOR* motorCreatePwmPwm(uint8_t pin1,uint8_t pin2){
	MOTOR* out=(MOTOR*)malloc(sizeof(MOTOR));
	out->pin1=pin1;
	out->pin2=pin2;
	out->pwmPin=_L298N_N_PWMPIN;
	return out;
}

void motorInit(MOTOR* motor){
	pinMode(motor->pin1,OUTPUT);
	pinMode(motor->pin2,OUTPUT);
	digitalWrite(motor->pin1,LOW);
	digitalWrite(motor->pin2,LOW);
	if(motor->pwmPin != _L298N_N_PWMPIN) analogWrite(motor->pwmPin,0);
}

void motorSet(MOTOR* motor,MOTOR_TURN_MOD turnMod){
	if(turnMod==CW){
		digitalWrite(motor->pin1,LOW);
		digitalWrite(motor->pin2,HIGH);
		motor->pwmPin=_L298N_N_PWMPIN | CW;		//為了motorSetPwmPwm而記錄當前轉向
	}
	else if(turnMod==CCW){
		digitalWrite(motor->pin1,HIGH);
		digitalWrite(motor->pin2,LOW);
		motor->pwmPin=_L298N_N_PWMPIN | CCW;	//為了motorSetPwmPwm而記錄當前轉向
	}
	else{
		digitalWrite(motor->pin1,LOW);
		digitalWrite(motor->pin2,LOW);
		motor->pwmPin=_L298N_N_PWMPIN | STOP;	//為了motorSetPwmPwm而記錄當前轉向
	}
}

void motorSetPwm(MOTOR* motor,uint16_t pwm){
	//是PWM型馬達才給調速
	if(motor->pwmPin < _L298N_N_PWMPIN) analogWrite(motor->pwmPin,pwm);
}

void motorSetPwmPwm(MOTOR* motor,uint16_t pwm){
	if(motor->pwmPin-_L298N_N_PWMPIN==CW){
		analogWrite(motor->pin2,pwm);
	}
	else if(motor->pwmPin-_L298N_N_PWMPIN==CCW){
		analogWrite(motor->pin1,pwm);
	}
}