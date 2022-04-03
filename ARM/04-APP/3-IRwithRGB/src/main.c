/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 3step
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_INTERFACE.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "SYSTIC_interface.h"

#include "IRREMOTE_interface.h"

u8 Global_Button =0;
void main(void)
{
	/* RCC init.*/
	RCC_voidSysClkInit();
	/* Enable GPIOA clock*/
	RCC_voidEnableClock(RCC_GPIOA);
	RCC_voidEnableClock(RCC_AFIO);
	/* make the pins of RGB output pins*/
	MGPIO_VidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);

	/*init remote control*/
	IR_voidInit();

	while(1)
	{
		MGPIO_VidSetPinValue(GPIOA,PIN1,LOW);
		MGPIO_VidSetPinValue(GPIOA,PIN1,LOW);
		MGPIO_VidSetPinValue(GPIOA,PIN1,LOW);
		Global_Button = IR_u8GETButton();
		switch(Global_Button)
		{
		case ZERO: 	MGPIO_VidSetPinValue(GPIOA,PIN1,HIGH);break;
		case ONE: 	MGPIO_VidSetPinValue(GPIOA,PIN2,HIGH);break;
		case TWO:	MGPIO_VidSetPinValue(GPIOA,PIN3,HIGH);break;
		case THREE:  MGPIO_VidSetPinValue(GPIOA,PIN1,HIGH);
					MGPIO_VidSetPinValue(GPIOA,PIN2,HIGH);
					MGPIO_VidSetPinValue(GPIOA,PIN3,HIGH);break;
		default:	MGPIO_VidSetPinValue(GPIOA,PIN1,LOW);
					MGPIO_VidSetPinValue(GPIOA,PIN2,LOW);
					MGPIO_VidSetPinValue(GPIOA,PIN3,LOW);break;
		}
	}

}
