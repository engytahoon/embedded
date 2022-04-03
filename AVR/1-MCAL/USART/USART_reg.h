

#ifndef USART_REG_H_
#define USART_REG_H_

/*uSART Data Register*/
#define UDR		 *((volatile u8*)0x2C)

/*USART Control and status register(A)*/
#define UCSRA	 *((volatile u8*)0x2B)
#define UCSRA_RXC	7	/*Receive Complete Flag*/
#define UCSRA_TXC	6	/*Transmit Complete Flag*/
#define UCSRA_UDRE	5	/*Data Register Empty Flag*/
#define UCSRA_FE	4	/*Frame Error*/
#define UCSRA_DOR	3	/*Data Overrun*/
#define UCSRA_PE	2	/*Parity Error*/
#define UCSRA_U2X	1	/*Double Transmission Speed*/
#define UCSRA_MPCM	0	/*Multi Processor Communication Mode*/

/*Usart Control And Status Register (B)*/
#define UCSRB	 *((volatile u8*)0x2A)
#define UCSRB_RXCIE	7	/*RX Complete Interrupt Enable*/
#define UCSRB_TXCIE	6	/*Tx Complete Interrupt Enable*/
#define UCSRB_UDRIE	5	/*Data Register Empty Interrupt Enable*/
#define UCSRB_RXEN	4	/*Receiver Enable*/
#define UCSRB_TXEN	3	/*Transmitter Enable*/
#define UCSRB_UCSZ2	2	/*Character Size Bit 2*/
#define UCSRB_RXB8	1	/*Receiving Bit 8*/
#define UCSRB_TXB8	0	/*Transmitter Bit 8*/


/*Usart Control And Status Register (C)*/
#define UCSRC	 	 *((volatile u8*)0x40)
#define UCSRC_URSEL  7        /*Register Select*/
#define UCSRC_UMSEL	 6        /*Mode Select*/
#define UCSRC_UPM1	 5        /*Parity Mode bit 1*/
#define UCSRC_UPM0	 4        /*Parity Mode bit 0*/
#define UCSRC_USBS	 3        /*Stop Bit Select*/
#define UCSRC_UCSZ1	 2        /*Character Size Bit 1*/
#define UCSRC_UCSZ0	 1        /*Character Size bit 0*/
#define UCSRC_UCPOL	 0        /*Clock Polarity*/


/*USART Baud Rate Registers*/
#define UBRRH	 	*((volatile u8*)0x40)
#define UBRRL	 	*((volatile u8*)0x29)

#endif /* USART_REG_H_ */
