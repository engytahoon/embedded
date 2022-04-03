/*****************************************/
/* Author  :  Engy Tahoon                */
/* Version :  V01                        */
/* Date    :  27 August 2020             */
/*****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTIC_private.h"
#include "SYSTIC_interface.h"
#include "SYSTIC_config.h"


static void (*STK_CallBack)(void);
u8 STK_Interval; 


void STK_voidInit(void)
{
	#if SYSTIC_CLK_SORCE == SYSTIC_AHB_8
		CLR_BIT(STK -> STK_CTRL,2);		// 2---> Clk source bit 
		
	#else
		SET_BIT(STK -> STK_CTRL,2);		// 2---> Clk source bit 
#endif
}
void STK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	STK -> STK_LOAD = Copy_u32Ticks;
	/*Start Timer */
	SET_BIT(STK -> STK_CTRL,0);		// 0--->Counter Enable bit 
	/*Waiting the timer to finish and the counter flag raised*/
	while((GET_BIT(STK-> STK_CTRL,16)) ==0);
	
	/*Disable Timer*/
	CLR_BIT(STK->STK_CTRL,0);	  // 0--->Counter Enable bit
	STK -> STK_LOAD = 0		;
	STK -> STK_VAL	= 0		;
}

void STK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	/* Disable Timer */
	CLR_BIT(STK->STK_CTRL,0);	  // 0--->Counter Enable bit
	STK -> STK_VAL	= 0		;
	
	/*wirte he ticks in load register*/
	STK -> STK_LOAD = Copy_u32Ticks;
	/*Start Timer*/
	SET_BIT(STK -> STK_CTRL,0);

	STK_CallBack = Copy_ptr;
	/*select single interval*/
	STK_Interval = SYSTIC_SINGLE_INTERVAL;
	/*Set interrupt flag */
	SET_BIT(STK -> STK_CTRL,1);		//1--->SYSTIC INT. bit
}

void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	/*wirte he ticks in load register*/
	STK -> STK_LOAD = Copy_u32Ticks;
	/*Start Timer*/
	SET_BIT(STK -> STK_CTRL,0);

	STK_CallBack = Copy_ptr;
	/*select single interval*/
	STK_Interval = SYSTIC_PERIOD_INTERVAL;
	/*Set interrupt flag */
	SET_BIT(STK -> STK_CTRL,1);		//1--->SYSTIC INT. bit
}

void STK_voidStopInterval(void)
{
	/*Stop interrupt flag*/
	CLR_BIT(STK -> STK_CTRL,1);		//1--->SYSTIC INT. bit
	/*Disable Timer*/
	CLR_BIT(STK->STK_CTRL,0);	  // 0--->Counter Enable bit
	STK -> STK_LOAD = 0		;
	STK -> STK_VAL	= 0		;

}

u32 STK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime ;
	Local_u32ElapsedTime = (STK-> STK_LOAD) - (STK-> STK_VAL);
	return Local_u32ElapsedTime;
}
u32 STK_u32GetRemainingTime(void)
{
	u32 Local_u32Remaining ;
	Local_u32Remaining = STK-> STK_VAL;
	return Local_u32Remaining;
}

void SysTick_Handler(void)
{
	if(STK_Interval == SYSTIC_SINGLE_INTERVAL)
	{
		/*Stop interrupt flag*/
		CLR_BIT(STK -> STK_CTRL,1);		//1--->SYSTIC INT. bit
		/*Disable Timer*/
		CLR_BIT(STK->STK_CTRL,0);	  // 0--->Counter Enable bit
		STK -> STK_LOAD = 0		;
		STK -> STK_VAL	= 0		;
	}
	STK_CallBack();
}
