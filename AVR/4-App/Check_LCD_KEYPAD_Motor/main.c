/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 3step
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY.h"
#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "Keypad_interface.h"
#include "motor.h"

	u8 x=0;

int main(void)
{
	CLCD_voidInit();
	KEYPAD_voidInit();
	DC_Motor_Init();
	DC_Motor_BackwardDir();
Delay_ms(100);
CLCD_GoToXY(1,5);
		LCD_Num(3);
	while(1)
	{
		x= KPD_u8GetPressedKey();

		if(x !=0)
		{
			CLCD_voidSendData(x);
		}
		DC_Motor_ForwardDir();
		Delay_ms(10);

	}
return 0;
}

