/*****************************************/
/* Author  :  Engy Tahoon                */
/* Version :  V01                        */
/* Date    :  27 August 2020             */
/*****************************************/

#ifndef SYSTIC_PRIVATE_H
#define SYSTIC_PRIVATE_H

typedef struct
{
	volatile u32 STK_CTRL ;
	volatile u32 STK_LOAD ;
	volatile u32 STK_VAL  ;
	volatile u32 STK_CALIB;
}STK_t;

#define STK		((volatile STK_t*)0xE000E010)


#define SYSTIC_AHB 		0
#define SYSTIC_AHB_8	1

#define SYSTIC_SINGLE_INTERVAL	0
#define SYSTIC_PERIOD_INTERVAL	1

#endif