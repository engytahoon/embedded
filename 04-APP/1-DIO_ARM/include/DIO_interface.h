/********************************/
/* Author  :Engy				*/
/*version:  V01					*/
/*Date :18 AUG 2020				*/
/********************************/


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* Macros for Ports */
#define PORTA		0
#define PORTB		1
#define PORTC		2

/* Macros for Pins */
#define DIO_PIN0		0		//first Pin in PORTA
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7
#define DIO_PIN8		8
#define DIO_PIN9		9
#define DIO_PIN10		10
#define DIO_PIN11		11
#define DIO_PIN12		12
#define DIO_PIN13		13
#define DIO_PIN14		14
#define DIO_PIN15		15		// Last pin in PORTA
#define DIO_PIN16		16		//First pin in PORTB
#define DIO_PIN17		17
#define DIO_PIN18		18
#define DIO_PIN19		19
#define DIO_PIN20		20
#define DIO_PIN21		21
#define DIO_PIN22		22
#define DIO_PIN23		23
#define DIO_PIN24		24
#define DIO_PIN25		25
#define DIO_PIN26		26
#define DIO_PIN27		27
#define DIO_PIN28		28
#define DIO_PIN29		29
#define DIO_PIN30		30
#define DIO_PIN31		31		//Last pin in PORTB
#define DIO_PIN32		45   	//13+32  pin 13 in PORTC
#define DIO_PIN33		46		//pin 14 in PORTC
#define DIO_PIN34		47		//pin 15 in PORTC

/* Macros for pin direction */

/* OUTPUT with freq 2MHz Speed*/
#define DIO_OUTPUT_2M_PP	0b0010		//00 for General purpose output push pull, 10 for output with max 2MHz
#define DIO_OUTPUT_2M_OD	0b0110		//01 for General purpose output open drain, 10 for output with max 2MHz
#define DIO_OUTPUT_2M_AFPP	0b1010		//10 for Alternate function output push pull, 10 for output with max 2MHz
#define DIO_OUTPUT_2M_AFOD	0b1110		//11 for Alternate function output open drain, 10 for output with max 2MHz

/* OUTPUT with freq 10M */
#define DIO_OUTPUT_10M_PP	0b0001		//01 for output with max 10MHz
#define DIO_OUTPUT_10M_OD	0b0101
#define DIO_OUTPUT_10M_AFPP	0b1001
#define DIO_OUTPUT_10M_AFOD	0b1101

/* OUTPUT with freq 50M */
#define DIO_OUTPUT_50M_PP	0b0011
#define DIO_OUTPUT_50M_OD	0b0111
#define DIO_OUTPUT_50M_AFPP	0b1011
#define DIO_OUTPUT_50M_AFOD	0b1111

/* INPUT */
#define DIO_INPUT_ANALOG	0b0000
#define DIO_INPUT_FLOATING	0b0100
#define DIO_INPUT_PULL_UP	0b1000
#define DIO_INPUT_PULL_DOWN	0b1100

/* Macros for pin value*/
#define DIO_HIGH		1
#define DIO_LOW			0


void DIO_voidInit(void);
void DIO_voidSetPinMode(u8 Copy_u8PinNb, u8 Copy_u8PinMode);
void DIO_voidSetPinValue(u8 Copy_u8PinNb, u8 Copy_u8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8PinNb);

#endif
