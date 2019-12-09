
#include "MotorDC.h"

int main(void)
{	
	uint16 delay;
	uint8 repeat =0;
	timer1Init(T1_NORMAL_MODE,0,T1_PRESCALER_NO,0,0,0,0,T1_POLLING);
	MotorDC_Init(MOT_1);
	MotorDC_Dir(MOT_1,FORWARD);


	while (1)
    {
    	if(repeat == 0){
    			for(delay=0;delay<1000;delay++){
    				MotorDC_Speed_PollingWithT0(70);
    			}

    		repeat = 1;
    	}
	}
}
