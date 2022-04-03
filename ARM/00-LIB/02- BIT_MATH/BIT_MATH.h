/********************************/
/*Author    :Engy				*/
/*version	:V01				*/
/*Date 		:31 Jan 2020		*/
/********************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define 	SET_BIT(REG, BIT_NUM)   		(REG |= (1<<BIT_NUM) )

#define		CLR_BIT(REG, BIT_NUM)    		(REG &= ~(1<<BIT_NUM))

#define		TGL_BIT(REG,BIT_NUM)			(REG ^=	(1<<BIT_NUM) )

#define		GET_BIT(REG,BIT_NUM)			((REG>>BIT_NUM) & 1  ) 

#define		ASSIGN_BIT(VAR,BIT,VAL)			VAR = (VAR &(~(1<<BIT))) | (VAL<<BIT)

#define ASSIGN_NIBBLE_VALUE(REG,PIN,VAL)	REG = ( (REG & (~(0xF << PIN*4))) | (VAL << PIN*4) )


#define CONC_8BIT(b0,b1,b2,b3,b4,b5,b6,b7) CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)
#define CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7) 0b##b7##b6##b5##b4##b3##b2##b1##b0




#endif