
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_INTERFACE.h"
#include "DELAY.h"
#include "LEDMatrix_interface.h"
#include "LEDMatrix_private.h"
#include "LEDMatrix_config.h"

u8 LEDMATRIX_ROW[16]={LEDMATRIX_ROW0,LEDMATRIX_ROW1,LEDMATRIX_ROW2,LEDMATRIX_ROW3,LEDMATRIX_ROW4,LEDMATRIX_ROW5,LEDMATRIX_ROW6,LEDMATRIX_ROW7};
u8 LEDMATRIX_COL[16]={LEDMATRIX_COL0,LEDMATRIX_COL1,LEDMATRIX_COL2,LEDMATRIX_COL3,LEDMATRIX_COL4,LEDMATRIX_COL5,LEDMATRIX_COL6,LEDMATRIX_COL7};

void HLEDMatrix_voidInit(void)
{
	u8 i=0;
	for(i=0;i<16;i+=2)
	{
		MGPIO_VidSetPinDirection(LEDMATRIX_ROW[i],LEDMATRIX_ROW[i+1],OUTPUT_SPEED_2MHZ_PP);
		MGPIO_VidSetPinDirection(LEDMATRIX_COL[i],LEDMATRIX_COL[i+1],OUTPUT_SPEED_2MHZ_PP);
	}
//	MGPIO_VidSetPinDirection(LEDMATRIX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);
//
//	MGPIO_VidSetPinDirection(LEDMATRIX_COL0_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_COL1_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_COL2_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_COL3_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_COL4_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_COL5_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_COL6_PIN,OUTPUT_SPEED_2MHZ_PP);
//	MGPIO_VidSetPinDirection(LEDMATRIX_COL7_PIN,OUTPUT_SPEED_2MHZ_PP);

}

void HLEDMatrix_voidDisplay(u8* Copy_u8Data)
{
	u8 i;
	for(i=0;i<16;i+=2)
	{
		DisableAllCOLs();
		SetRowValues(Copy_u8Data[i/2]);
		MGPIO_VidSetPinValue(LEDMATRIX_COL[i],LEDMATRIX_COL[i+1],LOW);;
		Delay_ms(2);
	}
	DisableAllCOLs();

}
void HLEDMatrix_voidDisplayShifLeft(u8* Copy_u8Data,u8 Copy_u8time, u8 Copy_u8TextSize)
{
	u8 cols,delay=0;
	for(cols=0 ; cols < Copy_u8TextSize-7 ; cols++)
	{
		u8 DataTemp[8]={Copy_u8Data[cols],Copy_u8Data[cols+1],Copy_u8Data[cols+2],Copy_u8Data[cols+3],Copy_u8Data[cols+4],Copy_u8Data[cols+5],Copy_u8Data[cols+6],Copy_u8Data[cols+7]};
		for(delay=0;delay<Copy_u8time;delay++)
		{
			HLEDMatrix_voidDisplay(DataTemp);
		}
	}
}

static void DisableAllCOLs(void)
{
	u8 i;
	for(i=0;i<16;i+=2)
	{
		MGPIO_VidSetPinValue(LEDMATRIX_COL[i],LEDMATRIX_COL[i+1],HIGH);
	}
}
static void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8Bit;
	u8 i;
	for(i=0;i<16;i+=2)
	{
		Local_u8Bit= GET_BIT(Copy_u8Value,i/2);
		MGPIO_VidSetPinValue(LEDMATRIX_ROW[i],LEDMATRIX_ROW[i+1],Local_u8Bit);
	}

//	Local_u8Bit= GET_BIT(Copy_u8Value,0);
//	MGPIO_VidSetPinValue(LEDMATRIX_ROW0,Local_u8Bit);
//
//	Local_u8Bit= GET_BIT(Copy_u8Value,1);
//	MGPIO_VidSetPinValue(LEDMATRIX_ROW1,Local_u8Bit);
//
//	Local_u8Bit= GET_BIT(Copy_u8Value,2);
//	MGPIO_VidSetPinValue(LEDMATRIX_ROW2,Local_u8Bit);
//
//	Local_u8Bit= GET_BIT(Copy_u8Value,3);
//	MGPIO_VidSetPinValue(LEDMATRIX_ROW3,Local_u8Bit);
//
//	Local_u8Bit= GET_BIT(Copy_u8Value,4);
//	MGPIO_VidSetPinValue(LEDMATRIX_ROW4,Local_u8Bit);
//
//	Local_u8Bit= GET_BIT(Copy_u8Value,5);
//	MGPIO_VidSetPinValue(LEDMATRIX_ROW5,Local_u8Bit);
//
//	Local_u8Bit= GET_BIT(Copy_u8Value,6);
//	MGPIO_VidSetPinValue(LEDMATRIX_ROW6,Local_u8Bit);
//
//	Local_u8Bit= GET_BIT(Copy_u8Value,7);
//	MGPIO_VidSetPinValue(LEDMATRIX_ROW7,Local_u8Bit);

}
