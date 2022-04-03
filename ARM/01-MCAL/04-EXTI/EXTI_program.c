/********************************/
/*Author :  Engy Tahoon 		*/
/*version:  V02					*/
/*Date 	 :	22 Aug 2020			*/
/********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

static void (*EXTI0_CallBack) (void);

void MEXTI_voidInit()
{
	#if EXTI_MODE	== RISING
		SET_BIT(EXTI -> EXTI_RTSR , EXTI_LINE);
	#elif EXTI_MODE == FALLING
		SET_BIT(EXTI -> EXTI_FTSR , EXTI_LINE);
	#elif EXTI_MODE == ON_CHANGE
		SET_BIT(EXTI -> EXTI_RTSR , EXTI_LINE);
		SET_BIT(EXTI -> EXTI_FTSR , EXTI_LINE);	
	#else 	#error "Wrong Mode and Line Choice"
	#endif
	/*Disable interrupt*/
	CLR_BIT(EXTI -> EXTI_IMR, Copy_u8Line);

}
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> EXTI_IMR, Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI -> EXTI_IMR, Copy_u8Line);

}
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> EXTI_IMR  , Copy_u8Line );
	SET_BIT(EXTI -> EXTI_SWIER, Copy_u8Line );	
}
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING :	SET_BIT(EXTI -> EXTI_RTSR , EXTI_LINE);break;
		case FALLING:	SET_BIT(EXTI -> EXTI_FTSR , EXTI_LINE);break;
		case ON_CHANGE:	SET_BIT(EXTI -> EXTI_RTSR , EXTI_LINE);
						SET_BIT(EXTI -> EXTI_FTSR , EXTI_LINE);break;
	}
}
void MEXTI_voidClearPendingFlag(u8 Copy_u8Line)
{
	SET_BIT(EXTI-> EXTI_PR , copy_u8Line );
}
/*For EXTI0 */
void EXTI0_VidSetCallBack( void (*ptr) (void) ){

	EXTI0_CallBack = ptr;
}
void EXTI0_IRQHandler(void){
	
	EXTI0_CallBack();
	/*Clear pending flag by writing 1 */
	SET_BIT( EXTI->PR , 0 );
}