/*
 * stepper.c
 *
 * Created: 6/15/2022 2:06:58 AM
 *  Author: Dasith
 */ 

#include "stepper.h"

void initSteppers(){
	DDRA = 0xFF;
	DDRC = 0xFF;
}

void rotateStepper_3(int distance){
	// clockwise-1
	// Counterclockwise-0
	// 1 distance unit = 1 rotating

	int period;
	period = 5;
	if (distance>0)
	{
		/* Rotate  clockwise */
		for(int i=0;i<distance;i++)
		{
			PORTC = 0x03;
			_delay_ms(period);
			PORTC = 0x06;
			_delay_ms(period);
			PORTC = 0x0c;
			_delay_ms(period);
			PORTC = 0x09;
			_delay_ms(period);
			PORTC = 0x03;
			_delay_ms(period);
		}

		_delay_ms(10);
	}
	else
	{
		/* Rotate  Counterclockwise  */
		for (int i = 0; i < abs(distance); i++)
		{
			PORTC = 0x03;
			_delay_ms(period);
			PORTC = 0x09;
			_delay_ms(period);
			PORTC = 0x0c;
			_delay_ms(period);
			PORTC = 0x06;
			_delay_ms(period);
			PORTC = 0x03;
			_delay_ms(period);
		}

		_delay_ms(10);
	}
}