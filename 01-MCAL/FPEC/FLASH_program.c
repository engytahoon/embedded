/********************************/
/* Author  : Engy Tahoon		*/
/*version  :  V02				*/
/*Date     : 8 OCT 2020			*/
/********************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "FLASH_interface.h"
#include "FLASH_private.h"
#include "FLASH_config.h"

/*.............................................................
 *Function Name: FLASH_State
 *Description  : Determine the state of the flash in that time
 *Arguments	   : no argument
 *Returns	   : return the state of the flash
 ..............................................................*/
 
u8 FLASH_State(void)
{
	u8 state=FLASH_COMPLETE;
	if(((FLASH->FLASH_SR.FourByteAcess) & (FLASH_FLAG_BSY)) !=0 )
	{
		state=FLASH_BUSY;
	}
	else
	{
		state= FLASH_COMPLETE;
	}
	return state;
}

/*.............................................................
 *Function Name: FLASH_WaitForLastOperation
 *Description  : wait for flash to complete the operation
 *Arguments	   : time of the operation 
 *Returns	   : return the state of the flash.
 ..............................................................*/
 
u8 FLASH_WaitForLastOperation(u32 TimeOut)
{
	u8 state=FLASH_COMPLETE;

	state=FLASH_State();
	while ((state==FLASH_BUSY)&& (TimeOut!=0))
	{
		state=FLASH_State();
		TimeOut--;
	}
	if (TimeOut==0)
	{
		state=FLASH_TIMEOUT;
	}
	return state;
}

/*.........................................................................
 *Function Name: FLASH_voidUnlock
 *Description  : unlock the flash before writing or erasing from the flash
 *Arguments	   : no argument
 *Returns	   : no return
 ..........................................................................*/
 
void FLASH_voidUnlock(void)
{
	if(FLASH->FLASH_CR.BitAcess.Bit7==1)		//bit 7 ->Lock
	{
		//perform unlock sequance
		FLASH->FLASH_KEYR.FourByteAcess=FLASH_KEY1;
		FLASH->FLASH_KEYR.FourByteAcess=FLASH_KEY2;
	}
}
/*.........................................................................
 *Function Name: FLASH_voidLock
 *Description  : Lock the flash.
 *Arguments	   : no argument
 *Returns	   : no return
 ..........................................................................*/
 
void FLASH_voidLock(void)
{
	SET_BIT(FLASH->FLASH_CR.FourByteAcess, 7)		//bit 7 ->Lock
}

/*.........................................................................
 *Function Name: FLASH_voidErase
 *Description  : erasing the flash
 *Arguments	   : Address of the place which we need to erase.
 *Returns	   : no return
 ..........................................................................*/
 
void FLASH_voidErase(u32 Address)
{
	u8 state;
		state= FLASH_WaitForLastOperation(EraseTimeout);
		if (state == FLASH_COMPLETE)
		{
			SET_BIT(FLASH->FLASH_CR.FourByteAcess , 1);		//bit 1 -> PER
			FLASH->FLASH_AR.FourByteAcess = Address;
			SET_BIT(FLASH->FLASH_CR.FourByteAcess , 6);		//bit 6 -> STRT

			state=FLASH_WaitForLastOperation(EraseTimeout);
				CLR_BIT(FLASH->FLASH_CR.FourByteAcess , 1);		//bit 1 -> PER
		}
}
/*.........................................................................
 *Function Name: FLASH_voidWriteHalfWord
 *Description  : Writing a half word(2 bytes) in Flash
 *Arguments	   : Address in flash to write the data into, 
				 data to be written in the flash 
 *Returns	   : no return
 ..........................................................................*/
 
void FLASH_voidWriteHalfWord(u32 Address, u16 Data)
{
	u8 state;
		state= FLASH_WaitForLastOperation(EraseTimeout);
		if (state == FLASH_COMPLETE)
		{
			SET_BIT(FLASH->FLASH_CR.FourByteAcess , 0);  // bit0 -> PG
			*(u16*) Address= Data;
			state= FLASH_WaitForLastOperation(ProgramTimeout);
				CLR_BIT(FLASH->FLASH_CR.FourByteAcess , 0);  // bit0 -> PG
		}
}
/*.........................................................................
 *Function Name: FLASH_voidWriteHalfWord
 *Description  : Writing a word(4 bytes) in Flash
 *Arguments	   : Address in flash to write the data into, 
				 data to be written in the flash 
 *Returns	   : no return
 ..........................................................................*/
 
void FLASH_voidWriteWord(u32 Address, u32 Data)
{
	u8 state;
		state= FLASH_WaitForLastOperation(EraseTimeout);
		if (state == FLASH_COMPLETE)
		{
			SET_BIT(FLASH->FLASH_CR.FourByteAcess , 0);  // bit0 -> PG
			*(u16*) Address= Data;
			state= FLASH_WaitForLastOperation(ProgramTimeout);
			if(state== FLASH_COMPLETE)
			{
				*(u16*) (Address+2) = (u16) (Data>>16);
			}
			state= FLASH_WaitForLastOperation(ProgramTimeout);
				CLR_BIT(FLASH->FLASH_CR.FourByteAcess , 0);  // bit0 -> PG
		}
}
