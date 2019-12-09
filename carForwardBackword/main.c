/*
 * dcMotor.c
 *
 * Created: 12/9/2019 8:34:35 PM
 * Author : eng-m
 */ 
#include "MotorDC.h"

int main(void)
{	
	uint16 delay;
	uint8 speed = 0,repeat =0;
	timer1Init(T1_NORMAL_MODE,0,T1_PRESCALER_NO,0,0,0,0,T1_POLLING);
	MotorDC_Init(MOT_1);
	MotorDC_Init(MOT_2);
	MotorDC_Dir(MOT_1,FORWARD);
	MotorDC_Dir(MOT_2,FORWARD);
	while (1)
    {
    	if(repeat == 0){
    		for(speed=0;speed<100;speed+=1){
    			for(delay=0;delay<50;delay++){
    				MotorDC_Speed_PollingWithT0(speed);
    			}
    		}
    		for(speed=99;speed>0;speed--){
    			for(delay=0;delay<50;delay++){
    				MotorDC_Speed_PollingWithT0(speed);
    			}
    		}
    		MotorDC_Dir(MOT_1,FORWARD);
    		MotorDC_Dir(MOT_2,STOP);
    		for(delay=0;delay<1000;delay++){
				MotorDC_Speed_PollingWithT0(70);
			}

    		repeat = 1;
    	}
	}
}
