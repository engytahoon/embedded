/***********************************************************************************
Author : 	EnGy Tahoon
Date   :	29 June 2020
***********************************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* Macro for PORTS*/
#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

/* Macro for PIN number*/
#define DIO_PIN_0		0
#define DIO_PIN_1		1
#define DIO_PIN_2		2
#define DIO_PIN_3		3
#define DIO_PIN_4		4
#define DIO_PIN_5		5
#define DIO_PIN_6		6
#define DIO_PIN_7		7

/* macro for PIN Directions */
#define DIO_PIN_OUTPUT		1
#define DIO_PIN_INPUT		0

/* macro for PORT Directions */
#define DIO_PORT_OUTPUT		0xff     //كتبتها كدا عشان اخلي كل البينز ب 1
#define DIO_PORT_INPUT		0x00


/* macro for PIN Value */
#define DIO_PIN_HIGH		1
#define DIO_PIN_LOW			0

/* macro for PORT Value */
#define DIO_PORT_HIGH		0xff     //كتبتها كدا عشان اخلي كل البينز ب 1
#define DIO_PORT_LOW		0x00


Error_Status DIO_EnuSetPinDirection (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8PinDirection);  //هنا كنت بعرف البناية دي انبوت ولا اوتبوت

Error_Status DIO_EnuSetPinValue (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8PinValue);

Error_Status DIO_EnuGetPinValue (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 * Copy_Pu8PinValue);

Error_Status DIO_EnuSetPortDirection (u8 Copy_u8PortNumber  , u8 Copy_u8PortDirection);  

Error_Status DIO_EnuSetPortValue (u8 Copy_u8PortNumber  , u8 Copy_u8PortValue);

Error_Status DIO_EnuGetPortValue (u8 Copy_u8PortNumber  , u8 * Copy_Pu8PortValue);






#endif