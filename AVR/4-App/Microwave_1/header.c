
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
#include<util/delay.h>

#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "TIM_REG.h"
#include "TIM_int.h"
#include "Timer0_confg.h"
/***********************TIM_2*****************/
#include "TIM2_REG.h"
#include "Tim2_confg.h"
#include "TIM2_int.h"

#include "lcd_inter.h"
#include "keybad_inter.h"
#include "motor.h"

#include "SW_Timer.h"
#include "header.h"

void Buzzer_ON(void)
{
	Timer2_Init( TIMER2_PHASECORRECT_MODE,TIMER2_SCALER_1 ,OC2_NON_INVERTING);
	OCR2=127;
}

void Buzzerr_OFF(void)
{
	Timer2_Disable();
	DIO_enumSetPinValue(DIO_U8_PORT_D, DIO_U8_PIN7, DIO_U8_LOW);
}

void Heater_OFF(void)
{
	Timer0_Disable();
	DIO_enumSetPinValue(DIO_U8_PORT_B,DIO_U8_PIN3 , DIO_U8_LOW);
}
void Heater_ON(void)
{
	u8 key_Level;
	LCD_enuSendCMD(LCD_CLEAR_SCREEN);
	LCD_voidGoToPosition(1,1);
	LCD_vidWriteString("2-POWER LEVEL");
	LCD_voidGoToPosition(2,1);
	LCD_vidWriteString("1LOW 2Med 3High");
	while(!key_Level)
	{
		key_Level=Keypad_u8Keypress(DIO_U8_PORT_C);
	}
	switch(key_Level)
	{
	case'1':
		//SELECT POWER LEVEL TO TURN ON THE HEATER
	{
		POWER_LOW();
		break;
	}
	case'2':
		//SELECT POWER LEVEL TO TURN ON THE HEATER
	{
		POWER_Meduim();
		break;
	}
	case'3':
		//SELECT POWER LEVEL TO TURN ON THE HEATER
	{
		POWER_High();
		break;
	}
	}
}
void POWER_LOW(void)
{
	Timer0_Init( TIMER0_FASTPWM_MODE,TIMER0_SCALER_1 ,OCO_NON_INVERTING);
	OCR0=50;
}
void POWER_Meduim(void)
{
	Timer0_Init( TIMER0_FASTPWM_MODE,TIMER0_SCALER_1 ,OCO_NON_INVERTING);
	OCR0=127;
}
void POWER_High(void)
{
	Timer0_Init( TIMER0_FASTPWM_MODE,TIMER0_SCALER_1 ,OCO_NON_INVERTING);
	OCR0=200;
}
