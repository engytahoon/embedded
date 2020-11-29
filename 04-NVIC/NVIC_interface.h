#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void NVIC_voidInit(void);
void NVIC_voidEnableInt(u8 Copy_u8Idx);
void NVIC_voidDisableInt(u8 Copy_u8Idx);

void NVIC_voidSetPendingFlag(u8 Copy_u8Idx);
void NVIC_voidClrPendingFlag(u8 Copy_u8Idx);

void NVIC_voidSetInitPriority(u8 Copy_u8Idx, u8 Copy_u8Priority);







#endif