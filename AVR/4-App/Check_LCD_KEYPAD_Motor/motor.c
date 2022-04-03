/*
 * motor.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: 3step
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "motor.h"

void DC_Motor_Init(void)
{
	DIO_EnuSetPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN1 , DIO_PIN_OUTPUT);
	DIO_EnuSetPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN2 , DIO_PIN_OUTPUT);

	DIO_EnuSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , DIO_PIN_LOW);
	DIO_EnuSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , DIO_PIN_LOW);

}

void DC_Motor_ForwardDir(void)
{
	DIO_EnuSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , DIO_PIN_HIGH);
	DIO_EnuSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , DIO_PIN_LOW);
}
void DC_Motor_BackwardDir(void)
{
	DIO_EnuSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , DIO_PIN_LOW);
	DIO_EnuSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , DIO_PIN_HIGH);
}
void DC_Motor_Stop(void)
{
	DIO_EnuSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , DIO_PIN_LOW);
	DIO_EnuSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , DIO_PIN_LOW);
}
