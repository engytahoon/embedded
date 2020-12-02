/********************************/
/* Author  : Engy Tahoon		*/
/*version  :  V02				*/
/*Date     : 8 OCT 2020			*/
/********************************/

#ifndef FLSINT_INTERFACE_H
#define FLSINT_INTERFACE_H


u8 	 FLASH_State(void);
u8 	 FLASH_WaitForLastOperation(u32 TimeOut);
void FLASH_voidUnlock(void);
void FLASH_voidLock(void);
void FLASH_voidErase(u32 Address);
void FLASH_voidWriteHalfWord(u32 Address, u16 Data);
void FLASH_voidWriteWord(u32 Address, u32 Data);



#endif
