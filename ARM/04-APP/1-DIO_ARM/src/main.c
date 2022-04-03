/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 3step
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Delay.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

int main(void)
{
	RCC_voidSysClkInit();
	RCC_voidEnableClock(RCC_GPIOA);
	DIO_voidSetPinMode(DIO_PIN0,DIO_OUTPUT_2M_PP);
	DIO_voidSetPinMode(DIO_PIN1,DIO_OUTPUT_2M_PP);


	while(1)
	{
		DIO_voidSetPinValue(DIO_PIN0,DIO_HIGH);
		DIO_voidSetPinValue(DIO_PIN1,DIO_LOW);
		_delay_ms(1000);
		DIO_voidSetPinValue(DIO_PIN0,DIO_LOW);
		DIO_voidSetPinValue(DIO_PIN1,DIO_HIGH);
		_delay_ms(1000);

	}

return 0;
}

