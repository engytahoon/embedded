/********************************/
/*Author :  Engy Tahoon 		*/
/*version:  V02					*/
/*Date 	 :	22 Aug 2020			*/
/********************************/

#ifndef EXTI_INTRFACE_H
#define EXTI_INTRFACE_H

void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidClearPendingFlag(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);

#endif