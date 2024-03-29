
#ifndef TIM2_confg_H_
#define TIM2_cong_H_
typedef enum{
	TIMER2_STOP=0,
	TIMER2_SCALER_1,
	TIMER2_SCALER_8,
	TIMER2_SCALER_32,
	TIMER2_SCALER_64,
	TIMER2_SCALER_256,
	TIMER2_SCALER_1024,

}Timer2Scaler_type;

typedef enum
{
	TIMER2_NORMAL_MODE=0,
	TIMER2_PHASECORRECT_MODE,
	TIMER2_CTC_MODE,
	TIMER2_FASTPWM_MODE

}Timer2Mode_type;
typedef enum
{
	OC2_DISCONNECTED=0,
	OC2_TOGGLE,
	OC2_NON_INVERTING,
	OC2_INVERTING

}OC2Mode_type;
typedef enum
{
	CS2O=0,
	CS21,
	CS22,
	WGM21,
	COM20,
	COM21,
	WGM20,
	FOC2
}TCCR2_BITS;

#define TOIE2 6
#define OCIE2 7



#endif /* TIM_CONFG_H_ */
