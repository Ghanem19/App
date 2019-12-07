/*
 * main.c
 *
 *  Created on: Dec 7, 2019
 *      Author: eng-m
 */


#include "led.h"
#include "Traffic_Light.h"

int main(void)
{
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);

	while(1)
    {
		trafficState(Stop);

	}



}
