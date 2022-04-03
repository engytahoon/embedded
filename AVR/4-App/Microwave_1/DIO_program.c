/**********************************************/
/*Auther  :Amira                */
/*Version :V01                                */  
/*Date    :25/3/2020                          */
/*Descriotion : Program                       */ 
/**********************************************/

/** STD LIB DIRECTIVES **/
#include"STD_types.h"
#include"BIT_MATH.h"
#include"ERROR_STATUS.h"
/************************/

/** COMPONENT DIRECTIVES **/
#include"DIO_register.h"
#include"DIO_config.h"
#include"DIO_interface.h"
/**************************/

/************************** FUNCTIONS IMPLEMENTATION **************************/

ErrorStatus  DIO_enumSetPortDirection( u8 DIO_u8PortID,u8 DIO_u8Direction)
{
	ErrorStatus Local_error= ES_NOK;
	if(DIO_u8PortID < 4)
	{
		switch(DIO_u8PortID)
		{
			case DIO_U8_PORT_A: DIO_U8_DDRA = DIO_u8Direction; break;
			case DIO_U8_PORT_B: DIO_U8_DDRB = DIO_u8Direction; break;
			case DIO_U8_PORT_C: DIO_U8_DDRC = DIO_u8Direction; break;
			case DIO_U8_PORT_D: DIO_U8_DDRD = DIO_u8Direction; break;
		}
		Local_error= ES_OK;
	}
	else
	{
	Local_error= ES_OUT_OF_RANGE;	
	}
	return Local_error;
}  
/******************************************************************************/
ErrorStatus  DIO_enumSetPinDirection( u8 DIO_u8PortID,u8 DIO_u8PinID,u8 DIO_u8Direction)
{
	ErrorStatus Local_error= ES_NOK;
	if((DIO_u8PortID < 4)&&(DIO_u8PinID <8))
	{
		if(DIO_u8Direction==DIO_U8_OUTPUT)
		{
		switch(DIO_u8PortID)
		{
			case DIO_U8_PORT_A: SET_BIT(DIO_U8_DDRA,DIO_u8PinID); break;
			case DIO_U8_PORT_B: SET_BIT(DIO_U8_DDRB,DIO_u8PinID); break;
			case DIO_U8_PORT_C: SET_BIT(DIO_U8_DDRC,DIO_u8PinID); break;
			case DIO_U8_PORT_D: SET_BIT(DIO_U8_DDRD,DIO_u8PinID); break;
		}
		}else
		{
		 Local_error= ES_OUT_OF_RANGE;
		}
		Local_error= ES_OK;
	}
	else
	{
	Local_error= ES_OUT_OF_RANGE;	
	}
	return Local_error;
} 
/**************************************************************************/
ErrorStatus  DIO_enumSetPortValue( u8 DIO_u8PortID,u8 DIO_u8Value)
{
	ErrorStatus Local_error= ES_NOK;
	if(DIO_u8PortID < 4)
	{
		switch(DIO_u8PortID)
		{
			case DIO_U8_PORT_A: DIO_U8_PORTA =  DIO_u8Value; break;
			case DIO_U8_PORT_B: DIO_U8_PORTB =  DIO_u8Value; break;
			case DIO_U8_PORT_C: DIO_U8_PORTC =  DIO_u8Value; break;
			case DIO_U8_PORT_D: DIO_U8_PORTD =  DIO_u8Value; break;
		}
		Local_error= ES_OK;
	}
	else
	{
	Local_error= ES_OUT_OF_RANGE;	
	}
	return Local_error;
} 
/*********************************************************************************************************************/
ErrorStatus  DIO_enumSetPinValue( u8 DIO_u8PortID,u8 DIO_u8PinID,u8 DIO_u8Value)
{
	ErrorStatus Local_error= ES_NOK;
	if((DIO_u8PortID < 4)&&(DIO_u8PinID<8))
	{
		if(DIO_u8Value==DIO_U8_HIGH)
		switch(DIO_u8PortID)
		{
			case DIO_U8_PORT_A: SET_BIT(DIO_U8_PORTA,DIO_u8PinID); break;
			case DIO_U8_PORT_B: SET_BIT(DIO_U8_PORTB,DIO_u8PinID); break;
			case DIO_U8_PORT_C: SET_BIT(DIO_U8_PORTC,DIO_u8PinID); break;
			case DIO_U8_PORT_D: SET_BIT(DIO_U8_PORTD,DIO_u8PinID); break;
		}
		else if(DIO_u8Value==DIO_U8_LOW)
		{
			switch(DIO_u8PortID)
		   {
			case DIO_U8_PORT_A: CLR_BIT(DIO_U8_PORTA,DIO_u8PinID); break;
			case DIO_U8_PORT_B: CLR_BIT(DIO_U8_PORTB,DIO_u8PinID); break;
			case DIO_U8_PORT_C: CLR_BIT(DIO_U8_PORTC,DIO_u8PinID); break;
			case DIO_U8_PORT_D: CLR_BIT(DIO_U8_PORTD,DIO_u8PinID); break;
		   }
		   Local_error= ES_OK;
		}
		
	}
	else
	{
	Local_error= ES_OUT_OF_RANGE;	
	}
	return Local_error;
} 
/*********************************************************************************************************************/
u8  DIO_enumGetPinValue( u8 DIO_u8PortID,u8 DIO_u8PinID)
{
	ErrorStatus Local_error= ES_NOK;
	u8 Local_u8value = 0;
	if((DIO_u8PortID < 4)&&(DIO_u8PinID<8))
	{
		switch(DIO_u8PortID)
		{
			case DIO_U8_PORT_A: Local_u8value = GET_BIT(DIO_U8_PINA,DIO_u8PinID); break;
			case DIO_U8_PORT_B: Local_u8value = GET_BIT(DIO_U8_PINB,DIO_u8PinID); break;
			case DIO_U8_PORT_C: Local_u8value = GET_BIT(DIO_U8_PINC,DIO_u8PinID); break;
			case DIO_U8_PORT_D: Local_u8value = GET_BIT(DIO_U8_PIND,DIO_u8PinID); break;
		}
		Local_error= ES_OK;
	}
	else
	{
	Local_error= ES_OUT_OF_RANGE;	
	}
	return Local_u8value;
	
}
