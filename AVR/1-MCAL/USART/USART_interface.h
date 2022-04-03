

/*Preprocessor File Guard*/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

Error_Status USART_Init(void);
u8 USART_u8ReceiveData(void);
void USART_voidSendData(u8 Copy_u8Data);

void USART_voidSendString(u8 *ptr);
Error_Status USART_ReceiveStringSynch(u8* Copy_pu8String, u8 Copy_u8MessageSize);
#endif /* USART_INTERFACE_H_ */
