#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

void TIMERS_voidTimer0Init(void);
void TIMERS_voidTimer1Init(void);
u8 TIMERS_u8TIMER0SetCallBack(void(*Copy_pf)(void));
u8 TIMERS_u8TIMER0CTCSetCallBack(void(*Copy_pf)(void));
void TIMERS_voidTIMER0SetCompareMatchValue(u8 Copy_u8OCR0Value);
void TIMERS_voidTIMER1SetCompareMatchValueA(u16 Copy_u8OCR1Value);

#endif
