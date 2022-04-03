/*****************************************/
/* Author  :  Engy Tahoon                */
/* Version :  V01                        */
/* Date    :  27 August 2020             */
/*****************************************/

#ifndef SYSTIC_INTERFACE_H
#define SYSTIC_INTERFACE_H

/*	Apply clock choice from config file 
	Disable systick interrupt
	Disable systick*/
void STK_voidInit(void);
/* Synch. function */
void STK_voidSetBusyWait(u32 Copy_u32Ticks);
/*ASynch. function*/
void STK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void));
/*ASynch. function*/
void STK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void));

void STK_voidStopInterval(void);

u32 STK_u32GetElapsedTime(void);
u32 STK_u32GetRemainingTime(void);


#endif