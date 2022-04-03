
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DELAY.h"
#include "Keypad_interface.h"
#include "KeyPad_config.h"
#include "Keypad_private.h"

void KEYPAD_voidInit(void)
{
	u8 loc_counter,loc_counter2;
	/* Init Rows */
	for( loc_counter =0 ; loc_counter < KEYPAD_NB_ROWS ; loc_counter++)
	{
		/*Rows---> output*/
		DIO_EnuSetPinDirection(KRYPAD_ROWS_PORT[loc_counter],KRYPAD_ROWS_PIN[loc_counter],DIO_PIN_OUTPUT);
		/*set pins of row --> high*/
		DIO_EnuSetPinValue(KRYPAD_ROWS_PORT[loc_counter],KRYPAD_ROWS_PIN[loc_counter],DIO_PIN_HIGH);
	}
	/* Init cols */
	for( loc_counter2 =0 ; loc_counter2 < KEYPAD_NB_COLS ; loc_counter2 ++)
	{
		/*Cols---> input*/
		DIO_EnuSetPinDirection(KRYPAD_COLS_PORT[loc_counter2],KRYPAD_COLS_PIN[loc_counter2],DIO_PIN_INPUT);
		/*set pins of cols to be pull up*/
		DIO_EnuSetPinValue(KRYPAD_COLS_PORT[loc_counter2],KRYPAD_COLS_PIN[loc_counter2],DIO_PIN_HIGH);
	}

}

u8 KPD_u8GetPressedKey(void)
{
	s8 loc_pressed_key = 0 ;
	u8 loc_keyState ;

	for (u8 loc_row = 0 ; loc_row < KEYPAD_NB_ROWS ; loc_row++ )
	{
		/* Activate one row */
		DIO_EnuSetPinValue(KRYPAD_ROWS_PORT[loc_row] , KRYPAD_ROWS_PIN[loc_row] , DIO_PIN_LOW);

		/* Check on columns */
		for (u8 loc_col = 0 ; loc_col < KEYPAD_NB_COLS ; loc_col++ )
		{
			 DIO_EnuGetPinValue(KRYPAD_COLS_PORT[loc_col] ,KRYPAD_COLS_PIN[loc_col],&loc_keyState );
			/* Check on column */
			if (loc_keyState == 0)
			{
				loc_pressed_key = KEYPAD_SWITCH[loc_row][loc_col];
			}

			/* Wait to release the key */
			while (loc_keyState == 0)
			{
				 DIO_EnuGetPinValue(KRYPAD_COLS_PORT[loc_col] ,KRYPAD_COLS_PIN[loc_col],&loc_keyState );
			}

			/* Delay for debounce */
			Delay_ms(10);

		}

		/* Deactivate the row */
		DIO_EnuSetPinValue(KRYPAD_ROWS_PORT[loc_row] , KRYPAD_ROWS_PIN[loc_row] , DIO_PIN_HIGH);
	}
	return loc_pressed_key ;
}
