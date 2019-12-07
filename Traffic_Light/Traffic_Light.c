/*
 * Traffic_Light.c
 *
 *  Created on: Dec 7, 2019
 *
 */

#include "Traffic_Light.h"


void trafficState(enum trafficState enum_currentState){


	switch(enum_currentState){
		case Stop:
			Led_On(3);
			SwDelay_ms(1000);
			Led_Off(3);
			enum_currentState++;
			break;
		case GetReady:
			Led_On(2);
			SwDelay_ms(1000);
			Led_Off(2);
			enum_currentState++;
			break;
		case Go:
			Led_On(1);
			SwDelay_ms(1000);
			Led_Off(1);
			enum_currentState = Stop;
			break;

	}
}
