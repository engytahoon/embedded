#include "STD_types.h"

void Delay_ms(u32 DelayValue)
{
	u32 i;
	u32 counts=370*DelayValue;
	for(i=0;i<counts;i++)
	{
		asm("nop");
	}	
}
void Delay_us(u32 DelayValue)
{
	u32 i;
	u32 counts=(((DelayValue-47)*375)/1000);
	for(i=0;i<counts;i++)
	{
		asm("nop");
	}
}
