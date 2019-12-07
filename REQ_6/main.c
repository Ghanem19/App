/*
 * main.c
 *
 *  Created on: Dec 6, 2019
 *	REQ_6 main.c file
 *
 *  When button 1 is pressed and released, LED 1 will be on and stay lit for 1
	 second then the LED 1 is switched off.
 *  If button 1 is kept pushed, the LED will stay on.
 *  If button 1 is pressed and released twice and the time between the first and
     second presses is less than 1s, then the LED 1 will be on for 2 seconds then it
     will be turned off.
 *  If the time between the first and second presses is more than 1s then the led will
     be turned off after 1s.
 */


#include "pushButton.h"
#include "softwareDelay.h"
#include "led.h"

int main(void)
{
	En_buttonStatus_t state;
	uint8 pressedCounter = 0,prereleasedCounter = 0;
	uint16 delay=0;
	Led_Init(LED_1);
	pushButton_Init(BTN_1);
	gpioPortDirection(GPIOA,OUTPUT);

	while(1)
    {

		pushButton_Update();
		state = pushButton_GetStatus(BTN_1);
		if(state == Pressed && pressedCounter == 0){
			Led_On(LED_1);
			pressedCounter++;
		}
		if(state == Prereleased){
			prereleasedCounter++;
		}
		if(delay<1000 && pressedCounter == 1 && prereleasedCounter == 2 ){
			Led_On(LED_1);
			SwDelay_ms(2000);
			Led_Off(LED_1);
			pressedCounter = 0;
			prereleasedCounter = 0;
			delay = 0;
		}
		if(prereleasedCounter > 0 ){
			SwDelay_ms(10);
			delay += 10;
			if(delay >= 1000){
			Led_Off(LED_1);
			pressedCounter = 0;
			prereleasedCounter = 0;
			delay = 0;

			}
		}

    }

}

