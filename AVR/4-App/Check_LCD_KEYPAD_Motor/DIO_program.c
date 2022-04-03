/***********************************************************************************
Author : 	EnGy Tahoon
Date   :	29 June 2020
***********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include"DIO_interface.h"
#include "DIO_config.h"
#include "DIO_register.h"




Error_Status DIO_EnuSetPinDirection (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8PinDirection)  //هنا كنت بعرف البناية دي انبوت ولا اوتبوت
{		
		Error_Status state = OK ;
		if(Copy_u8PortNumber >= DIO_PORTA && Copy_u8PortNumber <= DIO_PORTD && Copy_u8PinNumber >= DIO_PIN_0 && Copy_u8PinNumber <= DIO_PIN_7 && (Copy_u8PinDirection == DIO_PIN_OUTPUT || Copy_u8PinDirection == DIO_PIN_INPUT))
		{
			switch(Copy_u8PortNumber)
			{
				case DIO_PORTA :
				 if(Copy_u8PinDirection == DIO_PIN_INPUT)
				 {
					CLR_BIT(DDRA,Copy_u8PinNumber);
				 }
				 else
				 {
					SET_BIT(DDRA,Copy_u8PinNumber);
				 }
				break; 
				case DIO_PORTB :
				 if(Copy_u8PinDirection == DIO_PIN_INPUT)
				 {
					CLR_BIT(DDRB,Copy_u8PinNumber);
				 }
				 else
				 {
					SET_BIT(DDRB,Copy_u8PinNumber);
				 }
				break;
				
				case DIO_PORTC :
				if(Copy_u8PinDirection == DIO_PIN_INPUT)
				{
					CLR_BIT(DDRC,Copy_u8PinNumber);
				}
				else
				{
					SET_BIT(DDRC,Copy_u8PinNumber);
				}
				break;
				
				case DIO_PORTD :
				if(Copy_u8PinDirection == DIO_PIN_INPUT)
				{
					CLR_BIT(DDRD,Copy_u8PinNumber);
				}
				else
				{
					SET_BIT(DDRD,Copy_u8PinNumber);
				}
				break;
			}
		}
		else
		{
			state = OUTOFRANGE;
		}
return state;
}
Error_Status DIO_EnuSetPinValue (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8PinValue)
{
	Error_Status state = OK ;
		if(Copy_u8PortNumber >= DIO_PORTA && Copy_u8PortNumber <= DIO_PORTD && Copy_u8PinNumber >= DIO_PIN_0 && Copy_u8PinNumber <= DIO_PIN_7 && (Copy_u8PinValue == DIO_PIN_HIGH || Copy_u8PinValue == DIO_PIN_LOW))
		{
			switch(Copy_u8PortNumber)
			{
				case DIO_PORTA :
				 if(Copy_u8PinValue == DIO_PIN_LOW)
				 {
					CLR_BIT(PORTA,Copy_u8PinNumber);
				 }
				 else
				 {
					SET_BIT(PORTA,Copy_u8PinNumber);
				 }
				break;
				
				case DIO_PORTB :
				 if(Copy_u8PinValue == DIO_PIN_LOW)
				 {
					CLR_BIT(PORTB,Copy_u8PinNumber);
				 }
				 else
				 {
					SET_BIT(PORTB,Copy_u8PinNumber);
				 }
				break;
				
				case DIO_PORTC :
				 if(Copy_u8PinValue == DIO_PIN_LOW)
				 {
					CLR_BIT(PORTC,Copy_u8PinNumber);
				 }
				 else
				 {
					SET_BIT(PORTC,Copy_u8PinNumber);
				 } 
				break;
				
				case DIO_PORTD:
				 if(Copy_u8PinValue == DIO_PIN_LOW)
				 {
					CLR_BIT(PORTD,Copy_u8PinNumber);
				 }
				 else
				 {
					SET_BIT(PORTD,Copy_u8PinNumber);
				 }
				break;
			}
		}
		else
		{
			state = OUTOFRANGE;
		}
return state;
}

Error_Status DIO_EnuGetPinValue (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 * Copy_Pu8PinValue)
{
	Error_Status state = OK ;
		if(Copy_u8PortNumber >= DIO_PORTA && Copy_u8PortNumber <= DIO_PORTD && Copy_u8PinNumber >= DIO_PIN_0 && Copy_u8PinNumber <= DIO_PIN_7 )
		{
			if(* Copy_Pu8PinValue != NULL)
			{
				switch(Copy_u8PortNumber)
				{
					case DIO_PORTA :  * Copy_Pu8PinValue = GET_BIT(PINA,Copy_u8PinNumber); break ;
					case DIO_PORTB :  * Copy_Pu8PinValue = GET_BIT(PINB,Copy_u8PinNumber); break ;
					case DIO_PORTC :  * Copy_Pu8PinValue = GET_BIT(PINC,Copy_u8PinNumber); break ;
					case DIO_PORTD :  * Copy_Pu8PinValue = GET_BIT(PIND,Copy_u8PinNumber); break ;
					
				}
			}
			else
			{
				state = NULL_POINTER;
			}
		}

		else
		{
			state = OUTOFRANGE;
		}
return state;
}

Error_Status DIO_EnuSetPortDirection (u8 Copy_u8PortNumber  , u8 Copy_u8PortDirection)
{
	Error_Status state = OK;
	switch(Copy_u8PortNumber)
	{
		case DIO_PORTA :   DDRA =Copy_u8PortDirection ; break;
		case DIO_PORTB :   DDRB =Copy_u8PortDirection ; break;
		case DIO_PORTC :   DDRC =Copy_u8PortDirection ; break;
		case DIO_PORTD :   DDRD =Copy_u8PortDirection ; break;
		default : state = OUTOFRANGE ;
	}
	return state ;
}

Error_Status DIO_EnuSetPortValue (u8 Copy_u8PortNumber  , u8 Copy_u8PortValue)
{
	Error_Status state = OK;
	switch(Copy_u8PortNumber)
	{
		case DIO_PORTA :   PORTA =Copy_u8PortValue ; break;
		case DIO_PORTB :   PORTB =Copy_u8PortValue ; break;
		case DIO_PORTC :   PORTC =Copy_u8PortValue ; break;
		case DIO_PORTD :   PORTD =Copy_u8PortValue ; break;
		default : state = OUTOFRANGE ;
	}
	return state ;
}

Error_Status DIO_EnuGetPortValue (u8 Copy_u8PortNumber  , u8 * Copy_Pu8PortValue)
{
	Error_Status state = OK ;
	if (* Copy_Pu8PortValue != NULL)
	{
		switch(Copy_u8PortNumber)
		{
			case DIO_PORTA :  	*Copy_Pu8PortValue = PINA ; break ;
			case DIO_PORTB :  	*Copy_Pu8PortValue = PINB ; break ;
			case DIO_PORTC :  	*Copy_Pu8PortValue = PINC ; break ;
			case DIO_PORTD :  	*Copy_Pu8PortValue = PIND ; break ;
			default : state = OUTOFRANGE ;

		}
	}
	else
	{
		state = NULL_POINTER;
	}
return state ;
}
