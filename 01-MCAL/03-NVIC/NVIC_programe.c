/********************************/
/*Author :	Engy Tahoon 		*/
/*version:  V02					*/
/*Date 	 :	22 Aug 2020			*/
/********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void NVIC_voidInit(void)
{
	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION;
}

void NVIC_voidEnableInt(u8 Copy_u8Idx)
{
	if (Copy_u8Idx <=31)
		NVIC -> NVIC_ISER[0] = (1<<Copy_u8Idx);
	
	else if (Copy_u8Idx <=59)
	{
		Copy_u8Idx = Copy_u8Idx -32;
		NVIC -> NVIC_ISER[1] = (1<<Copy_u8Idx);
	}
	
}

void NVIC_voidDisableInt(u8 Copy_u8Idx)
{
	if (Copy_u8Idx <=31)
		NVIC -> NVIC_ICER[0] = (1<<Copy_u8Idx);
	
	else if (Copy_u8Idx <=59)
	{
		Copy_u8Idx = Copy_u8Idx -32;
		NVIC -> NVIC_ICER[1] = (1<<Copy_u8Idx);
	}
}

void NVIC_voidSetPendingFlag(u8 Copy_u8Idx)	//for debgging or testing 
{
	if (Copy_u8Idx <=31)
		NVIC -> NVIC_ISPR[0] = (1<<Copy_u8Idx);
	
	else if (Copy_u8Idx <=59)
	{
		Copy_u8Idx = Copy_u8Idx -32;
		NVIC -> NVIC_ISPR[1] = (1<<Copy_u8Idx);
	}
}

void NVIC_voidClrPendingFlag(u8 Copy_u8Idx)
{
	if (Copy_u8Idx <=31)
		NVIC -> NVIC_ICPR[0] = (1<<Copy_u8Idx);
	
	else if (Copy_u8Idx <=59)
	{
		Copy_u8Idx = Copy_u8Idx -32;
		NVIC -> NVIC_ICPR[1] = (1<<Copy_u8Idx);
	}
}

u8 NVIC_u8GetActiveFlag(u8 Copy_u8Idx)
{
	u8 Local_u8Result;
	if (Copy_u8Idx <=31)
	{
		Local_u8Result= Get_BIT(NVIC -> NVIC_IABR[0],Copy_u8Idx);
	}
	else if (Copy_u8Idx <=59)
	{
		Copy_u8Idx = Copy_u8Idx -32;
		Local_u8Result= Get_BIT(NVIC -> NVIC_IABR[1],Copy_u8Idx);
		}
	return Local_u8Result;

}


void NVIC_voidSetInitPriority(u8 Copy_u8Idx, u8 Copy_u8Priority)
{
	if(Copy_u8Idx <60)
	{
		NVIC -> NVIC_IPR[Copy_u8Idx]= Copy_u8Priority << 4;
	}
	else
	{
		/*Report Error*/
	}
}
