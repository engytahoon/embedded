#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"





void DIO_voidSetPinMode(u8 Copy_u8PinNb, u8 Copy_u8PinMode)
{
	/* Check that the pin nb within the range*/
	if (Copy_u8PinNb <= DIO_PIN34)
	{
		u8 Local_u8PortNb = Copy_u8PinNb / 16 ;
		u8 Local_u8PinNb  = Copy_u8PinNb % 16 ;

		switch (Local_u8PortNb)
		{
		case PORTA:
			if (Copy_u8PinMode == DIO_INPUT_PULL_UP)
			{
				SET_BIT(GPIOA -> GPIO_ODR , Local_u8PinNb);
			}
			else if (Copy_u8PinMode == DIO_INPUT_PULL_DOWN)
			{
				CLR_BIT(GPIOA -> GPIO_ODR , Local_u8PinNb);
			}
			if(Local_u8PinNb < 7)
			{
				ASSIGN_NIBBLE_VALUE(GPIOA -> GPIO_CRL, Local_u8PinNb, Copy_u8PinMode); break;

			}
			else if (Local_u8PinNb <= 15)
			{
				Local_u8PinNb -= 8;
				ASSIGN_NIBBLE_VALUE(GPIOA -> GPIO_CRH, Local_u8PinNb, Copy_u8PinMode); break;

			}
			break;

		case PORTB:
			if (Copy_u8PinMode == DIO_INPUT_PULL_UP)
			{
				SET_BIT(GPIOB -> GPIO_ODR , Local_u8PinNb);
			}
			else if (Copy_u8PinMode == DIO_INPUT_PULL_DOWN)
			{
				CLR_BIT(GPIOB -> GPIO_ODR , Local_u8PinNb);
			}

			if(Local_u8PinNb < 7)
			{
				ASSIGN_NIBBLE_VALUE(GPIOB -> GPIO_CRL, Local_u8PinNb, Copy_u8PinMode); break;

			}
			else if (Local_u8PinNb <= 15)
			{
				Local_u8PinNb -= 8;
				ASSIGN_NIBBLE_VALUE(GPIOB -> GPIO_CRH, Local_u8PinNb, Copy_u8PinMode); break;

			}
			break;
		case PORTC:
			if (Copy_u8PinMode == DIO_INPUT_PULL_UP)
			{
				SET_BIT(GPIOC -> GPIO_ODR , Local_u8PinNb);
			}
			else if (Copy_u8PinMode == DIO_INPUT_PULL_DOWN)
			{
				CLR_BIT(GPIOC -> GPIO_ODR , Local_u8PinNb);
			}

			if (Local_u8PinNb >= 13 && Local_u8PinNb <= 15)
			{
				Local_u8PinNb -= 8;
				ASSIGN_NIBBLE_VALUE(GPIOC -> GPIO_CRH, Local_u8PinNb, Copy_u8PinMode); break;
			}
			break;

		}
	}
}

void DIO_voidSetPinValue(u8 Copy_u8PinNb, u8 Copy_u8Value)
{
	if ((Copy_u8PinNb <= DIO_PIN34) && ((Copy_u8Value == DIO_HIGH) || (Copy_u8Value == DIO_LOW)))
	{
		u8 Local_u8PortNb = Copy_u8PinNb / 16;
		u8 Local_u8PinNb = Copy_u8PinNb % 16;

		switch (Local_u8PortNb)
		{

		case PORTA:
			if(Copy_u8Value == DIO_HIGH)
			{
				//				SET_BIT(GPIOA->GPIO_ODR , Local_u8PinNb);
				GPIOA-> GPIO_BSRR = 1 << Local_u8PinNb ;

			}
			else
			{
				//				CLR_BIT(GPIOA->GPIO_ODR , Local_u8PinNb);
				GPIOA-> GPIO_BRR = 1 << Local_u8PinNb ;

			}
			break;
		case PORTB:
			if(Copy_u8Value == DIO_HIGH)
			{
				//				SET_BIT(GPIOB->GPIO_ODR , Local_u8PinNb);
				GPIOB-> GPIO_BSRR = 1 << Local_u8PinNb ;
			}
			else
			{
				//				CLR_BIT(GPIOB->GPIO_ODR , Local_u8PinNb);
				GPIOB-> GPIO_BRR = 1 << Local_u8PinNb ;
			}
			break;
		case PORTC:
			if(Local_u8PinNb >= 13 && Local_u8PinNb <= 15)
			{
				if(Copy_u8Value == DIO_HIGH)
				{
					//					SET_BIT(GPIOC->GPIO_ODR , Local_u8PinNb);
					GPIOC-> GPIO_BSRR = 1 << Local_u8PinNb ;
				}
				else
				{
					//					CLR_BIT(GPIOC->GPIO_ODR , Local_u8PinNb);
					GPIOC-> GPIO_BSRR = 1 << Local_u8PinNb ;

				}
			}
			break;
		}
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8PinNb)
{
	u8 Local_u8Value = 0;
	if (Copy_u8PinNb <= DIO_PIN34)
	{
		u8 Local_u8PortNb = Copy_u8PinNb / 16;
		u8 Local_u8PinNb  = Copy_u8PinNb % 16;

		switch (Local_u8PortNb)
		{
		case PORTA:
			Local_u8Value = GET_BIT(GPIOA->GPIO_IDR , Local_u8PinNb);
			break;
		case PORTB:
			Local_u8Value = GET_BIT(GPIOB->GPIO_IDR , Local_u8PinNb);
			break;
		case PORTC:
			Local_u8Value = GET_BIT(GPIOC->GPIO_IDR , Local_u8PinNb);
			break;
		}
	}
	return Local_u8Value;
}

void DIO_voidLock(u8 Copy_u8PinNb)
{
	u32 Local_u8Value =0x00010000;
	u8 Local_u8PortNb = Copy_u8PinNb / 16;
	u8 Local_u8PinNb  = Copy_u8PinNb % 16;

	switch(Local_u8PortNb)
	{
	case PORTA:
		Local_u8Value |= (1<< Local_u8PinNb);
		/*Set LCKK bit*/
		GPIOA->GPIO_LCKR=Local_u8Value;
		/*Reset LCKK bit*/
		GPIOA->GPIO_LCKR= (1<< Local_u8PinNb);
		/*Set LCKK bit*/
		GPIOA->GPIO_LCKR=Local_u8Value;
		/*Read LCKK bit*/
		Local_u8Value = GPIOA->GPIO_LCKR;
		/*Read LCKK bit*/
		Local_u8Value = GPIOA->GPIO_LCKR;
		break;

	case PORTB:
		Local_u8Value |= (1<< Local_u8PinNb);
		/*Set LCKK bit*/
		GPIOB->GPIO_LCKR=Local_u8Value;
		/*Reset LCKK bit*/
		GPIOB->GPIO_LCKR= (1<< Local_u8PinNb);
		/*Set LCKK bit*/
		GPIOB->GPIO_LCKR=Local_u8Value;
		/*Read LCKK bit*/
		Local_u8Value = GPIOB->GPIO_LCKR;
		/*Read LCKK bit*/
		Local_u8Value = GPIOB->GPIO_LCKR;
		break;

	case PORTC:
		Local_u8Value |= (1<< Local_u8PinNb);
		/*Set LCKK bit*/
		GPIOC->GPIO_LCKR=Local_u8Value;
		/*Reset LCKK bit*/
		GPIOC->GPIO_LCKR= (1<< Local_u8PinNb);
		/*Set LCKK bit*/
		GPIOC->GPIO_LCKR=Local_u8Value;
		/*Read LCKK bit*/
		Local_u8Value = GPIOC->GPIO_LCKR;
		/*Read LCKK bit*/
		Local_u8Value = GPIOC->GPIO_LCKR;
		break;
	}
}
