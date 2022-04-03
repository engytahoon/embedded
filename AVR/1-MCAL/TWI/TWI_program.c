#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_reg.h"

void TWI_voidInitMaster(void)
{
	/*Clock Initialization to 400kbps*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	TWBR=2;

	/*TWI Enable*/
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidInitSlave(u8 Copy_u8Address)
{
	/*Set the required Address*/
	TWAR=Copy_u8Address<<1;

	/*TWI Enable*/
	SET_BIT(TWCR,TWCR_TWEN);
}

Error_Status TWI_errSendStartCondition(void)
{
	Error_Status Local_Error=OK;

	/*Enable TWI , Send Start Condition , Clear Flag*/
	TWCR= (1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN);

	/*Polling on interrupt flag*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*check status*/
	if ((TWSR & 0xf8)!= START_ACK)
	{
		Local_Error=NOKAY;
	}

	return Local_Error;
}

Error_Status TWI_errSendRepeatedStart(void)
{
	Error_Status Local_Error=OK;

	/*Enable TWI , Send Start Condition , Clear Flag*/
	TWCR= (1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN);

	/*Polling on interrupt flag*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*check status*/
	if ((TWSR & 0xf8)!= REP_START_ACK)
	{
		Local_Error=NOKAY;
	}

	return Local_Error;
}

Error_Status TWI_errSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	Error_Status Local_Error=OK;

	/*Put the 7bit slave address plus write*/
	TWDR= Copy_u8SlaveAddress<<1;

	/*clear the start condition bit , clear the flag*/
	TWCR= (1<<TWCR_TWINT)| (1<<TWCR_TWEN);

	/*Polling on interrupt flag*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*check status*/
	if ((TWSR & 0xf8)!= SLAVE_ADD_AND_WR_ACK)
	{
		Local_Error=NOKAY;
	}
	return Local_Error;
}

Error_Status TWI_errSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	Error_Status Local_Error=OK;

	/*Put the 7bit slave address plus Read*/
	TWDR= (Copy_u8SlaveAddress<<1)|1;

	/*clear the start condition bit , clear the flag*/
	TWCR= (1<<TWCR_TWINT)| (1<<TWCR_TWEN);

	/*Polling on interrupt flag*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*check status*/
	if ((TWSR & 0xf8)!= SLAVE_ADD_AND_RD_ACK)
	{
		Local_Error=NOKAY;
	}
	return Local_Error;
}

Error_Status TWI_errMstrWriteDataByte(u8 Copy_u8Byte)
{
	Error_Status Local_Error=OK;

	/*put the data into the data register*/
	TWDR=Copy_u8Byte;

	/*Clear flag*/
	TWCR=(1<<TWCR_TWINT)|(1<<TWCR_TWEN);

	/*Polling on interrupt flag*/
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	/*check status*/
	if ((TWSR & 0xf8)!= MSTR_WR_BYTE_ACK)
	{
		Local_Error=NOKAY;
	}

	return Local_Error;
}

Error_Status TWI_errMstrReceiveDataByte(u8* Copy_pu8Byte)
{
	Error_Status Local_Error=OK;

	/*clear flag to assure clock working, Enable Acknowledge generation */
	TWCR=(1<<TWCR_TWEN)|(1<<TWCR_TWINT)|(1<<TWCR_TWEA);

	if(Copy_pu8Byte!=NULL)
	{
		/*Polling on interrupt flag*/
		while((GET_BIT(TWCR,TWCR_TWINT))==0);

		/*check status*/
		if ((TWSR & 0xf8)!= MSTR_RD_BYTE_WITH_ACK)
		{
			Local_Error=NOKAY;
		}
		else
		{
			/*read Data*/
			*Copy_pu8Byte=TWDR;
		}
	}
	else
	{
		Local_Error=NULL_POINTER;
	}

	return Local_Error;
}

void TWI_voidSendStopCondition(void)
{
	/*Enable stop condition , clear flag*/
	TWCR= (1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWSTO);
}
