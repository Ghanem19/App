/*
 * softwareDelay.c
 *
 *  Created on: Dec 3, 2019
 *      Author: eng-m
 */
#include "softwareDelay.h"


/**
 * Description: this delay function operate in a polling manner
 * 				don't use it with RTOSs
 * @param n: the milli-seconds
 */
void SwDelay_ms(uint32 n){
	/**
	 * each machine cycle took 12 clock cycle
	 * assume clock 8MHz ->  so machine cycle = 1.5 us
	 * so 1ms require almost 667 machine cycle
	 *
	 */
	uint32 index = 0,j;


	for( index=0;index < n ;index++)
	{
		for(j=0;j < 26;j++){
			//26 is not logic number but it worked in simulation

		}
	}
}


