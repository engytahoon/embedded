#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY.h"
#include "RCC_interface.h"
#include "GPIO_INTERFACE.h"
#include "AFIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTIC_interface.h"

#include "IRREMOTE_interface.h"
#include "LEDMatrix_interface.h"

#include "LEM_IR.h"


u8 TextSize=25;
u8 engy[25]={127, 73, 73, 65, 0, 126, 2, 2, 126, 0, 110, 74, 126, 0, 110, 72, 72, 126, 0, 0, 0, 0, 0, 0, 0};
u8 Arr_Zeroes[8]={0};
u8 e[15]={0, 127, 73, 73, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
void LEMIR_voidInit(void)
{
	RCC_voidSysClkInit();
	RCC_voidEnableClock(RCC_GPIOA);
	RCC_voidEnableClock(RCC_GPIOB);
	/* init for RGB pins*/
	MGPIO_VidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP);

	IR_voidInit();
	HLEDMatrix_voidInit();
}
void LEMIR_voidApp(u8 Copy_u8Key)
{
	MGPIO_VidSetPinValue(GPIOA,PIN1,LOW);
	MGPIO_VidSetPinValue(GPIOA,PIN1,LOW);
	MGPIO_VidSetPinValue(GPIOA,PIN1,LOW);
	switch (Copy_u8Key)
	{
	case ON_OFF 		: LEMIR_voidPlay(engy); 	break;
	case STOP_CONT 		: LEMIR_voidStop();		break;
	case UP				: LEMIR_voidSpeedUp(engy);	break;
	case DOWN			: LEMIR_voidSpeedDown(engy);break;
	case ZERO			: MGPIO_VidSetPinValue(GPIOA,PIN1,HIGH);break;
	case ONE			: MGPIO_VidSetPinValue(GPIOA,PIN2,HIGH);break;
	case TWO			: MGPIO_VidSetPinValue(GPIOA,PIN3,HIGH);break;
	case THREE			: MGPIO_VidSetPinValue(GPIOA,PIN1,HIGH);
							MGPIO_VidSetPinValue(GPIOA,PIN2,HIGH);
							MGPIO_VidSetPinValue(GPIOA,PIN3,HIGH);break;
	default				: MGPIO_VidSetPinValue(GPIOA,PIN1,LOW);
							MGPIO_VidSetPinValue(GPIOA,PIN2,LOW);
							MGPIO_VidSetPinValue(GPIOA,PIN3,LOW);break;
	}
}
void LEMIR_voidPlay(u8* Copy_u8Data)
{
	HLEDMatrix_voidDisplayShifLeft(Copy_u8Data,40,TextSize);
}
void LEMIR_voidStop(void)
{
	HLEDMatrix_voidDisplay(e);
	Delay_ms(2500);
	//	HLEDMatrix_voidDisplay(Arr_Zeroes);
}
void LEMIR_voidSpeedUp(u8* Copy_u8Data)
{
	HLEDMatrix_voidDisplayShifLeft(Copy_u8Data,10,TextSize);
}

void LEMIR_voidSpeedDown(u8* Copy_u8Data)
{
	HLEDMatrix_voidDisplayShifLeft(Copy_u8Data,80,TextSize);
}
