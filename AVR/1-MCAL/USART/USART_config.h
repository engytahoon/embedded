
#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/*Options: 1- ENABLED
 * 		   2- DISABLED
 **/
#define USART_u8_DOUBLE_ASYNCHRONOUS_SPEED_ENABLE	DISABLED


/*Options: 1- ENABLED
 * 		   2- DISABLED
 **/
#define USART_u8_RECEIVE_COMP_INT_ENABLE			DISABLED

/*Options: 1- ENABLED
 * 		   2- DISABLED
 **/
#define USART_u8_TRANSMIT_COMP_INT_ENABLE			DISABLED

/*Options: 1- ENABLED
 * 		   2- DISABLED
 **/
#define USART_u8_DATA_REG_EMPTY_INT_ENABLE			DISABLED

/*Options: 1- ENABLED
 * 		   2- DISABLED
 **/
#define USART_u8_RECEIVER_ENABLE					ENABLED

/*Options: 1- ENABLED
 * 		   2- DISABLED
 **/
#define USART_u8_TRANSMITTER_ENABLE					ENABLED

/*Options: 1- SYNCHRONOUS
 * 		   2- ASYNCHRONOUS
 **/
#define USART_u8_MODE_SELECT						ASYNCHRONOUS

/*Options: 1- PARITY_DISABLED
 * 		   2- EVEN_PARITY
 * 		   3- ODD_PARITY
 **/
#define USART_u8_PARITY_MODE						PARITY_DISABLED

/*Options: 1- ONE_STOP_BIT
 * 		   2- TWO_STOP_BITS
 **/
#define USART_u8_STOP_BITS_NUMBER					ONE_STOP_BIT

/*Options: 1- FIVE_BITS
 * 		   2- SIX_BITS
 * 		   3- SEVEN_BITS
 * 		   4- EIGHT_BITS
 **/
#define USART_u8_CHARACTER_SIZE						EIGHT_BITS

/*Options: 1- TRANSMIT_ON_RISING_RECEIVE_ON_FALLING
 * 		   2- TRANSMIT_ON_FALLING_RECEIVE_ON_RISING
 **/
#define USART_u8_CLOCK_POLARITY		TRANSMIT_ON_RISING_RECEIVE_ON_FALLING

#define FCPU										8000000UL
#define USART_BAUD_RATE								9600UL
#endif