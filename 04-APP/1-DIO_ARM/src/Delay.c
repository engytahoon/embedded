/*
 * Delay.c
 *
 *  Created on: Feb 12, 2020
 *      Author: DELL
 */

#include <STD_TYPES.h>

#include "Delay.h"

void _delay_us(u32 value)
{
	u16 i;
	//value = value-(T1+T2+T3) > time taken be default for context switching and reading this order
	value = value-(5+8+15);
	u32 count = value /2;
	count = count - (count/4);
	for(i=0 ; i<count ; i++)
	{
		asm("NOP");
	}
}

void _delay_ms (u16 value)
{
	u16 i,j;
	for(j=0 ; j<value ; j++)
	{
		for(i=0 ; i<400 ; i++)
		{
			asm("NOP");
		}
	}
}
