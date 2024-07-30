#include "../../MCAL/Timer/Timer_Interface.h"

#define TIMERS_u16_OCR1A_REG			*((volatile u16 *)0x4A)

void Servo_Init(){
	TIMERS_voidTimer1Init();
}

void Servo_SetAngle(u16 Servo_Angle){
	u16 Local_u16OCR1AValue = (Servo_Angle * 11) + 3005;
	TIMERS_voidTIMER1SetCompareMatchValueA(Local_u16OCR1AValue);
}
