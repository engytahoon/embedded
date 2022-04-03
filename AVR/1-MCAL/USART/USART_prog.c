

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_private.h"
#include "USART_reg.h"
#include "USART_config.h"
#include "USART_interface.h"

/*Transmitted String Array*/
const static char* USART_pchTransmisttedString=NULL;

/*Transmission callback notification function*/
static void (*USART_pfTransmissionCallBack) (void) =NULL;

/*Transmission index*/
static u8 USART_u8TransmissionIndex;

/*Received Array*/
static u8* USART_pu8ReceivedMessgeArray=NULL;

/*Receiving callback notification function*/
static void (*USART_pfReceivingCallBack) (void)=NULL;

/*Receiving index*/
static u8 USART_u8ReceivingIndex;

/*Received message Size*/
static u8 USART_u8ReceivedMessageSize;

Error_Status USART_Init(void)
{
	Error_Status Local_Error=OK;

	u8 Local_u8UCSRCValue=0;
	u16 Local_u16BaudRateValue;

#if 	USART_u8_DOUBLE_ASYNCHRONOUS_SPEED_ENABLE ==ENABLED
	SET_BIT(UCSRA,UCSRA_U2X);
#elif 	USART_u8_DOUBLE_ASYNCHRONOUS_SPEED_ENABLE==DISABLED
	CLR_BIT(UCSRA,UCSRA_U2X);
#else
	Local_Error=NOKAY;
#endif

#if USART_u8_RECEIVE_COMP_INT_ENABLE==ENABLED
	SET_BIT(UCSRB,UCSRB_RXCIE);
#elif USART_u8_RECEIVE_COMP_INT_ENABLE==DISABLED
	CLR_BIT(UCSRB,UCSRB_RXCIE);
#else
	Local_Error=NOKAY;
#endif

#if USART_u8_TRANSMIT_COMP_INT_ENABLE==ENABLED
	SET_BIT(UCSRB,UCSRB_TXCIE);
#elif USART_u8_TRANSMIT_COMP_INT_ENABLE==DISABLED
	CLR_BIT(UCSRB,UCSRB_TXCIE);
#else
	Local_Error=NOKAY;
#endif


#if USART_u8_DATA_REG_EMPTY_INT_ENABLE==ENABLED
	SET_BIT(UCSRB,UCSRB_UDRIE);
#elif USART_u8_DATA_REG_EMPTY_INT_ENABLE==DISABLED
	CLR_BIT(UCSRB,UCSRB_UDRIE);
#else
	Local_Error=NOKAY;
#endif

#if USART_u8_RECEIVER_ENABLE==ENABLED
	SET_BIT(UCSRB,UCSRB_RXEN);
#elif USART_u8_RECEIVER_ENABLE==DISABLED
	CLR_BIT(UCSRB,UCSRB_RXEN);
#else
	Local_Error=NOKAY;
#endif

#if USART_u8_TRANSMITTER_ENABLE==ENABLED
	SET_BIT(UCSRB,UCSRB_TXEN);
#elif USART_u8_TRANSMITTER_ENABLE==DISABLED
	CLR_BIT(UCSRB,UCSRB_TXEN);
#else
	Local_Error=NOKAY;
#endif

#if USART_u8_MODE_SELECT==SYNCHRONOUS
	SET_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
#elif USART_u8_MODE_SELECT==ASYNCHRONOUS
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UMSEL);
#else
	Local_Error=NOKAY;
#endif

#if USART_u8_PARITY_MODE == PARITY_DISABLED
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
#elif USART_u8_PARITY_MODE == EVEN_PARITY
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
#elif USART_u8_PARITY_MODE == ODD_PARITY
	SET_BIT(Local_u8UCSRCValue,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UPM1);
#else
	Local_Error=NOKAY;
#endif

#if USART_u8_STOP_BITS_NUMBER == ONE_STOP_BIT
	CLR_BIT(Local_u8UCSRCValue,UCSRC_USBS);
#elif USART_u8_STOP_BITS_NUMBER == TWO_STOP_BITS
	SET_BIT(Local_u8UCSRCValue,UCSRC_USBS);
#else
	Local_Error=NOKAY;
#endif

#if USART_u8_CHARACTER_SIZE==FIVE_BITS
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
#elif USART_u8_CHARACTER_SIZE==SIX_BITS
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
#elif USART_u8_CHARACTER_SIZE==SEVEN_BITS
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
#elif USART_u8_CHARACTER_SIZE==EIGHT_BITS
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCSZ1);
#else
	Local_Error=NOKAY;
#endif

#if USART_u8_CLOCK_POLARITY==TRANSMIT_ON_RISING_RECEIVE_ON_FALLING
	CLR_BIT(Local_u8UCSRCValue,UCSRC_UCPOL);
#elif USART_u8_CLOCK_POLARITY==TRANSMIT_ON_FALLING_RECEIVE_ON_RISING
	SET_BIT(Local_u8UCSRCValue,UCSRC_UCPOL);
#else
	Local_Error=NOKAY;
#endif

	/*Send the Value to the UCSRC Register*/
	SET_BIT(Local_u8UCSRCValue,UCSRC_URSEL);
	UCSRC=Local_u8UCSRCValue;

	/*Check on NORMAL ASYNCHRONOUS Mode*/
#if (USART_u8_MODE_SELECT==ASYNCHRONOUS) && (USART_u8_DOUBLE_ASYNCHRONOUS_SPEED_ENABLE==DISABLED)
	Local_u16BaudRateValue=((FCPU/(16*USART_BAUD_RATE))-1);
#elif (USART_u8_MODE_SELECT==ASYNCHRONOUS) && (USART_u8_DOUBLE_ASYNCHRONOUS_SPEED_ENABLE==ENABLED)
	Local_u16BaudRateValue=((FCPU/(8*USART_BAUD_RATE))-1);
#elif USART_u8_MODE_SELECT==SYNCHRONOUS
	Local_u16BaudRateValue=((FCPU/(2*USART_BAUD_RATE))-1);
#endif

	/*Set the baud rate registers*/
UBRRL=(u8)Local_u16BaudRateValue;
UBRRH=(u8)(Local_u16BaudRateValue>>8);

	return Local_Error;
}
u8 USART_u8ReceiveData(void)
{
	/*check on receive complete flag*/
	while((GET_BIT(UCSRA,UCSRA_RXC))==0);

	/*get the data*/
	return UDR;
}

void USART_voidSendData(u8 Copy_u8Data)
{
	/*Check on data register empty flag*/
	while((GET_BIT(UCSRA,UCSRA_UDRE))==0);

	/*send the data*/
	UDR=Copy_u8Data;
}


Error_Status USART_voidSendStringSynch(const char* Copy_pchString)
{
	Error_Status Local_Error=OK;
	if(Copy_pchString!=NULL)
	{
		while(*Copy_pchString != '\0')
		{
			USART_voidSendData(*Copy_pchString);
			Copy_pchString++;
		}
	}

	else
	{
		Local_Error=NULL_POINTER;
	}
	return Local_Error;
}

Error_Status USART_ReceiveStringSynch(u8* Copy_pu8String, u8 Copy_u8MessageSize)
{
	Error_Status Local_Error= OK;
	u8 Local_u8ArrayIndex;
	if (Copy_pu8String!=NULL)
	{
		for(Local_u8ArrayIndex=0;Local_u8ArrayIndex<Copy_u8MessageSize;Local_u8ArrayIndex++)
		{
			Copy_pu8String[Local_u8ArrayIndex]=USART_u8ReceiveData();
		}
	}
	else
	{
		Local_Error=NULL_POINTER;
	}

	return Local_Error;
}

Error_Status USART_SendStringAsynch(const char * Copy_pchString , void (*Copy_pfCallBack) (void))
{
	Error_Status Local_Error= OK;

	if((Copy_pchString !=NULL) && (Copy_pfCallBack!=NULL))
	{
		/*Transmitted string initialization*/
		USART_pchTransmisttedString=Copy_pchString;

		/*Callback initialization*/
		USART_pfTransmissionCallBack=Copy_pfCallBack;

		/*Array Index Initialization*/
		USART_u8TransmissionIndex=0;

		/*Enable UDRE Interrupt*/
		SET_BIT(UCSRB,UCSRB_UDRIE);
	}
	else
	{
		Local_Error=NULL_POINTER;
	}

	return Local_Error;
}


/*USART Data Register Empty ISR*/
void __vector_14 (void)
{
	if(USART_pchTransmisttedString[USART_u8TransmissionIndex]!='\0')
	{
		/*Send the current element*/
		UDR= USART_pchTransmisttedString[USART_u8TransmissionIndex];

		/*Index Increment*/
		USART_u8TransmissionIndex++;
	}

	else
	{
		/*Disable UDRE Interrupt*/
		CLR_BIT(UCSRB,UCSRB_UDRIE);

		/*Invoke the notification callback function*/
		USART_pfTransmissionCallBack();
	}
}

Error_Status USART_ReceiveStringAsynch(u8* Copy_pu8ReceivedMessage,u8 Copy_u8MessageSize,void (*Copy_pfCallBack)(void))
{
	Error_Status Local_Error= OK;
	if((Copy_pu8ReceivedMessage!=NULL )&& (Copy_pfCallBack !=NULL))
	{
		/*Initialize Received Array*/
		USART_pu8ReceivedMessgeArray=Copy_pu8ReceivedMessage;

		/*Message Size Initialization*/
		USART_u8ReceivedMessageSize=Copy_u8MessageSize;

		/*CallBack Function Initialization*/
		USART_pfReceivingCallBack=Copy_pfCallBack;

		/*Array Index Initialization*/
		USART_u8ReceivingIndex=0;

		/*Receiving Complete Interrupt Enable*/
		SET_BIT(UCSRB,UCSRB_RXCIE);
	}

	else
	{
		Local_Error=NULL_POINTER;
	}
	return Local_Error;

}

/*Receiving Complete ISR*/
void __vector_13 (void)
{
	/*Receive the current element*/
	USART_pu8ReceivedMessgeArray[USART_u8ReceivingIndex]=UDR;

	/*Increment the current Index*/
	USART_u8ReceivingIndex++;

	if(USART_u8ReceivingIndex==USART_u8ReceivedMessageSize)
	{
		/*Disable receive complete interrupt*/
		CLR_BIT(UCSRB,UCSRB_RXCIE);

		/*Invoke the receiving call back notification function*/
		USART_pfReceivingCallBack();
	}
	else
	{
		/*Do Nothing*/
	}
}
