
#include "pushButton.h"



static uint8 au8_pushButtonValues[4] = {0};
static En_buttonStatus_t gaenu_pushButtonState[4] = {0};

/**
 * Description: Initialize the BTN_x Pin state (where x 0, 1, 2, 3) to Input
 * @param btn_id: The btn to  be initialized and it takes
 * 				  one of the enum (En_buttonId) parameters
 *
 */
void pushButton_Init(En_buttonId btn_id){
	
	switch(btn_id){
	case BTN_0:
		gpioPinDirection(BTN_0_GPIO,BTN_0_BIT,INPUT);
			break;
	case BTN_1:
		gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,INPUT);
			break;		
	case BTN_2:
		gpioPinDirection(BTN_2_GPIO,BTN_2_BIT,INPUT);
			break;
	case BTN_3:
		gpioPinDirection(BTN_3_GPIO,BTN_3_BIT,INPUT);
			break;		
	
	default:
			break;
	}
}

/**
 * Description: read all BTN_x (where x 0, 1, 2, 3) states and store it in the program
 
 * @note : this function must be called in the system tick hundler or in the super loop hundler
 */
void pushButton_Update(void){
	au8_pushButtonValues[0] = gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
	au8_pushButtonValues[1] = gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
	au8_pushButtonValues[2] = gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
	au8_pushButtonValues[3] = gpioPinRead(BTN_3_GPIO,BTN_3_BIT);


}
/**
 * Description: read BTN_x (where x 0, 1, 2, 3) state which is stored in the program
 * 				in the update function
 *
 */
En_buttonStatus_t pushButton_GetStatus(En_buttonId btn_id){
	En_buttonStatus_t enum_currentState = Released;
	switch (gaenu_pushButtonState[btn_id]){
			case Released:
				if(au8_pushButtonValues[btn_id] == LOW){
					enum_currentState = Released;
				}
				else{
					enum_currentState = Prepressed;
				}
				break;

			case Prepressed:
				if(au8_pushButtonValues[btn_id] == LOW){
					enum_currentState = Prereleased;
				}
				else{
					enum_currentState = Pressed;
				}
				break;

			case Pressed:
				if(au8_pushButtonValues[btn_id] == LOW){
					enum_currentState = Prereleased;
				}
				else{
					enum_currentState = Pressed;
				}
				break;
			case Prereleased:
				if(au8_pushButtonValues[btn_id] == LOW){
					enum_currentState = Released;
				}
				else{
					enum_currentState = Prereleased;
				}
				break;
			default:
				break;
		}
	gaenu_pushButtonState[btn_id] = enum_currentState;
	return enum_currentState;

}
