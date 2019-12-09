/*
 * timer.c
 *
 *  Created on: Dec 7, 2019
 *      Author: eng-m
 */
//TCCR BITS NAME
# include "timers.h"

#define TOV0  0
#define OCF0  1
#define OCF1A 4
#define TOV1  2
#define TOV2  6
#define OCF2  7
En_timer0perscaler_t genu_timer0Prescaler = 0;
En_timer1perscaler_t genu_timer1Prescaler = 0;
En_timer1perscaler_t genu_timer2Prescaler = 0;
/*===========================Timer0 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer0Init(En_timer0Mode_t mode,En_timer0OC_t OC0,En_timer0perscaler_t prescal, uint8 initialValue, uint8 outputCompare, En_timer0Interrupt_t interruptMask){

	/*   Overflow mode
		 * TCCR0:WGM 1:0 = 0
		 * 		 COM 1:0 = 0
		 * 		 FOC0 = 0
		 * set prescal if there and start timer
		 * */
	/*	Compare mode
		 * WGM 1:0 = 2
		 * COM 1:0 = 1,2 or 3
		 * FOC0 = 0
		 * OCR0 = outputCompare
		 * OCIE0 = 1 if interrupt required
		 * set prescaler if there and start timer
		 * */

	 TCCR0 = (mode | OC0);
	 TCNT0 = initialValue;
	 OCR0 = outputCompare;
	 TIMSK |= interruptMask;
	 genu_timer0Prescaler = prescal;
}

/**
 * Description:
 * @param value
 */
void timer0Set(uint8 value){
	 TCNT0 = value;
}

/**
 * Description:
 * @return
 */
uint8 timer0Read(void){
	return TCNT0;
}

/**
 * Description:
 */
void timer0Start(void){
	TCCR0 |= genu_timer0Prescaler;
}

/**
 * Description:
 */
void timer0Stop(void){
	TCCR0 &= 0xf8;
}

/**
 * Description:
 * @param delay
 */
void timer0Delay_ms(uint16 delay){
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_64,0,0,T0_POLLING);
		while(delay--){
			timer0Set(6);
			timer0Start();
			while((TIFR & (1<<TOV0)) == 0);
			TIFR |= (1<<TOV0);
			timer0Stop();
		}
}

/**
 * Description:
 * @param dutyCycle
 * @param frequency in kHz
 */
void timer0SwPWM(uint8 dutyCycle,uint8 freq){

}

/*===========================Timer1 Control===============================*/
/**
 * Description:
 * @param controlA
 * @param controlB
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer1Init(En_timer1Mode_t mode,En_timer1OC_t OC,En_timer1perscaler_t prescal, uint16 initialValue, uint16 outputCompareA, uint16 outputCompareB,uint16 inputCapture, uint8 interruptMask){
	TCCR1 = (mode | OC);
	TCNT1 = initialValue;
	TIMSK |=  interruptMask;
	OCR1A = outputCompareA;
	OCR1B = outputCompareB;
	ICR1 = inputCapture;
	genu_timer1Prescaler = prescal;
}

/**
 * Description:
 * @param value
 */
void timer1Set(uint16 value){
	TCNT1 = value;
}

/**
 * Description:
 * @param value
 */

uint16 timer1Read(void){
	return TCNT1;
}


/**
 * Description:
 */
void timer1Start(void){
	TCCR1 |= genu_timer1Prescaler;
}

/**
 * Description:
 */
void timer1Stop(void){
	TCCR1 &= T1_NO_CLOCK;
}

/**
 * Description:
 * @param delay
 */
void timer1Delay_ms(uint16 delay){
		timer1Init(T1_NORMAL_MODE,0,T1_PRESCALER_64,0,250,0,0,T0_POLLING);
		while(delay>0){
			OCR1A = 250;
			timer1Set(0);
			timer1Start();
			while((TIFR & (1<<OCF1A)) == 0);
			TIFR |= (1<<OCF1A);
			timer1Stop();
			delay--;
		}
}

/**
 * Description:
 * @param dutyCycle
 */
void timer1SwPWM(uint8 dutyCycle,uint16 freq){


	uint32 periodTicks = (16000/(freq));
	uint16 onTimeTicks = (((dutyCycle*periodTicks)/100) - 1);
	periodTicks = 0xffff - periodTicks; // TCNT
	onTimeTicks += periodTicks;	//OCR1
	//timer1Init(T1_NORMAL_MODE,0,T1_PRESCALER_NO,periodTicks,onTimeTicks,0,0,T1_POLLING);s
		timer1Set(periodTicks);
		OCR1A = onTimeTicks;
		gpioPinWrite(GPIOD,BIT4,HIGH);
		gpioPinWrite(GPIOD,BIT5,HIGH);
		timer1Start();
		while((TIFR & (1<<OCF1A)) == 0);
		TIFR |= (1<<OCF1A);
		gpioPinWrite(GPIOD,BIT4,LOW);
		gpioPinWrite(GPIOD,BIT5,LOW);
		while((TIFR & (1<<TOV1)) == 0);
		TIFR |= (1<<TOV1);
		timer1Stop();
}
/*===========================Timer2 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer2Init(En_timer2Mode_t mode,En_timer2OC_t OC,En_timer2perscaler_t prescal, uint8 initialValue, uint8 outputCompare, uint8 assynchronous, En_timer2Interrupt_t interruptMask){

	 TCCR2 = mode | OC;
	 TCNT2 = initialValue;
	 OCR2 = outputCompare;
	 TIMSK |= interruptMask;
	 genu_timer2Prescaler = prescal;

}
/**
 * Description:
 * @param value
 */
void timer2Set(uint8 value){
	TCNT2 = value;
}

/**
 * Description:
 * @return
 */
uint8 timer2Read(void){
	return TCNT2;
}

/**
 * Description:
 */
void timer2Start(void){
	TCCR2 = genu_timer2Prescaler;
}

/**
 * Description:
 */
void timer2Stop(void){
	TCCR2 &= 0xf0;
}

/**
 * Description:
 * @param delay
 */
void timer2Delay_ms(uint16 delay){
	timer2Init(T2_NORMAL_MODE,T0_OC0_DIS,T2_PRESCALER_64,6,0,0,T2_POLLING);
			while(delay--){
				timer2Set(6);
				timer2Start();
				while((TIFR & (1<<TOV2)) == 0);
				TIFR |= (1<<TOV2);
				timer2Stop();
			}

}

/**
 * Description:
 * @param dutyCycle
 * @param freq
 */
void timer2SwPWM(uint8 dutyCycle,uint8 freq){

}

/*
 * user defined

void timer2Delay_us(uint32 delay){
	timer2Init(T2_NORMAL_MODE,T0_OC0_DIS,T2_PRESCALER_NO,0,0,0,T2_POLLING);
		timer2Set(250);
		timer2Start();

				while(delay--){
					while((TIFR & (1<<TOV2)) == 0);
					TIFR |= (1<<TOV2);
					timer2Stop();
					timer2Set(250);
					timer2Start();

				}
	}




 */
