/*
 * Led_Animation.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Engy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTIC_interface.h"
#include "Led_Animation.h"

u8 a=4, b=3;

void LED_voidInit(void)
{
	/*select the mode of the pin*/
	DIO_voidSetPinMode(DIO_PIN0,DIO_OUTPUT_2M_PP);
	DIO_voidSetPinMode(DIO_PIN1,DIO_OUTPUT_2M_PP);
	DIO_voidSetPinMode(DIO_PIN2,DIO_OUTPUT_2M_PP);
	DIO_voidSetPinMode(DIO_PIN3,DIO_OUTPUT_2M_PP);
	DIO_voidSetPinMode(DIO_PIN4,DIO_OUTPUT_2M_PP);
	DIO_voidSetPinMode(DIO_PIN5,DIO_OUTPUT_2M_PP);
	DIO_voidSetPinMode(DIO_PIN6,DIO_OUTPUT_2M_PP);
	DIO_voidSetPinMode(DIO_PIN7,DIO_OUTPUT_2M_PP);
}

void LED_voidAnimationLeft(void)
{
	u8 i;
	for(i=0 ; i<8;i++)
	{
		DIO_voidSetPinValue(i,DIO_HIGH);
		DIO_voidSetPinValue(i-1,DIO_LOW);
		STK_voidSetBusyWait(500000);
	}
}
void LED_voidAnimationRight(void)
{
	u8 j;
	for(j=7 ; j>0;j--)
	{
		DIO_voidSetPinValue(j+1,DIO_LOW);
		DIO_voidSetPinValue(j,DIO_HIGH);
		STK_voidSetBusyWait(500000);
		DIO_voidSetPinValue(j,DIO_LOW);

	}
}
void LED_voidAnimationIn(void)
{
	while(b > 0)
	{

		DIO_voidSetPinValue(a,DIO_HIGH);
		DIO_voidSetPinValue(b,DIO_HIGH);
		STK_voidSetBusyWait(500000);
		a++;
		b--;
		DIO_voidSetPinValue(a-1,DIO_LOW);
		DIO_voidSetPinValue(b+1,DIO_LOW);
	}
}
void LED_voidAnimationOut(void)
{
	while(b <= 3)
	{
		DIO_voidSetPinValue(a,DIO_HIGH);
		DIO_voidSetPinValue(b,DIO_HIGH);
		STK_voidSetBusyWait(500000);
		a--;
		b++;
		DIO_voidSetPinValue(a+1,DIO_LOW);
		DIO_voidSetPinValue(b-1,DIO_LOW);
	}
}

