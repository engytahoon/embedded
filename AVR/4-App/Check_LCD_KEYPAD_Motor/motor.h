/*
 * motor.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: 3step
 */

/*Driver for DC motor*/

#ifndef MOTOR_H_
#define MOTOR_H_

#define DC_MOTOR_PORT		DIO_PORTB
#define DC_MOTOR_PIN1		DIO_PIN_0
#define DC_MOTOR_PIN2		DIO_PIN_1


void DC_Motor_Init(void);
void DC_Motor_ForwardDir(void);
void DC_Motor_BackwardDir(void);
void DC_Motor_Stop(void);


#endif /* MOTOR_H_ */
