/********************************/
/*Author :  Engy Tahoon 		*/
/*version:  V02					*/
/*Date 	 :	24 Aug 2020			*/
/********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"


void AFIO_voidSelectPortForEXTI(u8 Copy_u8Line,u8 Copy_u8Port)
{
	/*To select the register*/
	u8 Local_u8Indx = Copy_u8Line/4;
	/*To select the EXTI number*/
	u8 Local_u8EXTINb = Copy_u8Line%4;
	Local_u8EXTINb*= 4 ;
	
	/*Clear the 4-bits*/
	AFIO -> AFIO_EXTICR[Local_u8Indx] &= ~(0b1111 << Local_u8EXTINb);
	/*write on the register to remap the EXTI to the port I want*/
	AFIO -> AFIO_EXTICR[Local_u8Indx] |= (Copy_u8Port << Local_u8EXTINb);
}
