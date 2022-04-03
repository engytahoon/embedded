
#include "STD_types.h"
#include "BIT_MATH.h"
#include "ERROR_STATUS.h"

#include "DIO_interface.h"

#include "motor.h"

void DC_Motor_Init(void)
{
	DIO_enumSetPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN1 , DIO_U8_OUTPUT);
	DIO_enumSetPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN2 , DIO_U8_OUTPUT);

	DIO_enumSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , DIO_U8_LOW);
	DIO_enumSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , DIO_U8_LOW);

}

void DC_Motor_ForwardDir(void)
{
	DIO_enumSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , DIO_U8_HIGH);
	DIO_enumSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , DIO_U8_LOW);
}
void DC_Motor_BackwardDir(void)
{
	DIO_enumSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , DIO_U8_LOW);
	DIO_enumSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , DIO_U8_HIGH);
}
void DC_Motor_Stop(void)
{
	DIO_enumSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , DIO_U8_LOW);
	DIO_enumSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , DIO_U8_LOW);
}
