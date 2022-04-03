#ifndef IRREMOTE_INTERFACE_H
#define IRREMOTE_INTERFACE_H

/* The Remote buttons */
#define ON_OFF		69
#define MODE		70
#define SILENT		71
#define STOP_CONT	68
#define LEFT		76
#define RIGHT		67
#define EQ			7
#define VOL_DOWN	21
#define VOL_UP		9
#define ZERO		22
#define RPT			25
#define U_SD		13
#define ONE			12
#define TWO			24
#define THREE		94
#define FOUR		8
#define FIVE		28
#define SIX			90
#define SIVEN		66
#define EIGHT		82
#define NINE		74


void IR_voidInit(void);
void IR_u8GetFrame(void);
void IR_voidGetCode(void);
u8 IR_u8GETButton(void);

#endif
