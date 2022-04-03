/********************************/
/*Author :  Engy Tahoon 		*/
/*version:  V02					*/
/*Date 	 :	24 Aug 2020			*/
/********************************/

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

typedef struct {
	
	volatile u32 AFIO_EVCR      ;
	volatile u32 AFIO_MAPR      ;
	volatile u32 AFIO_EXTICR[4] ;
	volatile u32 AFIO_MAPR2     ;
}AFIO_t;

#define AFIO 	((volatile AFIO_t*)0x40010000)


#endif
