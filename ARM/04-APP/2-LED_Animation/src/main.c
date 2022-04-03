/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 3step
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTIC_interface.h"
#include "Led_Animation.h"


int main (void)
{
	/*init RCC clock*/
	RCC_voidSysClkInit();
	RCC_voidEnableClock(RCC_GPIOA);
	LED_voidInit();
	STK_voidInit();
	while(1)
	{
		LED_voidAnimationLeft();
		LED_voidAnimationRight();
		LED_voidAnimationIn();
		LED_voidAnimationOut();
	}
	return 0;
}
