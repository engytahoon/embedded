
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void NVIC_voidInit(void)
{
	#define SCB_AIRCR	*((u32*)0xE000ED0C)
	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION;
}

void NVIC_voidEnableInt(u8 Copy_u8Idx)
{
	if (Copy_u8Idx <=31)
		NVIC_ISER0 = (1<<Copy_u8Idx);
	
	else if (Copy_u8Idx <=59)
	{
		Copy_u8Idx = Copy_u8Idx -32;
		NVIC_ISER1 = (1<<Copy_u8Idx);
	}
	
}

void NVIC_voidDisableInt(u8 Copy_u8Idx)
{
	if (Copy_u8Idx <=31)
		NVIC_ICER0 = (1<<Copy_u8Idx);
	
	else if (Copy_u8Idx <=59)
	{
		Copy_u8Idx = Copy_u8Idx -32;
		NVIC_ICER1 = (1<<Copy_u8Idx);
	}
}

void NVIC_voidSetPendingFlag(u8 Copy_u8Idx)	//for debgging or testing 
{
	if (Copy_u8Idx <=31)
		NVIC_ISPR0 = (1<<Copy_u8Idx);
	
	else if (Copy_u8Idx <=59)
	{
		Copy_u8Idx = Copy_u8Idx -32;
		NVIC_ISPR1 = (1<<Copy_u8Idx);
	}
}

void NVIC_voidClrPendingFlag(u8 Copy_u8Idx)
{
	if (Copy_u8Idx <=31)
		NVIC_ICPR0 = (1<<Copy_u8Idx);
	
	else if (Copy_u8Idx <=59)
	{
		Copy_u8Idx = Copy_u8Idx -32;
		NVIC_ICPR1 = (1<<Copy_u8Idx);
	}
}

u8 NVIC_u8GetActiveFlag(u8 Copy_u8Idx)
{
	u8 Local_u8Result;
	if (Copy_u8Idx <=31)
	{
		Local_u8Result= Get_BIT(NVIC_IABR0,Copy_u8Idx);
	}
	else if (Copy_u8Idx <=59)
	{
		Copy_u8Idx = Copy_u8Idx -32;
		Local_u8Result= Get_BIT(NVIC_IABR1,Copy_u8Idx);
		}
	return Local_u8Result;

}


void NVIC_voidSetInitPriority(u8 Copy_u8Idx, u8 Copy_u8Priority)
{
	if(Copy_u8Idx <60)
	{
		NVIC_IPR[Copy_u8Idx]= Copy_u8Priority;
	}
	else
	{
		/*Report Error*/
	}
}
