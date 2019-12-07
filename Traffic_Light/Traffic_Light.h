/*
 * Traffic_Light.h
 *
 *  Created on: Dec 7, 2019
 *      Author: eng-m
 */

#ifndef TRAFFIC_LIGHT_H_
#define TRAFFIC_LIGHT_H_

#include "led.h"
#include "softwareDelay.h"
enum trafficState{
	Stop,
	GetReady,
	Go

};
void trafficState(enum trafficState state);

#endif /* TRAFFIC_LIGHT_H_ */
