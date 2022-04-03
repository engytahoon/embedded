

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

void __vector_14 (void) __attribute__((signal));
void __vector_13 (void) __attribute__((signal));


#define ENABLED			1
#define DISABLED		2

#define SYNCHRONOUS		1
#define ASYNCHRONOUS	2

#define PARITY_DISABLED	1
#define EVEN_PARITY		2
#define ODD_PARITY		3

#define ONE_STOP_BIT	1
#define TWO_STOP_BITS	2

#define FIVE_BITS		1
#define SIX_BITS		2
#define SEVEN_BITS		3
#define EIGHT_BITS		4

#define TRANSMIT_ON_RISING_RECEIVE_ON_FALLING	1
#define TRANSMIT_ON_FALLING_RECEIVE_ON_RISING	2



#endif /* USART_PRIVATE_H_ */
