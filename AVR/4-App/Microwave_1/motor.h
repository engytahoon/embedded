
/*Driver for DC motor*/

#ifndef MOTOR_H_
#define MOTOR_H_

#define DC_MOTOR_PORT		DIO_U8_PORT_B
#define DC_MOTOR_PIN1		DIO_U8_PIN5
#define DC_MOTOR_PIN2		DIO_U8_PIN6


void DC_Motor_Init(void);
void DC_Motor_ForwardDir(void);
void DC_Motor_BackwardDir(void);
void DC_Motor_Stop(void);


#endif /* MOTOR_H_ */
