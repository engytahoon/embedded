/***********************************************************************************
Author : 	EnGy Tahoon
Date   :	29 June 2020
***********************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H


#define NULL   ((void *)0xffff) 

typedef unsigned char 		    u8	;
typedef unsigned short int 	    u16 ;
typedef unsigned long int 	    u32 ;

typedef signed char  			s8	;
typedef signed short int 	    s16	;
typedef signed long int		    s32	;
typedef float				    f32	;
typedef double 				    f64	;

/*8bit Register*/
typedef union
{
	struct{
		u8 BIT0:1;		//lw 3awza at3amel bit w7da bs
		u8 BIT1:1;
		u8 BIT2:1;
		u8 BIT3:1;
		u8 BIT4:1;
		u8 BIT5:1;
		u8 BIT6:1;
		u8 BIT7:1;
	}BitAccess;
	u8 ByteAccess;		// lw 3awza at3amel m3 el register kolo
	
}Register_8bit;

/*32bit Register*/
typedef union
{
	struct{
		u32 BIT0:1;		//lw 3awza a7gez bit w7da bs
		u32 BIT1:1;
		u32 BIT2:1;
		u32 BIT3:1;
		u32 BIT4:1;
		u32 BIT5:1;
		u32 BIT6:1;
		u32 BIT7:1;
		u32 BIT8:1;
		u32 BIT9:1;
		u32 BIT10:1;
		u32 BIT11:1;
		u32 BIT12:1;
		u32 BIT13:1;
		u32 BIT14:1;
		u32 BIT15:1;
		u32 BIT16:1;
		u32 BIT17:1;
		u32 BIT18:1;
		u32 BIT19:1;
		u32 BIT20:1;
		u32 BIT21:1;
		u32 BIT22:1;
		u32 BIT23:1;
		u32 BIT24:1;
		u32 BIT25:1;
		u32 BIT26:1;
		u32 BIT27:1;
		u32 BIT28:1;
		u32 BIT29:1;
		u32 BIT30:1;
		u32 BIT31:1;
		u32 BIT32:1;
	}BitAccess;
	
	u32 ByteAccess;
	
}Register_32bit;


typedef enum
{
	OK = 0,
	NOKAY= 4,
	OUTOFRANGE = 8,
	NULL_POINTER =16,   //wild pointer m4 be4awer 3la 7aga
}Error_Status;

#endif
