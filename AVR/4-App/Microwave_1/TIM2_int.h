
#ifndef TIMER2_int_H_
#define TIMER2_int_H_




void Timer2_Init( Timer2Mode_type mode,Timer2Scaler_type scaler ,OC2Mode_type oc_mode);
void Timer2_OV_InterruptEnable(void);
void Timer2_OV_InterruptDisable(void);
void Timer2_OC_InterruptEnable(void);
void Timer2_OC_InterruptDisable(void);
void TIMER02_VCallback(void(*x)(void));

void Timer2_Disable(void);

#endif /* TIMER0_int_H_ */

