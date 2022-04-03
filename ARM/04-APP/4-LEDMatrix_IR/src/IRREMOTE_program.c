/*
 * IRREMOTE_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 3step
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_INTERFACE.h"
#include "SYSTIC_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"

#include "IRREMOTE_config.h"
#include "IRREMOTE_interface.h"
#include "IRREMOTE_private.h"

volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;

void (*IR_CallBack)(u8 Copy_u8Key);

void IR_voidInit(void)
{
	/*make the pin of IR remote input pin */
	MGPIO_VidSetPinDirection(IR_PORT, IR_PIN ,INPUT_FLOATING);
	STK_voidInit();

	/*init the EXTI*/
	AFIO_voidSelectPortForEXTI(IR_EXTI_LINE, IR_PORT);
	MEXTI_voidInit();
	MEXTI_voidEnableEXTI(IR_EXTI_LINE);
	NVIC_voidEnableInt(IR_NVIC_NUM);
	EXTI0_VidSetCallBack(IR_u8GetFrame);

}
void IR_u8GetFrame(void)
{
	if(u8StartFlag==0)
	{
		STK_voidSetIntervalSingle(1000000,IR_voidGetCode);
		u8StartFlag=1;
	}
	else
	{
		u32FrameData[u8EdgeCounter]=STK_u32GetElapsedTime();
		STK_voidSetIntervalSingle(1000000,IR_voidGetCode);
		u8EdgeCounter++;
	}
}
void IR_voidGetCode(void)
{
	u8 i;
	u8Data=0;
	/* check if start bit is send 13500 micro sec*/
	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for (i=0;i<8;i++)
		{
			/*check the data if 2250 u sec that meant the remote send 1 and if 1125u sec the remote send 0 */
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) )
			{
				SET_BIT(u8Data,i);
			}

			else
			{
				CLR_BIT(u8Data,i);
			}
		}
		IR_CallBack(u8Data);
	}
	else
	{
		/* Invalid Frame */
	}

	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;

}

void IR_voidSetCallBack(void(*ptr)(u8 Copy_u8Key))
{
	IR_CallBack = ptr;
}
//u8 IR_u8GETButton(void)
//{
//	return u8Data;
//}
