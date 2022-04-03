#ifndef CLCD_CONFIG_H
#define CLCD_CONFIG_H

/* select mode
 * 1- EIGHT_BIT_MODE
 * 2- FOUR_BIT_MODE */
#define CLCD_MODE			EIGHT_BIT_MODE

/*control pins */
/* RS PIN */
#define CLCD_RS_PIN				DIO_PIN_0
#define CLCD_RS_PORT			DIO_PORTC
/* RW PIN */
#define CLCD_RW_PIN				DIO_PIN_1
#define CLCD_RW_PORT			DIO_PORTC
/* Enable PIN */
#define CLCD_E_PIN				DIO_PIN_2
#define CLCD_E_PORT				DIO_PORTC

/* Data Pins */
#define CLCD_D0_PIN				DIO_PIN_0
#define CLCD_D0_PORT			DIO_PORTD

#define CLCD_D1_PIN				DIO_PIN_1
#define CLCD_D1_PORT			DIO_PORTD

#define CLCD_D2_PIN				DIO_PIN_2
#define CLCD_D2_PORT			DIO_PORTD

#define CLCD_D3_PIN				DIO_PIN_3
#define CLCD_D3_PORT			DIO_PORTD

#define CLCD_D4_PIN				DIO_PIN_4
#define CLCD_D4_PORT			DIO_PORTD

#define CLCD_D5_PIN				DIO_PIN_5
#define CLCD_D5_PORT			DIO_PORTD

#define CLCD_D6_PIN				DIO_PIN_6
#define CLCD_D6_PORT			DIO_PORTD

#define CLCD_D7_PIN				DIO_PIN_7
#define CLCD_D7_PORT			DIO_PORTD


#define CLCD_DATA_PORT			DIO_PORTD




#endif
