
#include "MotorDC.h"

/**
 * Description: 
 * @param
 */
void MotorDC_Init(En_motorType_t MOT_x){
	switch(MOT_x){
		case(MOT_1):
			gpioPinDirection(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,OUTPUT);
			gpioPinDirection(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT	,OUTPUT);
			gpioPinDirection(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT	,OUTPUT);
			break;
		case(MOT_2):
			gpioPinDirection(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,OUTPUT);
			gpioPinDirection(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT	,OUTPUT);
			gpioPinDirection(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT	,OUTPUT);
			break;
		default:
			break;
	}
}

/**
 * Description: 
 * @param 
 * @param 
 */
void MotorDC_Dir(En_motorType_t MOT_x, En_motorDir_t dir){

	switch(MOT_x){
		case(MOT_1):
			switch(dir){
				case STOP:
				gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT	,LOW);
				gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT	,LOW);		
				//gpioPinWrite(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,HIGH);
	
					break;
				case FORWARD:
				gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT	,HIGH);
				gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT	,LOW);		
				//gpioPinWrite(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,HIGH);
	
					break;
				case BACKWARD:
				gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT	,LOW);
				gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT	,HIGH);		
				//gpioPinWrite(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,HIGH);
					
					break;
				default:
					break;
			}
			break;
		case(MOT_2):
			switch(dir){
				case STOP:
				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT	,LOW);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT	,LOW);		
				//gpioPinWrite(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,HIGH);
	
					break;
				case FORWARD:
				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT	,HIGH);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT	,LOW);		
				//gpioPinWrite(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,HIGH);
	
					break;
				case BACKWARD:
				gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT	,LOW);
				gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT	,HIGH);		
				//gpioPinWrite(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,HIGH);
		
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}


}

/**
 * Description: 
 * @param 
 */
 
void MotorDC_Speed_PollingWithT0(uint8 speed){
		
	timer1SwPWM(speed,1);
		
}

/**
 * Description: set the port value (which is PORT register)
 * @param 
 */
void MotorDC_Speed_HwPWM(uint8 speed);
