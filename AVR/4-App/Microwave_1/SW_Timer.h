
#ifndef SW_TIMER_H_
#define SW_TIMER_H_

/****************************************Software Timer ******************************************************/
void Microwave_SetTime(u8 input_hours, u8 input_min, u8 input_sec);
void Microwave_RemainingTime(void);
void Microwave_ResetTime(void);
u8 Microwave_CheckTimeFinish(void);

/****************************************Request Time from Keypad **********************************************/
u8 TimeReq_Keypad(void);
void Microwave_RequestTime(void);
void Microwave_DisplayTime(void);
void Microwave_CountingDown(void);

#endif /* SW_TIMER_H_ */
