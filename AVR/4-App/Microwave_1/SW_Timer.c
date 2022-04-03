
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"
#include "DELAY.h"

#include "DIO_interface.h"

#include "lcd_inter.h"
#include "keybad_inter.h"
#include "motor.h"

#include "SW_Timer.h"

u8 Set_hours, Set_min, Set_sec;
u8 Remaining_hours=0, Remaining_min=0, Remaining_sec=0;
u8  Stop_Flag = 0;
u8 Clear_Time_Flag = 0;

/********************************************* Software Timer ****************************************************************/
void Microwave_SetTime(u8 input_hours, u8 input_min, u8 input_sec)
{
	Set_sec = input_sec;
	Set_min = input_min;
	Set_hours = input_hours;

	Remaining_hours = input_hours;
	Remaining_min = input_min;
	Remaining_sec = input_sec;
}

void Microwave_RemainingTime(void)
{
	if(Remaining_sec > 0)
	{
		Remaining_sec--;
	}
	else
	{
		if(Remaining_min > 0)		// 22:50:00
		{
			Remaining_sec = 59;
			Remaining_min--;		// 22:49:59
		}
		else
		{
			if(Remaining_hours > 0)	// 22:00:00
			{
				Remaining_min = 59;
				Remaining_sec = 59;
				Remaining_hours--;		// 21:59:59
			}
			else
			{
				//doing nothing
			}
		}
	}
}

void Microwave_ResetTime(void)
{
	Remaining_hours = 0;
	Remaining_min = 0;
	Remaining_sec =0;
}


u8 Microwave_CheckTimeFinish(void)
{
	if( ((Remaining_sec == 0) && (Remaining_min == 0)) && (Remaining_hours == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*********************************************************Request Time from Keypad ****************************************/
u8 TimeReq_Keypad(void)
{
	u8 Key, arr[10] ;
	do
	{
		Key = Keypad_u8Keypress(DIO_U8_PORT_C);
		Delay_ms(10);
	} while(!(Key >= '0') && (Key <= '9'));
	LCD_Num(Key-48);
	//	tostring(arr,Key-48);
	//	LCD_vidWriteString(arr);
	return Key ;
}
void Microwave_RequestTime(void)
{
	u8 HoursTen=0 , HoursUnit=0 , MinTen=0 , MinUnit=0 , SecTen=0 , SecUnit=0 ;
	u8 Hours=0 , Min =0 , Sec=0 ;
	/* To enter a new time we should clear the previous time */
	//	Microwave_Stop();
	Microwave_ResetTime();
	do
	{
		/* enter the time */
		LCD_enuSendCMD(LCD_CLEAR_SCREEN);
		LCD_vidWriteString("Timer Setting");
		LCD_voidGoToPosition(2 , 1);
		LCD_vidWriteString("HH:MM:SS");
		LCD_voidGoToPosition(2 , 1);
		LCD_vidWriteString("__:__:__");
		LCD_voidGoToPosition(2 , 1);

		HoursTen = TimeReq_Keypad()-48;
		HoursUnit = TimeReq_Keypad()-48;

		LCD_voidGoToPosition(2 , 4);

		MinTen = TimeReq_Keypad()-48;
		MinUnit = TimeReq_Keypad()-48;

		LCD_voidGoToPosition(2 , 7);

		SecTen = TimeReq_Keypad()-48;
		SecUnit = TimeReq_Keypad()-48;

		Hours = (HoursTen * 10) + HoursUnit ;
		Min = (MinTen * 10) + MinUnit ;
		Sec = (SecTen * 10) + SecUnit ;

	} while((Min > 59 ) || (Sec > 59) );

	Microwave_SetTime(Hours , Min , Sec);
}

/* Display the Remaining Time on LCD */
void Microwave_DisplayTime(void)
{
	//	Microwave_Start();
	LCD_voidGoToPosition(2 , 1);
	LCD_Num(Remaining_hours / 10);
	LCD_Num(Remaining_hours % 10);

	LCD_enuSendData(':');
	LCD_Num(Remaining_min / 10);
	LCD_Num(Remaining_min % 10);

	LCD_enuSendData(':');
	LCD_Num(Remaining_sec / 10);
	LCD_Num(Remaining_sec % 10);
}

void Microwave_CountingDown(void)
{
	u8 Timing=0 ;
	while((Timing == 0) && (Stop_Flag == 0))
	{
		Microwave_DisplayTime();
		Delay_ms(100);
		Microwave_RemainingTime();
		Delay_ms(100);
		Timing = Microwave_CheckTimeFinish();
	}
}


