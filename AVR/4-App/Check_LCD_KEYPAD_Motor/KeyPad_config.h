#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

/* private config */
#define  KEYPAD_NB_ROWS		4
#define  KEYPAD_NB_COLS		4

/* rows pins */
const u8 KRYPAD_ROWS_PORT[KEYPAD_NB_ROWS] = {DIO_PORTA,DIO_PORTA,DIO_PORTA,DIO_PORTA};
const u8 KRYPAD_ROWS_PIN[KEYPAD_NB_ROWS] = {DIO_PIN_0,DIO_PIN_1,DIO_PIN_2,DIO_PIN_3};

/* cols pins */
const u8 KRYPAD_COLS_PORT[KEYPAD_NB_COLS] = {DIO_PORTA,DIO_PORTA,DIO_PORTA,DIO_PORTA};
const u8 KRYPAD_COLS_PIN[KEYPAD_NB_COLS] = {DIO_PIN_4,DIO_PIN_5,DIO_PIN_6,DIO_PIN_7};


const u8 KEYPAD_SWITCH[KEYPAD_NB_ROWS][KEYPAD_NB_COLS] = {
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'.','0','=','+'}
};


#endif
