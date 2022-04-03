
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/******************************** EXTI0 func. *************************************/
ErrorStatus EXTI0_enumInit (void);
ErrorStatus EXTI0_enumEnable (void);
ErrorStatus EXTI0_enumDisable (void);
void EXTI0_enumSetCallBack (void(*x)(void));

/****************************** EXTI1 func. ***************************************/
ErrorStatus EXTI1_enumInit(void);
ErrorStatus EXTI1_enumEnable (void);
ErrorStatus EXTI1_enumDisable (void);
void EXTI1_enumSetCallBack (void(*x)(void));

/****************************** EXTI2 func. *****************************************/

ErrorStatus EXTI2_enumInit(void);
ErrorStatus EXTI2_enumEnable (void);
ErrorStatus EXTI2_enumDisable (void);
void EXTI2_enumSetCallBack (void(*x)(void));

#endif /* EXTI_INTERFACE_H_ */
