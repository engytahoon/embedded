/********************************/
/* Author  : Engy Tahoon		*/
/*version  :  V02				*/
/*Date     : 8 OCT 2020			*/
/********************************/


#ifndef FLSINT_PRIVATE_H
#define FLSINT_PRIVATE_H

typedef struct
{
	volatile u32  FLASH_ACR ;
	volatile u32  FLASH_KEYR ;
	volatile u32  FLASH_OPTKEYR ;
	volatile u32  FLASH_SR ;
	volatile u32  FLASH_CR;
	volatile u32  FLASH_AR ;

}Flash_memory;
#define FLASH		((volatile Flash_memory*)0x40022000)
/*Key of flash*/
#define RDP_Key         ((u16)0x00A5)
#define FLASH_KEY1		((u32)0x45670123)
#define FLASH_KEY2		((u32)0xCDEF89AB)

#define FLASH_FLAG_BSY	      ((u32)0x00000001)
#define ProgramTimeout        ((u32)0x00002000)
#define EraseTimeout          ((u32)0x000B0000)

#define   FLASH_BUSY         0
#define   FLASH_COMPLETE     1
#define   FLASH_TIMEOUT      2

#define ok	1
#endif
