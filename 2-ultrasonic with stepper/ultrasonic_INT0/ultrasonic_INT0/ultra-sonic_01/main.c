/*
 * ultra-sonic_01.c
 *
 * Created: 12/3/2021 11:21:51 AM
 * Author : milanka
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "ultrasonic.h"
#include "dcmotor.h"
#include "stepper.h"
int static volatile ult1_distance;

int main(void)
{
	initDCMotors();
	initUltrasonic();
	initSteppers();
 
	sei();
	
	int rounds=3;  //quantity
	int length=20; //length
	int halfDistance=2;//distance pipe at clutch 3
		ult1_distance=getUltrasonic_1_distance();
		_delay_ms(100);
	while(1)
	{	
		
		for (int i = 0; i < rounds; i++)
		{
			//rotate stepper motor2 and 1 backwards
			// move pipe forward according to the calculated length
			//rotateDCMotors(0);
		
			ult1_distance=getUltrasonic_1_distance();
			while(ult1_distance>6){
				rotateDCMotors(0);
				ult1_distance=getUltrasonic_1_distance();
			};
			stopDCMotors();
			_delay_ms(200);
			//rotate stepper motor2 and 1 forward
			// rotate stepper motor3 backward 
			rotateStepper_3(-halfDistance);
			_delay_ms(100);
			// get ultrasonic1 output distance (distance1)
			ult1_distance=getUltrasonic_1_distance();
			
			rotateDCMotors(1);
			// move clutches though rail until ult1_distance-instantDistance==length
			while((getUltrasonic_1_distance()-ult1_distance)!=length){
				rotateDCMotors(1);
			};
			stopDCMotors();
			_delay_ms(200);
			ult1_distance=getUltrasonic_1_distance();
			_delay_ms(100);
			// rotate stepper motor3 forward
			rotateStepper_3(halfDistance);
			_delay_ms(200);
			// pipe cutting process
			// start rotating cutting blade DC motor
			// rotate stepper motor4
		}
		
	}
}














	


