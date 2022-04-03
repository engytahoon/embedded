
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
#include<util/delay.h>
#include "DELAY.h"

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
#include "serves.h"

void EXTI0_DoorISR(void);
void EXTI1_StopISR(void);
extern u8 Stop_Flag ;

void Microwave_Option(void)
{
	lcd_gotox_y(0,1);
	LCD_vidWriteString("1-TIME");
	lcd_gotox_y(1,1);
	LCD_vidWriteString("*CLEAR");
	lcd_gotox_y(1,8);
	LCD_vidWriteString("=OK");

}

/******************************** on mode ****************************************************/
void Microwave_ON(void)
{
	u8 Time_Finish = 0;
	while(Stop_Flag == 0)
	{
		//Heater_ON
		Heater_ON();
		LCD_enuSendCMD(LCD_CLEAR_SCREEN);
		LCD_vidWriteString("Waiting");
		/* the motor is on, led on */
		DC_Motor_ForwardDir();
		DIO_enumSetPinValue(DIO_U8_PORT_B, DIO_U8_PIN7, DIO_U8_HIGH);
		/* show the time on LCD and counting down */
		Microwave_CountingDown();

		Time_Finish = Microwave_CheckTimeFinish();
		if(Time_Finish == 1)
		{
			Microwave_OFF();
		}

	}
}
/*********************************************** off mode ********************************************/
void Microwave_OFF(void)
{
	/* Motor off, led off */
	DC_Motor_Stop();
	DIO_enumSetPinValue(DIO_U8_PORT_B, DIO_U8_PIN7, DIO_U8_LOW);
	//heater off, buzzer on
	Heater_OFF();
	Buzzer_ON();
	LCD_enuSendCMD(LCD_CLEAR_SCREEN);
	//	Microwave_Stop();
	Microwave_ResetTime();
	LCD_vidWriteString("Food is Ready");
	Delay_ms(1000);
	Buzzerr_OFF();
}

/********************************************** Initializing func. ***********************************************/
void Init_Funs(void)
{
	/*Pins config*/
	DIO_enumSetPinDirection(DIO_U8_PORT_D, DIO_U8_PIN1, DIO_U8_INPUT);	//switch for Weight
	DIO_enumSetPinDirection(DIO_U8_PORT_B, DIO_U8_PIN7, DIO_U8_OUTPUT);	//pin for LED
	/* switchs for interrupt*/
	DIO_enumSetPinDirection(DIO_U8_PORT_D, DIO_U8_PIN2, DIO_U8_INPUT);	//switch for Door
	DIO_enumSetPinDirection(DIO_U8_PORT_D, DIO_U8_PIN3, DIO_U8_INPUT);	//switch for Stop

	/* LCD pins config*/
	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN0,DIO_U8_OUTPUT);
	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN1,DIO_U8_OUTPUT);
	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN4,DIO_U8_OUTPUT);
	DIO_enumSetPortDirection(DIO_U8_PORT_A,0xff);

	DIO_enumSetPinDirection(DIO_U8_PORT_B,DIO_U8_PIN3 , DIO_U8_OUTPUT); //OC0

	/**********************Timer_2 Init**********************/
	DIO_enumSetPinDirection(DIO_U8_PORT_D,DIO_U8_PIN7 , DIO_U8_OUTPUT); //OC2

	/* function init*/
	EXTI0_enumInit();		// for Door switch
	EXTI1_enumInit();		// for Stop switch

	LCD_enuInit();
	keypad_init(DIO_U8_PORT_C);
	DC_Motor_Init();

	LCD_enuSendCMD(0x01);
	lcd_gotox_y(0,1);
	LCD_vidWriteString("WELCOME");
	_delay_ms(100);
	LCD_enuSendCMD(0x01);
	lcd_gotox_y(0,1);
	LCD_vidWriteString("Choose Option");
	_delay_ms(100);
	LCD_enuSendCMD(0x01);
	Microwave_Option();

}

void Microwave_Reg(void)
{
	u8 key1;
	while(!key1)
	{
		key1=Keypad_u8Keypress(DIO_U8_PORT_C);
	}
	switch (key1)
	{
	case'1':
	{
		Microwave_ResetTime();
		Microwave_RequestTime();
		LCD_enuSendCMD(LCD_CLEAR_SCREEN);
		Microwave_Option();
		break;
	}
	case'*':
	{
		Microwave_ResetTime();
		Microwave_RequestTime();
		LCD_enuSendCMD(LCD_CLEAR_SCREEN);
		Microwave_Option();
		break;
	}
	case '=':
	{
		Simple_Mirowave();
		break;
	}
	}
}
/********************************************** Microwave Modes *************************************************/
void Simple_Mirowave(void)
{
	u8 state_Door=0, state_weight=0, state_Stop=0;
	u8 Time_Finish ;
	LCD_enuSendCMD(LCD_CLEAR_SCREEN);

	EXTI0_enumEnable();
	EXTI0_enumSetCallBack(EXTI0_DoorISR);

	EXTI1_enumEnable();
	EXTI1_enumSetCallBack(EXTI1_StopISR);

	state_Door = DIO_enumGetPinValue(DIO_U8_PORT_D, DIO_U8_PIN2);
	state_weight = DIO_enumGetPinValue(DIO_U8_PORT_D, DIO_U8_PIN1);
	state_Stop	= DIO_enumGetPinValue(DIO_U8_PORT_D, DIO_U8_PIN3);


	/******************************************** Microwave modes ****************************************************/
	Time_Finish = Microwave_CheckTimeFinish();
	if( (state_Door == 0) && (state_weight == 0) && (Time_Finish == 0) )
	{
		Microwave_ON();
	}

	else if((state_Door == 1) && (state_weight == 1) && (Time_Finish == 1))
	{
		Microwave_OFF();
	}
	else
	{
		// nothing
	}
}

/********************************************** ISR func. ****************************************/

void EXTI0_DoorISR(void)
{
	// if the door open before the microwave finish, this will cause the interrupt
	// motor off, led off
	DC_Motor_Stop();
	DIO_enumSetPinValue(DIO_U8_PORT_B, DIO_U8_PIN7, DIO_U8_LOW);
	// LCD will display "door is opened"
	LCD_enuSendCMD(LCD_CLEAR_SCREEN);
	LCD_vidWriteString("Door is opened");
	//buzzer on, heater off
	Buzzer_ON();
	Heater_OFF();

	Stop_Flag=1;
}

void EXTI1_StopISR(void)
{
	/* Motor off, led on */
	DC_Motor_Stop();
	DIO_enumSetPinValue(DIO_U8_PORT_B, DIO_U8_PIN7, DIO_U8_HIGH);
	//heater off
	Heater_OFF();
	// lcd will display the remaining time
	LCD_enuSendCMD(LCD_CLEAR_SCREEN);
	LCD_vidWriteString("STOP MODE");
	Stop_Flag=1;
	Microwave_DisplayTime();
}


